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

#include "cltree.h"
#include "dataset.h"
#include "nodes.h"
#include "cnet.h"
#include "params.h"
#include "enscnet.h"
#include "globals.h"
#include "cmdline.h"
#include "utils.h"

std::mt19937
random_generator;

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


  return ("./" + out_path + "/" + problem_name + "_" + std::string (buffer) +
          "/");
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

  if (args_info.option_length_given)
    for (unsigned int i = 0; i < args_info.option_length_given; i++)
      input_parameters.option_length.push_back (args_info.
                                                option_length_arg[i]);
  else
    input_parameters.option_length.push_back (args_info.option_length_arg[0]);

  input_parameters.ensemble = args_info.ensemble_flag;
  input_parameters.max_components = args_info.k_arg;
  verbose = args_info.verbose_flag;

  // print options

  std::cout << input_parameters;

  random_generator.seed (input_parameters.seed);


  // loading data

  dataset train_data ("./data/" + input_parameters.problem_name + ".ts.data");
  dataset valid_data ("./data/" + input_parameters.problem_name +
                      ".valid.data");
  dataset test_data ("./data/" + input_parameters.problem_name +
                     ".test.data");

  std::string output_dir_name =
    log_outdir (input_parameters.problem_name, input_parameters.out_path);
  std::string system_command = "mkdir -p " + output_dir_name;
  const int dir_err = std::system (system_command.c_str ());
  if (-1 == dir_err)
    {
      printf ("Error creating directory!n");
      exit (1);
    }

  std::ofstream output;
  output.open (output_dir_name + "exp.log");

  std::cout << "Loaded " << train_data.
    shape[0] << " instances on " << train_data.
    shape[1] << " variables, sparsity: " << train_data.sparsity << std::endl;

  paramsexp pars;

  // grid search

  random_generator.seed (input_parameters.seed);

  std::cout << "Starting grid search " << std::endl;
  std::cout.flush ();

  output << ";; " << input_parameters;
  output << ";; " << std::endl;
  output <<
    ";; components, min_instances, min_features, alpha, learn_time_m, learn_time_s, eval_time_m, eval_time_s," <<
    " train_ll_m, train_ll_s, valid_ll_m, valid_ll_s, test_ll_m, test_ll_s" << std::endl;

  for (unsigned int mi = 0; mi < input_parameters.min_instances.size (); mi++)
    {
      for (unsigned int mf = 0; mf < input_parameters.min_features.size (); mf++)
        {
          for (unsigned int ma = 0; ma < input_parameters.alpha.size (); ma++)
            {

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
                ", min_feat=" << pars.min_features <<
                ", alpha=" << pars.alpha;
              std::cout.flush ();


              int max_iterations = 1;

              if (input_parameters.model == "xcnet"
                  || input_parameters.model == "optionxcnet")
                max_iterations = 10;

              max_iterations = 1;

              double learn_time = 0;
              double eval_time = 0;
              double train_ll;
              double valid_ll;
              double test_ll;

              for (int iter = 0; iter < max_iterations; iter++)
                {
                  std::shared_ptr < ensemble > C;

                  std::cout << "\n    iter:" << iter << " ";

                  if (input_parameters.model == "cnet")
                    C = std::make_shared < enscnet < cnet >>(input_parameters.max_components);
                  if (input_parameters.model == "xcnet")
                    C = std::make_shared < enscnet < xcnet > >(input_parameters.max_components);
                  if (input_parameters.model == "optioncnet")
                    C = std::make_shared < enscnet < optioncnet > >(input_parameters.max_components);
                  if (input_parameters.model == "optionxcnet")
                    C = std::make_shared < enscnet < optionxcnet > >(input_parameters.max_components);

                  auto t1 = std::chrono::high_resolution_clock::now ();
                  C->fit (train_data, pars);
                  auto t2 = std::chrono::high_resolution_clock::now ();

                  std::vector < std::vector < double >>train_lls;
                  std::vector < std::vector < double >>valid_lls;
                  std::vector < std::vector < double >>test_lls;

                  learn_time = (double) std::chrono::duration_cast < std::chrono::milliseconds >
                    (t2 - t1).count () / 1000;
 
                  /* no serialization 
                  for (unsigned mdls=0; mdls<input_parameters.max_components; mdls++)
                    {
                      if ((mdls % 10 == 0) | mdls == input_parameters.max_components -1)
                        {
                          serialize(train_lls[mdls], output_dir_name + "trainll_" + std::to_string(mdls));
                          serialize(valid_lls[mdls], output_dir_name + "validll_" + std::to_string(mdls));
                          serialize(test_lls[mdls], output_dir_name + "testll_" + std::to_string(mdls));
                        }
                    }
                  */

                  std::vector<double> global_train_lls;
                  global_train_lls.resize (train_data.shape[0], 0.0);
                  std::vector<double> global_valid_lls;
                  global_valid_lls.resize (valid_data.shape[0], 0.0);
                  std::vector<double> global_test_lls;
                  global_test_lls.resize (test_data.shape[0], 0.0);

                  for (unsigned nc = 0; nc < input_parameters.max_components; nc++)
                    {

                      auto te1 = std::chrono::high_resolution_clock::now ();
                      std::vector<double> c_ll = C->eval(train_data,nc);
                      double train_local_ll = 0;
                      for (unsigned inst = 0; inst<train_data.shape[0]; inst++)
                        {
                          global_train_lls[inst] += exp(c_ll[inst]);
                          train_local_ll += log(global_train_lls[inst] / (nc + 1));
                        }
                      train_local_ll /= train_data.shape[0];
                      auto te2 = std::chrono::high_resolution_clock::now ();
                      eval_time += (double) std::chrono::duration_cast < std::chrono::milliseconds >
                        (te2 - te1).count () / 1000;

                      c_ll = C->eval(valid_data,nc);
                      double valid_local_ll = 0;
                      for (unsigned inst = 0; inst<valid_data.shape[0]; inst++)
                        {
                          global_valid_lls[inst] += exp(c_ll[inst]);
                          valid_local_ll += log(global_valid_lls[inst] / (nc + 1));
                        }
                      valid_local_ll /= valid_data.shape[0];

                      c_ll = C->eval(test_data,nc);
                      double test_local_ll = 0;
                      for (unsigned inst = 0; inst<test_data.shape[0]; inst++)
                        {
                          global_test_lls[inst] += exp(c_ll[inst]);
                          test_local_ll += log(global_test_lls[inst] / (nc + 1));
                        }
                      test_local_ll /= test_data.shape[0];

                      std::cout << "ll: " << train_local_ll << " " << test_local_ll << std::endl;

                      output << nc + 1 << ","
                             << input_parameters.min_instances[mi] << ","
                             << input_parameters.min_features[mf] << ","
                             << input_parameters.alpha[ma];

                      output << "," << learn_time << "," << eval_time;
                      output << "," << train_local_ll << ",";
                      output << "," << valid_local_ll << ",";
                      output << "," << test_local_ll;
                      output << std::endl;
 

                   }

                }


              std::cout << std::endl;
            }
        }
    }
  output.close ();
}
