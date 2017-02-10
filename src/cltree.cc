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

#include "cltree.h"

void
minumum_spanning_tree (rarray < double, 2 > &M, int n, int *tree)
{
  bool *selected = new bool[n];
  double *key = new double[n];
  int i;

  for (i = 0; i < n; i++)
    {
      selected[i] = false;
      key[i] = std::numeric_limits < double >::max ();
    }

  // First node is always root of MST
  key[0] = 0;
  tree[0] = -1;

  for (i = 0; i < n - 1; i++)
    {
      double min = std::numeric_limits < double >::max ();
      int min_index;
      for (int v = 0; v < n; v++)
        if (selected[v] == false && key[v] < min)
          {
            min = key[v];
            min_index = v;
          }
      selected[min_index] = true;
      for (int v = 0; v < n; v++)
        if (M[min_index][v] && selected[v] == false
            && M[min_index][v] < key[v])
          {
            tree[v] = min_index;
            key[v] = M[min_index][v];
          }
    }
  delete[]selected;
  delete[]key;
}

cltree::cltree ()
{
  _fitted = false;
}

std::vector < double >
cltree::eval (dataset & X)
{
  unsigned int i, r;
  int p;

  SOFT_ASSERT (_fitted, "error: cltree is not fitted!");
  SOFT_ASSERT (_n_vars == X.shape[1],
               "error: cltree and data have not the same dimesion!");

  std::vector < double >lls (X.shape[0]);

  for (r = 0; r < X.shape[0]; r++)
    {
      double prob = 0;
      std::vector < int >&row_data = X.data[r];
      for (i = 0; i < _n_vars; i++)
        {
          p = _tree[i];
          if (p == -1)
            prob = prob + _log_factors[i][row_data[i]][0];
          else
            prob = prob + _log_factors[i][row_data[i]][row_data[p]];
        }
      lls[r] = prob;
    }
  return lls;
}

std::vector < double >
cltree::eval (dataset & X, std::vector < int >&rows_idx,
              std::vector < int >&scope)
{
  unsigned int i, r;
  int p;

  SOFT_ASSERT (_fitted, "error: cltree is not fitted!");

  std::vector < double >lls (rows_idx.size (), 0.0);

  std::vector < int >scope_assoc;
 

 unsigned int scope_size = scope.size ();
  for (i = 0; i < scope_size; ++i)
    if (scope[i])
      scope_assoc.push_back (i);

  SOFT_ASSERT (_n_vars == scope_assoc.size (),
               "error: cltree and data have not the same dimesion!");

  unsigned int rows_idx_size = rows_idx.size ();
  double lp;
  std::vector<int> data_row(_n_vars);
  for (r = 0; r < rows_idx_size; ++r)
    {
      std::vector < int >&row_data = X.data[rows_idx[r]];
      for (i = 0; i < _n_vars; ++i)
        data_row[i] = row_data[scope_assoc[i]];
      lp = _log_factors[0][data_row[0]][0];
      for (i = 1; i < _n_vars; ++i)
        lp += _log_factors[i][data_row[i]][data_row[_tree[i]]];
      lls[r] = lp;
    }

  /*
  for (r = 0; r < rows_idx_size; ++r)
    {
      double prob = 0;
      std::vector < int >&row_data = X.data[rows_idx[r]];
      for (i = 0; i < _n_vars; ++i)
        {
          p = _tree[i];
          if (p == -1)
            prob = prob + _log_factors[i][row_data[scope_assoc[i]]][0];
          else
            prob =
              prob +
              _log_factors[i][row_data[scope_assoc[i]]][row_data[scope_assoc[p]]];
        }
      lls[r] = prob;
    }
  */
  return lls;

}


