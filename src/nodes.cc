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

#include "nodes.h"

int
node::_id_counter = 0;

node::node (node_type type)
{
  SOFT_ASSERT (type == TREE_NODE || type == OR_NODE
               || type == OPTION_NODE, "error: unknown node type!") _type =
    type;
  _id = _id_counter++;
}

void
node::init_id_counter ()
{
  _id_counter = 0;
}

node::~node ()
{

}

int
node::get_id () const
{
  return _id;
}

node_type
node::get_type () const
{
  return _type;
}

tree_node::tree_node (std::shared_ptr < cltree > clt):node (TREE_NODE)
{
  _tree = clt;
}

std::vector < double >
tree_node::eval (dataset & X)
{
  return _tree->eval (X);
}

std::vector < double >
tree_node::eval (dataset & X, std::vector < int >&row_idx)
{
  return _tree->eval (X, row_idx, _scope);
}

void
tree_node::fit (dataset & X, double alpha)
{
  _tree->fit (X, _row_idx.size (), _row_idx, _scope, _scope_length, alpha);
}


or_node::or_node (std::shared_ptr < tree_node > &ln,
                  std::shared_ptr < tree_node > &rn, double lw, double rw,
                  int of):
  node (OR_NODE)
{
  _left_child = ln;
  _right_child = rn;
  _left_weight = lw;
  _right_weight = rw;
  _or_feature = of;
}

void
or_node::set_left_child (const std::shared_ptr < node > &lc)
{
  _left_child = lc;
}

void
or_node::set_right_child (const std::shared_ptr < node > rc)
{
  _right_child = rc;
}

std::shared_ptr < node > or_node::get_left_child ()
{
  return _left_child;
}

std::shared_ptr < node > or_node::get_right_child ()
{
  return _right_child;
}

unsigned int
or_node::get_or_feature ()
{
  return _or_feature;
}

double
or_node::get_left_weight ()
{
  return _left_weight;
}

double
or_node::get_right_weight ()
{
  return _right_weight;
}

std::vector < double >
or_node::eval (dataset & X, std::vector < int >&row_idx)
{
  std::vector < double >lls (row_idx.size (), 0.0);

  std::vector < int >left_row_idx, right_row_idx;
  int rowsIdV_size = row_idx.size ();
  for (int i = 0; i < rowsIdV_size; i++)
    if (X.data[row_idx[i]][_or_feature])
      right_row_idx.push_back (row_idx[i]);
    else
      left_row_idx.push_back (row_idx[i]);


  std::vector < double >left_ll = _left_child->eval (X, left_row_idx);
  std::vector < double >right_ll = _right_child->eval (X, right_row_idx);


  int lc = 0;
  int rc = 0;
  double logRW = log (_right_weight);
  double logLW = log (_left_weight);
  for (int i = 0; i < rowsIdV_size; i++)
    if (X.data[row_idx[i]][_or_feature])
      {
        lls[i] = logRW + right_ll[rc];
        rc++;
      }
    else
      {
        lls[i] = logLW + left_ll[lc];
        lc++;
      }

  return lls;
}

std::vector < double >
or_node::eval (dataset & X)
{
  std::vector < int >rows;
  rows.resize (X.shape[0]);
  for (unsigned int i = 0; i < X.shape[0]; i++)
    rows[i] = i;

  return eval (X, rows);
}

option_node::option_node ():node (OPTION_NODE)
{

}

option_node::option_node (std::vector < std::shared_ptr < or_node > >&or_nodes,
                          std::vector < double >&weights) : node(OPTION_NODE)
{
  for (unsigned int i = 0; i < or_nodes.size (); i++)
    {
      _children.push_back (or_nodes[i]);
      _weights.push_back (weights[i]);
    }
}


void
option_node::push_back_child (const std::shared_ptr < or_node > child)
{
  _children.push_back (child);
}

void
option_node::push_back_weight (const double weight)
{
  _weights.push_back (weight);
}

std::shared_ptr < or_node > option_node::get_child (int id)
{
  return _children[id];
}

double
option_node::get_weight (int id)
{
  return _weights[id];
}

unsigned int
option_node::n_children ()
{
  return _children.size ();
}

std::vector < double >
option_node::eval (dataset & X)
{
  std::vector < int >rows;
  rows.resize (X.shape[0]);
  for (unsigned int i = 0; i < X.shape[0]; i++)
    rows[i] = i;

  return eval (X, rows);
}


std::vector < double >
option_node::eval (dataset & X, std::vector < int >&row_idx)
{
  std::vector < double >lls;
  lls.resize (row_idx.size (), 0.0);

  std::vector < std::vector < double >>children_ll;
  for (unsigned int i = 0; i < n_children (); i++)
    children_ll.push_back (_children[i]->eval (X, row_idx));

  std::vector < double >log_weights;
  for (unsigned int i = 0; i < _weights.size (); i++)
    log_weights.push_back (log (_weights[i]));
  unsigned int row_idx_size = row_idx.size ();
  for (unsigned int i = 0; i < row_idx_size; i++)
    {
      // log-sum-exp trick
      children_ll[0][i] += log_weights[0];
      double max_log_val = children_ll[0][i];
      for (unsigned int k = 1; k < n_children (); k++)
        {
          children_ll[k][i] += log_weights[k];
          if (children_ll[k][i] > max_log_val)
            max_log_val = children_ll[k][i];
        }
      double lse = 0.0;
      for (unsigned int k = 0; k < n_children (); k++)
        lse += exp (children_ll[k][i] - max_log_val);
      lls[i] = max_log_val + log (lse);
    }
  return lls;
}
