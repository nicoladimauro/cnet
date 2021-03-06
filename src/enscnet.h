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

#ifndef _ENSCNET
#define _ENSCNET

#include <iostream>
#include <memory>
#include <random>

#include "dataset.h"
#include "params.h"
#include "globals.h"
#include "cnet.h"

class ensemble
{
 public:
  virtual void fit (dataset &, paramsexp &) = 0;
  virtual std::vector < std::vector < double >>eval (dataset &) = 0;
  virtual std::vector < double >eval (dataset &, int) = 0;
  virtual bool is_pdf (int) = 0;
};

template < class M > class enscnet:public ensemble
{
 private:
  std::vector < std::shared_ptr < M > >_models;
  std::vector < double >_weights;
  unsigned int _n_models;
  bool _bootstraps;
 public:
  bool is_pdf (int);
  enscnet (int, bool bootstraps = true, unsigned n_mob=10);
  void fit (dataset &, paramsexp &);
  std::vector < std::vector < double >>eval (dataset &);
  std::vector < double >eval (dataset &, int);
};

template < class M > enscnet < M >::enscnet (int n_models, bool bootstraps, unsigned n_mob)
{
  _n_models = n_models;
  _bootstraps = bootstraps;
  for (unsigned int i = 0; i < n_models; i++)
    {
      _models.push_back (std::make_shared < M > (M ()));
    }
}

template <>
enscnet <cnet<mix_bernoulli>>::enscnet (int n_models, bool bootstraps, unsigned n_mob)
{
  _n_models = n_models;
  _bootstraps = bootstraps;
  for (unsigned int i = 0; i < n_models; i++)
    {
      _models.push_back (std::make_shared < cnet<mix_bernoulli> > (cnet<mix_bernoulli> (n_mob)));
    }
}

template <>
enscnet <xcnet<mix_bernoulli>>::enscnet (int n_models, bool bootstraps, unsigned n_mob)
{
  _n_models = n_models;
  _bootstraps = bootstraps;
  for (unsigned int i = 0; i < n_models; i++)
    {
      _models.push_back (std::make_shared < xcnet<mix_bernoulli> > (xcnet<mix_bernoulli> (n_mob)));
    }
}

template <>
enscnet <optioncnet<mix_bernoulli>>::enscnet (int n_models, bool bootstraps, unsigned n_mob)
{
  _n_models = n_models;
  _bootstraps = bootstraps;
  for (unsigned int i = 0; i < n_models; i++)
    {
      _models.push_back (std::make_shared < optioncnet<mix_bernoulli> > (optioncnet<mix_bernoulli> (n_mob)));
    }
}

template <>
enscnet <optionxcnet<mix_bernoulli>>::enscnet (int n_models, bool bootstraps, unsigned n_mob)
{
  _n_models = n_models;
  _bootstraps = bootstraps;
  for (unsigned int i = 0; i < n_models; i++)
    {
      _models.push_back (std::make_shared < optionxcnet<mix_bernoulli> > (optionxcnet<mix_bernoulli> (n_mob)));
    }
}


template < class M > void enscnet < M >::fit (dataset & X, paramsexp & input_parameters)
{
  if (!_bootstraps)
    for (unsigned int i = 0; i < _n_models; i++)
      _models[i]->fit (X, input_parameters);
  else
    {
      for (unsigned int i = 0; i < _n_models; i++)
        {
          dataset bootstrap;

          bootstrap.shape[0] = X.shape[0];
          bootstrap.shape[1] = X.shape[1];
          bootstrap.sparsity = X.sparsity;

          for (unsigned int k = 0; k < X.shape[0]; k++)
            {
              std::uniform_int_distribution < int >distribution (0, X.shape[0] - 1);
              int selected = distribution (random_generator);

              bootstrap.data.push_back (X.data[selected]);
              bootstrap.lil_data.push_back (X.lil_data[selected]);
            }
          _models[i]->fit (bootstrap, input_parameters);
        }
    }
}


template < class M > std::vector < std::vector < double >>
enscnet <
M >::eval (dataset & X)
{
  std::vector < double >
    lls;
  std::vector < std::vector < double >>
    models_ll;

  lls.resize (X.shape[0], 0.0);
  for (unsigned int i = 0; i < _n_models; i++)
    models_ll.push_back (_models[i]->eval (X));

  return models_ll;
}

template < class M > std::vector < double >
enscnet <
M >::eval (dataset & X, int component)
{
  return _models[component]->eval (X);
}

template < class M > bool enscnet < M >::is_pdf (int nc)
{
  int
    l = 16;
  std::vector < std::vector < int >>
    result = { {} };
  std::vector < std::vector < int >>
    pools;

  for (unsigned int i = 0; i < l; ++i)
    {
      std::vector < int >
        v = { 0, 1 };
      pools.push_back (v);
    }

  for (auto & pool:pools)
    {
      std::vector < std::vector < int >>
        new_result;
      for (auto & partial:result)
        {
          for (auto & v:pool)
            {
              std::vector < int >
                new_partial (partial);
              new_partial.push_back (v);
              new_result.push_back (new_partial);
            }
        }
      result = new_result;
    }

  SOFT_ASSERT (result.size () == pow (2, l), "error: possible worlds!");

  dataset X;
  X.shape[0] = pow (2, l);
  X.shape[1] = l;
  X.data = result;

  std::vector < std::vector < double >>
    lls_ = eval (X);
  std::vector < double >
    uniform_weights (nc, log ((double) 1 / nc));
  std::vector < double >
    lls = log_sum_exp (lls_, uniform_weights, nc);

  double
    sum = 0.0;
  for (auto & v:lls)
    sum += exp (v);

  std::cout << "Is pdf: " << " " << X.shape[0] << " " << result.size () << " " << std::setprecision (10) << sum;

  return (sum == 1.0);
}


#endif