void
cltree::fit (dataset & X, int n_rows, std::vector < int >&rows_idx,
             std::vector < int >&scope, int scope_length, double alpha)
{
  unsigned int i, j;

  _fitted = true;
  _n_vars = scope_length;

  compute_log_probs (X, rows_idx, scope, scope_length, alpha);

  rarray < double, 2 > MI (_n_vars, _n_vars);
  MI.fill (0.0);

  for (i = 0; i < _n_vars; ++i)
    for (j = i + 1; j < _n_vars; ++j)
      {
        double
          j_prob_00 = _log_j_probs[i][j][0][0],
          j_prob_01 = _log_j_probs[i][j][0][1],
          j_prob_10 = _log_j_probs[i][j][1][0],
          j_prob_11 = _log_j_probs[i][j][1][1],
          prob_i0 = _log_probs[i][0],
          prob_i1 = _log_probs[i][1],
          prob_j0 = _log_probs[j][0],
          prob_j1 = _log_probs[j][1];

        MI[i][j] += exp (j_prob_00) * (j_prob_00 - prob_i0 - prob_j0);
        MI[i][j] += exp (j_prob_01) * (j_prob_01 - prob_i0 - prob_j1);
        MI[i][j] += exp (j_prob_10) * (j_prob_10 - prob_i1 - prob_j0);
        MI[i][j] += exp (j_prob_11) * (j_prob_11 - prob_i1 - prob_j1);
        MI[i][j] *= -1.0;

        MI[j][i] = MI[i][j];
      }

  _tree = new int[_n_vars];

  minumum_spanning_tree (MI, _n_vars, _tree);

  // computing the factored represetation

  _log_factors = rarray < double, 3 > (_n_vars, 2, 2);
  _log_factors.fill (0.0);

  int p;
  for (i = 0; i < _n_vars; ++i)
    if (_tree[i] == -1)
      {
        _log_factors[i][0][0] = _log_probs[i][0];
        _log_factors[i][0][1] = _log_probs[i][0];
        _log_factors[i][1][0] = _log_probs[i][1];
        _log_factors[i][1][1] = _log_probs[i][1];
      }
    else
      {
        p = _tree[i];
        _log_factors[i][0][0] = _log_j_probs[i][p][0][0] - _log_probs[p][0];
        _log_factors[i][0][1] = _log_j_probs[i][p][0][1] - _log_probs[p][1];
        _log_factors[i][1][0] = _log_j_probs[i][p][1][0] - _log_probs[p][0];
        _log_factors[i][1][1] = _log_j_probs[i][p][1][1] - _log_probs[p][1];
      }
  _log_probs.clear ();
  _log_j_probs.clear ();

}

void
cltree::fit (dataset & X, double alpha)
{
  unsigned int i, j;

  _n_vars = X.shape[1];
  _fitted = true;

  compute_log_probs (X, alpha);

  // Compute MI
  rarray < double, 2 > MI (_n_vars, _n_vars);
  MI.fill (0.0);

  for (i = 0; i < _n_vars; i++)
    for (j = i + 1; j < _n_vars; j++)
      {
        MI[i][j] +=
          exp (_log_j_probs[i][j][0][0]) * (_log_j_probs[i][j][0][0] -
                                            _log_probs[i][0] -
                                            _log_probs[j][0]);
        MI[i][j] +=
          exp (_log_j_probs[i][j][0][1]) * (_log_j_probs[i][j][0][1] -
                                            _log_probs[i][0] -
                                            _log_probs[j][1]);
        MI[i][j] +=
          exp (_log_j_probs[i][j][1][0]) * (_log_j_probs[i][j][1][0] -
                                            _log_probs[i][1] -
                                            _log_probs[j][0]);
        MI[i][j] +=
          exp (_log_j_probs[i][j][1][1]) * (_log_j_probs[i][j][1][1] -
                                            _log_probs[i][1] -
                                            _log_probs[j][1]);
        MI[i][j] *= -1.0;
        MI[j][i] = MI[i][j];
      }


  _tree = new int[_n_vars];

  minumum_spanning_tree (MI, _n_vars, _tree);


  // computing the factored represetation

  _log_factors = rarray < double, 3 > (_n_vars, 2, 2);
  _log_factors.fill (0.0);

  int p;
  for (i = 0; i < _n_vars; i++)
    if (_tree[i] == -1)
      {
        _log_factors[i][0][0] = _log_probs[i][0];
        _log_factors[i][0][1] = _log_probs[i][0];
        _log_factors[i][1][0] = _log_probs[i][1];
        _log_factors[i][1][1] = _log_probs[i][1];
      }
    else
      {
        p = _tree[i];
        _log_factors[i][0][0] = _log_j_probs[i][p][0][0] - _log_probs[p][0];
        _log_factors[i][0][1] = _log_j_probs[i][p][0][1] - _log_probs[p][1];
        _log_factors[i][1][0] = _log_j_probs[i][p][1][0] - _log_probs[p][0];
        _log_factors[i][1][1] = _log_j_probs[i][p][1][1] - _log_probs[p][1];
      }
  _log_probs.clear ();
  _log_j_probs.clear ();
}


