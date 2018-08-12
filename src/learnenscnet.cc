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
#include <limits>
#include <cstdio>

#include "cltree.h"
#include "bernoulli.h"
#include "mix_bernoulli.h"
#include "dataset.h"
#include "nodes.h"
#include "cnet.h"
#include "params.h"
#include "enscnet.h"
#include "globals.h"
#include "cmdline.h"
#include "utils.h"

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
      printf ("Error creating directory!\n");
      exit (1);
    }

  std::ofstream output;
  output.open (output_dir_name + "exp.log");

  std::cout << "Loaded " << train_data.shape[0] << " instances on " << train_data.shape[1] << " variables, sparsity: "
            << train_data.sparsity << std::endl;

  paramsexp pars;

  // grid search

  std::cout << "Starting grid search " << std::endl;
  std::cout.flush ();

  output << ";; " << input_parameters;
  output << ";; " << std::endl;
  output <<
    ";; components, min_instances, min_features, alpha, learn_time, eval_time," <<
    " train_ll, valid_ll, test_ll" << std::endl;

  double best_valid_ll = -std::numeric_limits<double>::infinity();
  
  for (unsigned int mi = 0; mi < input_parameters.min_instances.size (); mi++)
    {
      for (unsigned int mf = 0; mf < input_parameters.min_features.size (); mf++)
        {
          for (unsigned int ma = 0; ma < input_parameters.alpha.size (); ma++)
            {

              random_generator.seed (input_parameters.seed);

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


              double learn_time = 0;
              double eval_time = 0;

              std::shared_ptr < ensemble > C;

              if (input_parameters.leaf_distribution == "cltree")
                {
                  if (input_parameters.model == "cnet")
                    C = std::make_shared < enscnet < cnet < cltree >>>
                      (input_parameters.max_components, true, input_parameters.max_components_bmix);
                  if (input_parameters.model == "xcnet")
                    C = std::make_shared < enscnet < xcnet < cltree >>>
                      (input_parameters.max_components, false, input_parameters.max_components_bmix);
                  if (input_parameters.model == "optioncnet")
                    C = std::make_shared < enscnet < optioncnet < cltree >>>
                      (input_parameters.max_components, true, input_parameters.max_components_bmix);
                  if (input_parameters.model == "optionxcnet")
                    C = std::make_shared < enscnet < optionxcnet < cltree >>>
                      (input_parameters.max_components, false, input_parameters.max_components_bmix);
                }
              else
                if (input_parameters.leaf_distribution == "bernoulli")
                  {
                    if (input_parameters.model == "cnet")
                      C = std::make_shared < enscnet < cnet < bernoulli >>>
                        (input_parameters.max_components, true, input_parameters.max_components_bmix);
                    if (input_parameters.model == "xcnet")
                      C = std::make_shared < enscnet < xcnet < bernoulli >>>
                        (input_parameters.max_components, false, input_parameters.max_components_bmix);
                    if (input_parameters.model == "optioncnet")
                      C = std::make_shared < enscnet < optioncnet < bernoulli >>>
                        (input_parameters.max_components, true, input_parameters.max_components_bmix);
                    if (input_parameters.model == "optionxcnet")
                      C = std::make_shared < enscnet < optionxcnet < bernoulli >>>
                        (input_parameters.max_components, false, input_parameters.max_components_bmix);
                  }
                else
                  if (input_parameters.leaf_distribution == "mix-bernoulli")
                    {
                      if (input_parameters.model == "cnet")
                        C = std::make_shared < enscnet < cnet < mix_bernoulli >>>
                          (input_parameters.max_components, true, input_parameters.max_components_bmix);
                      if (input_parameters.model == "xcnet")
                        C = std::make_shared < enscnet < xcnet < mix_bernoulli >>>
                          (input_parameters.max_components, false, input_parameters.max_components_bmix);
                      if (input_parameters.model == "optioncnet")
                        C = std::make_shared < enscnet < optioncnet < mix_bernoulli >>>
                          (input_parameters.max_components, true, input_parameters.max_components_bmix);
                      if (input_parameters.model == "optionxcnet")
                        C = std::make_shared < enscnet < optionxcnet < mix_bernoulli >>>
                          (input_parameters.max_components, false, input_parameters.max_components_bmix);
                    }

              auto t1 = std::chrono::high_resolution_clock::now ();
              C->fit (train_data, pars);
              auto t2 = std::chrono::high_resolution_clock::now ();
              //              C->is_pdf(55);

              std::vector < double >max_train_ll;
              std::vector < double >max_valid_ll;
              std::vector < double >max_test_ll;

              learn_time = (double) std::chrono::duration_cast < std::chrono::milliseconds > (t2 - t1).count () / 1000;

              std::vector < double >global_train_lls;
              global_train_lls.resize (train_data.shape[0], 0.0);
              std::vector < double >global_valid_lls;
              global_valid_lls.resize (valid_data.shape[0], 0.0);
              std::vector < double >global_test_lls;
              global_test_lls.resize (test_data.shape[0], 0.0);

              for (unsigned nc = 0; nc < input_parameters.max_components; nc++)
                {

                  auto te1 = std::chrono::high_resolution_clock::now ();
                  std::vector < double >c_ll = C->eval (train_data, nc);
                  // setting the max for the log sum exp trick to the first component value

                  if (nc == 0)
                    max_train_ll = c_ll;
                  double train_local_ll = 0;
                  for (unsigned inst = 0; inst < train_data.shape[0]; inst++)
                    {
                      if (c_ll[inst] > max_train_ll[inst])
                        {
                          global_train_lls[inst] = global_train_lls[inst] * exp(max_train_ll[inst] - c_ll[inst]);
                          max_train_ll[inst] = c_ll[inst];
                        }
                      global_train_lls[inst] += exp (c_ll[inst] - max_train_ll[inst]);
                      train_local_ll += max_train_ll[inst] - log ((double) nc + 1) + log (global_train_lls[inst]);
                    }
                  train_local_ll /= train_data.shape[0];


                  auto te2 = std::chrono::high_resolution_clock::now ();
                  eval_time += (double) std::chrono::duration_cast < std::chrono::milliseconds >
                    (te2 - te1).count () / 1000;

                  c_ll = C->eval (valid_data, nc);
                  if (nc == 0)
                    max_valid_ll = c_ll;
                  double valid_local_ll = 0;
                  for (unsigned inst = 0; inst < valid_data.shape[0]; inst++)
                    {
                      if (c_ll[inst] > max_valid_ll[inst])
                        {
                          global_valid_lls[inst] = global_valid_lls[inst] * exp(max_valid_ll[inst] - c_ll[inst]);
                          max_valid_ll[inst] = c_ll[inst];
                        }
                      global_valid_lls[inst] += exp (c_ll[inst] - max_valid_ll[inst]);
                      valid_local_ll += max_valid_ll[inst] - log ((double) nc + 1) + log (global_valid_lls[inst]);
                    }
                  valid_local_ll /= valid_data.shape[0];

                  c_ll = C->eval (test_data, nc);
                  if (nc == 0)
                    max_test_ll = c_ll;
                  double test_local_ll = 0;
                  for (unsigned inst = 0; inst < test_data.shape[0]; inst++)
                    {
                      if (c_ll[inst] > max_test_ll[inst])
                        {
                          global_test_lls[inst] = global_test_lls[inst] * exp(max_test_ll[inst] - c_ll[inst]);
                          max_test_ll[inst] = c_ll[inst];
                        }
                      global_test_lls[inst] += exp (c_ll[inst] - max_test_ll[inst]);
                      test_local_ll += max_test_ll[inst] - log ((double) nc + 1) + log (global_test_lls[inst]);
                    }
                  test_local_ll /= test_data.shape[0];

                  output << nc + 1 << ","
                         << input_parameters.min_instances[mi] << ","
                         << input_parameters.min_features[mf] << "," << input_parameters.alpha[ma];

                  output << "," << learn_time << "," << eval_time;
                  output << "," << train_local_ll;
                  output << "," << valid_local_ll;
                  output << "," << test_local_ll;
                  output << std::endl;

                  if (nc == input_parameters.max_components - 1)
                    {
                      std::cout << ", learn time: " << learn_time << ", eval time: " << eval_time;
                      std::cout << ", train ll: " << train_local_ll;
                      std::cout << ", valid ll: " << valid_local_ll;
                      std::cout << ", test ll: " << test_local_ll;

		      if (valid_local_ll > best_valid_ll)
			{
			  best_valid_ll = valid_local_ll;
			  std::ofstream output_ll;
			  output_ll.open (output_dir_name + "best_lls", std::ofstream::out);
			  for (int s=0; s < global_test_lls.size(); s++)
			    output_ll << max_test_ll[s] - log ((double) input_parameters.max_components) + log (global_test_lls[s]) << std::endl;
			  output_ll.close();
			}
                    }
                }
              std::cout << std::endl;
            }
        }
    }
  output.close ();
  return 0;
}
