/*************************************************************************************
Copyright 2017, Nicola Di Mauro, Department of Computer Science, University of Bari

Permission is hereby granted, free of charge, to any person obtaining a copy of this
software and associated documentation files (the "Software"), to deal in the Software
without restriction, including without limitation the rights to use, copy, modify,
merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be included in all copies
or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*************************************************************************************/

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <map>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <cstdio>

#include "cltree.h"
#include "bernoulli.h"
#include "mix_bernoulli.h"
#include "dataset.h"
#include "nodes.h"
#include "cnet.h"
#include "params.h"
#include "utils.h"
#include "cmdline.h"
#include "globals.h"

std::mt19937 random_generator;

int
verbose;

std::string
log_outdir (std::string problem_name, std::string out_path)
{
  time_t rawtime;
  struct tm *timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer, 80, "%d-%m-%Y-%I-%M-%S", timeinfo);


  return ("./" + out_path + "/" + problem_name + "_" + std::string (buffer) + "/");
}

int
main (int argc, char **argv)
{
  params input_parameters;
  gengetopt_args_info args_info;

  /* let's call our cmdline parser */
  if (cmdline_parser (argc, argv, &args_info) != 0)
    exit (1);

  if (args_info.problem_given)
    input_parameters.problem_name = args_info.problem_arg;
  if (args_info.min_inst_given)
    for (unsigned int i = 0; i < args_info.min_inst_given; i++)
      input_parameters.min_instances.push_back (args_info.min_inst_arg[i]);
  else
    input_parameters.min_instances.push_back (args_info.min_inst_arg[0]);
  if (args_info.min_feat_given)
    for (unsigned int i = 0; i < args_info.min_feat_given; i++)
      input_parameters.min_features.push_back (args_info.min_feat_arg[i]);
  else
    input_parameters.min_features.push_back (args_info.min_feat_arg[0]);
  if (args_info.alpha_given)
    for (unsigned int i = 0; i < args_info.alpha_given; i++)
      input_parameters.alpha.push_back (args_info.alpha_arg[i]);
  else
    input_parameters.alpha.push_back (args_info.alpha_arg[0]);

  input_parameters.seed = args_info.seed_arg;
  input_parameters.out_path = args_info.output_dir_arg;
  input_parameters.model = args_info.model_arg;
  input_parameters.leaf_distribution = args_info.leaf_distribution_arg;
  input_parameters.max_components_bmix = args_info.kbm_arg;

  if (args_info.option_length_given)
    for (unsigned int i = 0; i < args_info.option_length_given; i++)
      input_parameters.option_length.push_back (args_info.option_length_arg[i]);
  else
    input_parameters.option_length.push_back (args_info.option_length_arg[0]);

  input_parameters.ensemble = args_info.ensemble_flag;
  input_parameters.max_components = args_info.k_arg;
  verbose = args_info.verbose_flag;

  // print options

  std::cout << input_parameters;


  // loading data

  dataset train_data ("./data/" + input_parameters.problem_name + ".ts.data");
  dataset valid_data ("./data/" + input_parameters.problem_name + ".valid.data");
  dataset test_data ("./data/" + input_parameters.problem_name + ".test.data");

  std::string output_dir_name = log_outdir (input_parameters.problem_name, input_parameters.out_path);
  std::string system_command = "mkdir -p " + output_dir_name;
  const int dir_err = std::system (system_command.c_str ());
  if (-1 == dir_err)
    {
      printf ("Error creating directory!n");
      exit (1);
    }

  std::ofstream output;
  output.open (output_dir_name + "exp.log", std::ofstream::out);

  std::cout << "Loaded " << train_data.shape[0] << " instances on " << train_data.shape[1] << " variables, sparsity: "
            << train_data.sparsity << std::endl;

  paramsexp pars;

  // grid search

  std::cout << "Starting grid search " << std::endl;
  std::cout.flush ();

  output << ";; " << input_parameters;
  output << ";; " << std::endl;
  output <<
    ";; min_instances, min_features, alpha, time_m, time_s, or_nodes_m, or_nodes_s, tree_nodes_m, tree_nodes_s, option_nodes_m, option_nodes_s,"
         <<
    "max_depth_m, max_depth_s, mean_depth_m, mean_depth_s, train_ll_m, train_ll_s, valid_ll_m, valid_ll_s, test_ll_m, test_ll_s"
         << std::endl;

  double best_valid_ll = -std::numeric_limits<double>::infinity();

  for (unsigned int mi = 0; mi < input_parameters.min_instances.size (); mi++)
    {
      for (unsigned int mf = 0; mf < input_parameters.min_features.size (); mf++)
        {
          for (unsigned int ma = 0; ma < input_parameters.alpha.size (); ma++)
            {

              random_generator.seed (input_parameters.seed);

              output << input_parameters.min_instances[mi] << "," <<
                input_parameters.min_features[mf] << "," << input_parameters.alpha[ma];


              pars.problem_name = input_parameters.problem_name;
              pars.min_instances = input_parameters.min_instances[mi];
              pars.min_features = input_parameters.min_features[mf];
              pars.alpha = input_parameters.alpha[ma];
              pars.out_path = input_parameters.out_path;
              pars.model = input_parameters.model;
              pars.option_length = input_parameters.option_length;
              pars.ensemble = input_parameters.ensemble;
              pars.max_components = input_parameters.max_components;

              std::cout << "  min_inst=" << pars.min_instances <<
                ", min_feat=" << pars.min_features << ", alpha=" << pars.alpha;
              std::cout.flush ();


              int max_iterations = 1;

              if (input_parameters.model == "xcnet" || input_parameters.model == "optionxcnet")
                max_iterations = 10;

              std::vector < double >time_accum;
              std::vector < int >or_nodes_accum;
              std::vector < int >tree_nodes_accum;
              std::vector < int >option_nodes_accum;
              std::vector < int >max_cnet_depth_accum;
              std::vector < double >mean_cnet_depth_accum;
              std::vector < double >train_ll_accum;
              std::vector < double >valid_ll_accum;
              std::vector < double >test_ll_accum;

	      
              for (int iter = 0; iter < max_iterations; iter++)
                {

                  std::shared_ptr < cnet < cltree > > M_cltree;
                  std::shared_ptr < cnet < bernoulli > > M_bernoulli;
                  std::shared_ptr < cnet < mix_bernoulli > > M_mix_bernoulli;

                  std::vector < double >train_lls;
                  std::vector < double >valid_lls;
                  std::vector < double >test_lls;

                  std::cout << "\n    iter:" << iter << " ";
                  auto t1 = std::chrono::high_resolution_clock::now ();

                  if (input_parameters.leaf_distribution == "cltree")
                    {

                      if (input_parameters.model == "cnet")
                        {
                          M_cltree = std::make_shared< cnet < cltree > >();
                          M_cltree->fit (train_data, pars);
                        }
                      if (input_parameters.model == "xcnet")
                        {
                          M_cltree = std::make_shared < xcnet < cltree > >();
                          M_cltree->fit (train_data, pars);
                        }
                      if (input_parameters.model == "optioncnet")
                        {
                          M_cltree = std::make_shared < optioncnet < cltree > >();
                          M_cltree->fit (train_data, pars);
                        }
                      if (input_parameters.model == "optionxcnet")
                        {
                          M_cltree = std::make_shared < optionxcnet < cltree > >();
                          M_cltree->fit (train_data, pars);
                        }
                    }
                  else
                    if (input_parameters.leaf_distribution == "bernoulli")
                      {

                        if (input_parameters.model == "cnet")
                          {
                            M_bernoulli = std::make_shared < cnet < bernoulli > >();
                            M_bernoulli->fit (train_data, pars);
                          }
                        if (input_parameters.model == "xcnet")
                          {
                            M_bernoulli = std::make_shared < xcnet < bernoulli > >();
                            M_bernoulli->fit (train_data, pars);
                          }
                        if (input_parameters.model == "optioncnet")
                          {
                            M_bernoulli = std::make_shared < optioncnet < bernoulli > >();
                            M_bernoulli->fit (train_data, pars);
                          }
                        if (input_parameters.model == "optionxcnet")
                          {
                            M_bernoulli = std::make_shared < optionxcnet < bernoulli > >();
                            M_bernoulli->fit (train_data, pars);
                          }
                      }
                    else
                      if (input_parameters.leaf_distribution == "mix-bernoulli")
                        {

                          if (input_parameters.model == "cnet")
                            {
                              M_mix_bernoulli = std::make_shared < cnet < mix_bernoulli > >
                                (input_parameters.max_components_bmix);
                              M_mix_bernoulli->fit (train_data, pars);
                            }
                          if (input_parameters.model == "xcnet")
                            {
                              M_mix_bernoulli = std::make_shared < xcnet < mix_bernoulli > >
                                (input_parameters.max_components_bmix);
                              M_mix_bernoulli->fit (train_data, pars);
                            }
                          if (input_parameters.model == "optioncnet")
                            {
                              M_mix_bernoulli = std::make_shared < optioncnet < mix_bernoulli > >
                                (input_parameters.max_components_bmix);
                              M_mix_bernoulli->fit (train_data, pars);
                            }
                          if (input_parameters.model == "optionxcnet")
                            {
                              M_mix_bernoulli = std::make_shared < optionxcnet < mix_bernoulli > >
                                (input_parameters.max_components_bmix);
                              M_mix_bernoulli->fit (train_data, pars);
                            }
                        }

                  auto t2 = std::chrono::high_resolution_clock::now ();


                  //C->is_pdf();
                  if (input_parameters.leaf_distribution == "cltree")
                    {
                      train_lls = M_cltree->eval(train_data);
                      valid_lls = M_cltree->eval(valid_data);
                      test_lls = M_cltree->eval(test_data);
                      M_cltree->compute_stats ();

                      std::cout << " [Net stats -- or:" << M_cltree->_n_or_nodes << ", tr:" <<
                        M_cltree->_n_tree_nodes << ", op:" << M_cltree->_n_option_nodes << ", maxd:" <<
                        M_cltree->_max_depth << ", meand:" << M_cltree->_mean_depth << "]";
                      or_nodes_accum.push_back (M_cltree->_n_or_nodes);
                      tree_nodes_accum.push_back (M_cltree->_n_tree_nodes);
                      option_nodes_accum.push_back (M_cltree->_n_option_nodes);
                      max_cnet_depth_accum.push_back (M_cltree->_max_depth);
                      mean_cnet_depth_accum.push_back (M_cltree->_mean_depth);
                    }
                  else if (input_parameters.leaf_distribution == "bernoulli")
                    {
                      train_lls = M_bernoulli->eval (train_data);
                      valid_lls = M_bernoulli->eval(valid_data);
                      test_lls = M_bernoulli->eval(test_data);
                      M_bernoulli->compute_stats ();

                      std::cout << " [Net stats -- or:" << M_bernoulli->_n_or_nodes << ", tr:" <<
                        M_bernoulli->_n_tree_nodes << ", op:" << M_bernoulli->_n_option_nodes << ", maxd:" <<
                        M_bernoulli->_max_depth << ", meand:" << M_bernoulli->_mean_depth << "]";
                      or_nodes_accum.push_back (M_bernoulli->_n_or_nodes);
                      tree_nodes_accum.push_back (M_bernoulli->_n_tree_nodes);
                      option_nodes_accum.push_back (M_bernoulli->_n_option_nodes);
                      max_cnet_depth_accum.push_back (M_bernoulli->_max_depth);
                      mean_cnet_depth_accum.push_back (M_bernoulli->_mean_depth);
                    }
                  else if (input_parameters.leaf_distribution == "mix-bernoulli")
                    {
                      train_lls = M_mix_bernoulli->eval (train_data);
                      valid_lls = M_mix_bernoulli->eval(valid_data);
                      test_lls = M_mix_bernoulli->eval(test_data);
                      M_mix_bernoulli->compute_stats ();

                      std::cout << " [Net stats -- or:" << M_mix_bernoulli->_n_or_nodes << ", tr:" <<
                        M_mix_bernoulli->_n_tree_nodes << ", op:" << M_mix_bernoulli->_n_option_nodes << ", maxd:" <<
                        M_mix_bernoulli->_max_depth << ", meand:" << M_mix_bernoulli->_mean_depth << "]";
                      or_nodes_accum.push_back (M_mix_bernoulli->_n_or_nodes);
                      tree_nodes_accum.push_back (M_mix_bernoulli->_n_tree_nodes);
                      option_nodes_accum.push_back (M_mix_bernoulli->_n_option_nodes);
                      max_cnet_depth_accum.push_back (M_mix_bernoulli->_max_depth);
                      mean_cnet_depth_accum.push_back (M_mix_bernoulli->_mean_depth);
                    }
                  double train_ll = mean (train_lls);
                  double valid_ll = mean (valid_lls);
                  double test_ll = mean (test_lls);

		  std::ofstream output_ll;
		  output_ll.open (output_dir_name + "lls_iter" + std::to_string(iter), std::ofstream::out);
		  for (int s=0; s < test_lls.size(); s++)
		    output_ll << test_lls[s] << std::endl;
		  output_ll.close();
		  
                  train_ll_accum.push_back (train_ll);
                  valid_ll_accum.push_back (valid_ll);
                  test_ll_accum.push_back (test_ll);

                  std::cout << ", time:"
                            << (double) std::chrono::duration_cast <
                                 std::chrono::milliseconds > (t2 - t1).count () / 1000 << " s";

                  std::cout << ", trainLL:" << train_ll << ", validLL:" << valid_ll << ", testLL:" << test_ll;

                  time_accum.push_back ((double) std::chrono::duration_cast <
                                        std::chrono::milliseconds > (t2 - t1).count () / 1000);
                }
              std::cout << std::endl;

              double meanTime = mean (time_accum);
              output << "," << meanTime << "," << stdev (time_accum, meanTime);
              double meanOr = mean (or_nodes_accum);
              output << "," << meanOr << "," << stdev (or_nodes_accum, meanOr);
              double meanTree = mean (tree_nodes_accum);
              output << "," << meanTree << "," << stdev (tree_nodes_accum, meanTree);
              double meanOption = mean (option_nodes_accum);
              output << "," << meanOption << "," << stdev (option_nodes_accum, meanOption);
              double meanMaxDepth = mean (max_cnet_depth_accum);
              output << "," << meanMaxDepth << "," << stdev (max_cnet_depth_accum, meanMaxDepth);
              double meanMeanDepth = mean (mean_cnet_depth_accum);
              output << "," << meanMeanDepth << "," << stdev (mean_cnet_depth_accum, meanMeanDepth);

              double meanTrainLL = mean (train_ll_accum);
              output << "," << meanTrainLL << "," << stdev (train_ll_accum, meanTrainLL);
              double meanValidLL = mean (valid_ll_accum);
              output << "," << meanValidLL << "," << stdev (valid_ll_accum, meanValidLL);
              double meanTestLL = mean (test_ll_accum);
              output << "," << meanTestLL << "," << stdev (test_ll_accum, meanTestLL);
              output << std::endl;


	      if (meanValidLL > best_valid_ll)
		{
		  best_valid_ll = meanValidLL;
		  for (int iter = 0; iter < max_iterations; iter++)
		    {
		      std::string old_name = output_dir_name + "lls_iter" + std::to_string(iter);
		      std::string new_name = output_dir_name + "best_lls_iter" + std::to_string(iter);
		      std::rename(old_name.c_str(), new_name.c_str());
		    }
		}
	      else
		{
		  for (int iter = 0; iter < max_iterations; iter++)
		    {
		      std::string filename = output_dir_name + "lls_iter" + std::to_string(iter);
		      std::remove(filename.c_str());
		    }
		}
            }
        }
    }

  output.close ();
}