void
cltree::compute_log_probs (dataset & X, double alpha)
{
  int i, j, k;
  int n_rows = X.shape[0];
  int n_cols = X.shape[1];

  _log_probs = rarray < double, 2 > (n_cols, 2);
  _log_j_probs = rarray < double, 4 > (n_cols, n_cols, 2, 2);
  _log_probs.fill (0.0);
  _log_j_probs.fill (0.0);

  rarray < unsigned int, 2 > cooccurrences (n_cols, n_cols);
  cooccurrences.fill (0);

  for (k = 0; k < n_rows; ++k)
    {
      std::vector < int >&row_values = X.lil_data[k];
      int row_size = row_values.size ();
      for (i = 0; i < row_size; ++i)
        for (j = i; j < row_size; ++j)
          {
            cooccurrences[row_values[i]][row_values[j]]++;
          }
    }

  for (i = 1; i < n_cols; i++)
    for (j = 0; j < i; j++)
      cooccurrences[i][j] = cooccurrences[j][i];

  // additive smoothing, also called Laplace smoothing
  for (i = 0; i < n_cols; i++)
    {
      double prob =
        ((double) cooccurrences[i][i] + alpha) / ((double) n_rows + 2 * alpha);
      _log_probs[i][0] = log (1 - prob);
      _log_probs[i][1] = log (prob);
    }

  double det = (n_rows + 4 * alpha);
  double cc_ii, cc_ij, cc_jj;
  for (i = 0; i < n_cols; i++)
    {
      cc_ii = cooccurrences[i][i];
      for (j = i; j < n_cols; j++)
        {
          cc_ij = cooccurrences[i][j];
          cc_jj = cooccurrences[j][j];
          _log_j_probs[i][j][1][1] = log ((cc_ij + alpha) / det);
          _log_j_probs[i][j][0][1] = log ((cc_jj - cc_ij + alpha) / det);
          _log_j_probs[i][j][1][0] = log ((cc_ii - cc_ij + alpha) / det);
          _log_j_probs[i][j][0][0] =
            log ((n_rows - cc_jj - cc_ii + cc_ij + alpha) / det);

          _log_j_probs[j][i][1][1] = _log_j_probs[i][j][1][1];
          _log_j_probs[j][i][1][0] = _log_j_probs[i][j][0][1];
          _log_j_probs[j][i][0][1] = _log_j_probs[i][j][1][0];
          _log_j_probs[j][i][0][0] = _log_j_probs[i][j][0][0];
        }
    }
}


void
cltree::compute_log_probs (dataset & X, std::vector < int >&rows_i,
                           std::vector < int >&scope, int scope_length,
                           double alpha)
{

  int i, j, k;

  int n_rows = rows_i.size ();
  int n_cols = scope_length;

  _log_probs = rarray < double, 2 > (n_cols, 2);
  _log_j_probs = rarray < double, 4 > (n_cols, n_cols, 2, 2);
  _log_probs.fill (0.0);
  _log_j_probs.fill (0.0);


  int scope_size = scope.size ();
  std::vector < int >scope_assoc (scope_size);
  int c = 0;
  for (i = 0; i < scope_size; i++)
    if (scope[i])
      {
        scope_assoc[i] = c;
        c++;
      }

  rarray < unsigned int, 2 > cooccurrences (n_cols, n_cols);
  cooccurrences.fill (0);

  std::vector<int> scoped_epurated(scope_size);
  int epurated_l;
  for (k = 0; k < n_rows; ++k)
    {
      int r = rows_i[k];
      std::vector < int >&rdata = X.lil_data[r];
      int rdata_size = rdata.size ();
      epurated_l = 0;
      for (i=0;i<rdata_size;i++)
        {
          int v = rdata[i];
          if (scope[v])
            scoped_epurated[epurated_l++] = scope_assoc[v];
        }
      for (i = 0; i < epurated_l; ++i)
        {
          unsigned int se = scoped_epurated[i];
          for (j = i; j < epurated_l; ++j)
            ++cooccurrences[se][scoped_epurated[j]];
        }
    }

  for (i = 1; i < n_cols; i++)
    for (j = 0; j < i; j++)
      cooccurrences[i][j] = cooccurrences[j][i];

  // additive smoothing
  for (i = 0; i < n_cols; i++)
    {
      double prob =
        ((double) cooccurrences[i][i] + alpha) / ((double) n_rows + 2 * alpha);
      _log_probs[i][0] = log (1 - prob);
      _log_probs[i][1] = log (prob);
    }

  double det = (n_rows + 4 * alpha);
  double cc_ii, cc_ij, cc_jj;
  for (i = 0; i < n_cols; i++)
    {
      cc_ii = cooccurrences[i][i];
      for (j = i; j < n_cols; j++)
        {
          cc_ij = cooccurrences[i][j];
          cc_jj = cooccurrences[j][j];
          _log_j_probs[i][j][1][1] = log ((cc_ij + alpha) / det);
          _log_j_probs[i][j][0][1] = log ((cc_jj - cc_ij + alpha) / det);
          _log_j_probs[i][j][1][0] = log ((cc_ii - cc_ij + alpha) / det);
          _log_j_probs[i][j][0][0] =
            log ((n_rows - cc_jj - cc_ii + cc_ij + alpha) / det);

          _log_j_probs[j][i][1][1] = _log_j_probs[i][j][1][1];
          _log_j_probs[j][i][1][0] = _log_j_probs[i][j][0][1];
          _log_j_probs[j][i][0][1] = _log_j_probs[i][j][1][0];
          _log_j_probs[j][i][0][0] = _log_j_probs[i][j][0][0];
        }
    }
}

cltree::~cltree ()
{

  if (!_fitted)
    return;

  delete[]_tree;
}
