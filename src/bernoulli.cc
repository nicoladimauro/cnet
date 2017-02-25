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

#include "bernoulli.h"

bernoulli::bernoulli ()
{
  _fitted = false;
}

std::vector < double >
bernoulli::eval (dataset & X)
{
  unsigned int
    i, r;
  int
    p;

  SOFT_ASSERT (_fitted, "error: bernoulli is not fitted!");

  SOFT_ASSERT (_n_vars == X.shape[1],
               "error: bernoulli and data have not the same dimesion!");

  std::vector < double >
    lls (X.shape[0]);

  double
    lp;
  for (r = 0; r < X.shape[0]; ++r)
    {
      lp=0;
      for (i = 0; i < _n_vars; ++i)
        lp += _log_thetas[i][X.data[r][i]];
      lls[r] = lp;
    }
  return lls;
}

std::vector < double >
bernoulli::eval (dataset & X, std::vector < int >&rows_idx, std::vector < int >&scope)
{
  unsigned int
    i, r;
  int
    p;

  SOFT_ASSERT (_fitted, "error: bernoulli is not fitted!");

  std::vector < double >
    lls (rows_idx.size (), 0.0);

  std::vector < int >
    scope_assoc;


  unsigned int
    scope_size = scope.size ();
  for (i = 0; i < scope_size; ++i)
    if (scope[i])
      scope_assoc.push_back (i);

  SOFT_ASSERT (_n_vars == scope_assoc.size (),
               "error: bernoulli and data have not the same dimesion!");

  unsigned int
    rows_idx_size = rows_idx.size ();
  double
    lp;
   for (r = 0; r < rows_idx_size; ++r)
    {
      lp=0;
      int rr = rows_idx[r];
      for (i = 0; i < _n_vars; ++i)
        lp += _log_thetas[i][X.data[rr][scope_assoc[i]]];
      lls[r] = lp;
    }
  return lls;
}


void
bernoulli::fit (dataset & X, int n_rows, std::vector < int >&rows_idx,
                std::vector < int >&scope, int scope_length, double alpha)
{
  unsigned int
    i, j, k;

  _fitted = true;
  _n_vars = scope_length;

  _log_thetas.clear();
  for (unsigned k=0; k<_n_vars; k++)
    _log_thetas.push_back({0, 0});;

  int scope_size = scope.size ();
  std::vector < int >scope_assoc (scope_size);
  int c = 0;
  for (i = 0; i < scope_size; i++)
    if (scope[i])
      {
        scope_assoc[i] = c;
        c++;
      }

  for (k = 0; k < n_rows; ++k)
    {
      std::vector < int >&rdata = X.lil_data[rows_idx[k]];
      int rdata_size = rdata.size ();
      for (i = 0; i < rdata_size; ++i)
        {
          int v = rdata[i];
          if (scope[v])
            _log_thetas[scope_assoc[v]][1]++;
        }
    }

  for (unsigned k=0; k<_n_vars; k++)
    {
      _log_thetas[k][1] = (_log_thetas[k][1] + alpha) / (n_rows + 2*alpha);
      _log_thetas[k][0] = (1-_log_thetas[k][1]);
      _log_thetas[k][0] = log(_log_thetas[k][0]);
      _log_thetas[k][1] = log(_log_thetas[k][1]);
    }
}

void
bernoulli::fit (dataset & X, double alpha)
{
  unsigned int i, j, k;

  _fitted = true;
  _n_vars = X.shape[1];
  int n_rows = X.shape[0];

  _log_thetas.clear();
  for (unsigned k=0; k<_n_vars; k++)
    _log_thetas.push_back({0, 0});;

  for (k = 0; k < n_rows; ++k)
    {
      std::vector < int >&rdata = X.lil_data[k];
      int rdata_size = rdata.size ();
      for (i = 0; i < rdata_size; ++i)
        _log_thetas[rdata[i]][1]++;
    }


  for (unsigned k=0; k<_n_vars; k++)
    {
      _log_thetas[k][1] = (_log_thetas[k][1] + alpha) / (X.shape[0] + 2*alpha);
      _log_thetas[k][0] = (1-_log_thetas[k][1]);
      _log_thetas[k][0] = log(_log_thetas[k][0]);
      _log_thetas[k][1] = log(_log_thetas[k][1]);
    }
}


bernoulli::~bernoulli ()
{
}
