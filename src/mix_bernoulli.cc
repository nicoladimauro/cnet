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

#include "mix_bernoulli.h"

mix_bernoulli::mix_bernoulli () :
  _n_components (10),
  _fitted(false)
{
  _components.resize(_n_components);
}

mix_bernoulli::mix_bernoulli (int N) :
  _n_components (N),
  _fitted(false)
{
  _components.resize(_n_components);
}

std::vector < double >
mix_bernoulli::eval (dataset & X)
{
  unsigned n_rows = X.shape[0];
  // we assume to have uniform weights
  std::vector<double> ll_accumulator;
  ll_accumulator.resize(n_rows, 0.0);

  for (unsigned c=0; c<_n_components; c++)
    {
      std::vector<double> component_ll = _components[c]->eval(X);
      for (unsigned i=0; i<n_rows; i++)
        ll_accumulator[i] += exp(component_ll[i]);
    }
  for (unsigned i=0; i<n_rows; i++)
    ll_accumulator[i] = log(ll_accumulator[i]/_n_components);
  return ll_accumulator;
}

std::vector < double >
mix_bernoulli::eval (dataset & X, std::vector < int >&rows_idx, std::vector < int >&scope)
{

  unsigned n_rows = rows_idx.size();

  // we assume to have uniform weights
  std::vector<double> ll_accumulator;
  ll_accumulator.resize(n_rows, 0.0);

  for (unsigned c=0; c<_n_components; c++)
    {
      std::vector<double> component_ll = _components[c]->eval(X, rows_idx, scope);

      for (unsigned i=0; i<n_rows; i++)
        ll_accumulator[i] += exp(component_ll[i]);
    }
  for (unsigned i=0; i<n_rows; i++)
    ll_accumulator[i] = log(ll_accumulator[i]/_n_components);
  return ll_accumulator;
}

void
mix_bernoulli::fit (dataset & X, int n_rows, std::vector < int >&rows_idx,
                    std::vector < int >&scope, int scope_length, double alpha)
{
  for (unsigned c=0; c<_n_components; c++)
    {
      _components[c] = std::make_shared<bernoulli>();

      std::vector<int> bootstrap_rows_idx(rows_idx.size());
      std::uniform_int_distribution < int >distribution (0, rows_idx.size()-1);
      for (unsigned i=0; i<rows_idx.size(); i++)
        bootstrap_rows_idx[i]=rows_idx[distribution (random_generator)];
      _components[c]->fit(X, n_rows, bootstrap_rows_idx, scope, scope_length, alpha);
    }
}


void
mix_bernoulli::fit (dataset & X, double alpha)
{
  for (unsigned c=0; c<_n_components; c++)
    {
      _components[c] = std::make_shared<bernoulli>();
      _components[c]->fit(X, alpha);
    }
}


mix_bernoulli::~mix_bernoulli ()
{
}
