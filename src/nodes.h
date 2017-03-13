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

#ifndef _NODES
#define _NODES

#include <iostream>
#include <memory>
#include <cmath>
#include <random>

#include "cltree.h"
#include "dataset.h"
#include "globals.h"

#define OR_NODE 0
#define LEAF_NODE 1
#define OPTION_NODE 2
#define TREE_NODE 3

typedef int node_type;

class node
{
  static int _id_counter;
  node_type _type;
  int _id;
 public:
  node (node_type);
  ~node ();
  static void init_id_counter ();

  std::vector < int >_scope;
  unsigned int _scope_length;
  // std::weak_ptr used to break circular references of std::shared_ptr,
  // no memory leak
  std::weak_ptr < node > _parent;
  std::vector < int >_row_idx;
  unsigned int _depth;

  int get_id () const;
  node_type get_type () const;
  virtual std::vector < double >eval (dataset &) = 0;
  virtual std::vector < double >eval (dataset &, std::vector < int >&) = 0;
  virtual void sample(std::vector<int>&) = 0;
};

template < class D > class leaf_node:public node
{
  std::shared_ptr < D > _model;
 public:
  ~leaf_node();
  leaf_node (std::shared_ptr < D >);
  void fit (dataset &, double);
  void sample(std::vector<int>&);
  std::vector < double >eval (dataset &);
  std::vector < double >eval (dataset &, std::vector < int >&);
};

template < class D >
leaf_node < D >::~leaf_node ()
{
}

template < class D >
leaf_node < D >::leaf_node (std::shared_ptr < D > model):node (LEAF_NODE)
{
  _model = model;
}

template < class D > std::vector < double >
leaf_node <D >::eval (dataset & X)
{
  return _model->eval (X);
}

template < class D >
void
leaf_node <D >::sample (std::vector<int>& _sample)
{
  _model->sample (_sample, _scope);
}

template < class D >
std::vector < double >
leaf_node <D >::eval (dataset & X, std::vector < int >&row_idx)
{
  return _model->eval (X, row_idx, _scope);
}

template < class D >
void
leaf_node <D >::fit (dataset & X, double alpha)
{
  _model->fit (X, _row_idx.size (), _row_idx, _scope, _scope_length, alpha);
}


template < class D > class or_node:public node
{
 private:
  std::shared_ptr < node > _left_child;
  std::shared_ptr < node > _right_child;
  double _left_weight;
  double _right_weight;
  unsigned int _or_feature;
 public:
  unsigned int get_or_feature ();
  void set_left_child (const std::shared_ptr < node > &);
  void set_right_child (const std::shared_ptr < node >);
  std::shared_ptr < node > get_left_child ();
  std::shared_ptr < node > get_right_child ();
  or_node (std::shared_ptr < leaf_node < D > >&, std::shared_ptr < leaf_node < D > >&, double, double, int);

  void sample (std::vector<int>&);
  std::vector < double > eval (dataset &);
  std::vector < double > eval (dataset &, std::vector < int >&);
};

template < class D >
or_node < D >::or_node (std::shared_ptr < leaf_node < D > >&ln,
                        std::shared_ptr < leaf_node < D > >&rn, double lw, double rw, int of) :
node (OR_NODE)
{
  _left_child = ln;
  _right_child = rn;
  _left_weight = lw;
  _right_weight = rw;
  _or_feature = of;
}

template < class D > void
or_node <D >::set_left_child (const std::shared_ptr < node > &lc)
{
  _left_child = lc;
}

template < class D > void
or_node <D >::set_right_child (const std::shared_ptr < node > rc)
{
  _right_child = rc;
}

template < class D > std::shared_ptr < node > or_node < D >::get_left_child ()
{
  return _left_child;
}

template < class D > std::shared_ptr < node > or_node < D >::get_right_child ()
{
  return _right_child;
}

template < class D > unsigned int
or_node <D >::get_or_feature ()
{
  return _or_feature;
}


template < class D >
void
or_node<D>::sample (std::vector<int>& _sample)
{
  std::bernoulli_distribution b_distr (_right_weight);
  if (b_distr(random_generator))
    {
      _sample[_or_feature]=1;
      _right_child->sample(_sample);
    }
  _left_child->sample(_sample);
}

template < class D > std::vector < double >
or_node <D >::eval (dataset & X, std::vector < int >&row_idx)
{
  std::vector < double >
    lls (row_idx.size (), 0.0);

  std::vector < int >
    left_row_idx,
    right_row_idx;
  int
    rowsIdV_size = row_idx.size ();
  for (int i = 0; i < rowsIdV_size; i++)
    if (X.data[row_idx[i]][_or_feature])
      right_row_idx.push_back (row_idx[i]);
    else
      left_row_idx.push_back (row_idx[i]);


  std::vector < double >
    left_ll = _left_child->eval (X, left_row_idx);
  std::vector < double >
    right_ll = _right_child->eval (X, right_row_idx);


  int
    lc = 0;
  int
    rc = 0;
  double
    logRW = log (_right_weight);
  double
    logLW = log (_left_weight);
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

template < class D > std::vector < double >
or_node <D >::eval (dataset & X)
{
  std::vector < int >
    rows;
  rows.resize (X.shape[0]);
  for (unsigned int i = 0; i < X.shape[0]; i++)
    rows[i] = i;

  return eval (X, rows);
}


template < class D > class option_node:public node
{
  std::vector < std::shared_ptr < or_node < D > > >_children;
  std::vector < double >
    _weights;
 public:
  option_node ();
  option_node (std::vector < std::shared_ptr < or_node < D > > >&, std::vector < double >&);
  void push_back_child (const std::shared_ptr < or_node < D > >);
  void push_back_weight (const double);
  std::shared_ptr < or_node < D > >get_child (int);
  double get_weight (int);
  unsigned int n_children ();
  void sample (std::vector<int>&);
  std::vector < double > eval (dataset &);
  std::vector < double > eval (dataset &, std::vector < int >&);
};

template < class D > option_node < D >::option_node ():node (OPTION_NODE) {}

template < class D >
option_node < D >::option_node (std::vector < std::shared_ptr < or_node < D > > >&or_nodes,
                                std::vector < double >&weights):
node (OPTION_NODE)
{
  for (unsigned int i = 0; i < or_nodes.size (); i++)
    {
      _children.push_back (or_nodes[i]);
      _weights.push_back (weights[i]);
    }
}

template < class D > void
option_node <D >::push_back_child (const std::shared_ptr < or_node < D > >child)
{
  _children.push_back (child);
}

template < class D > void
option_node <D >::push_back_weight (const double weight)
{
  _weights.push_back (weight);
}

template < class D > std::shared_ptr < or_node < D > >option_node < D >::get_child (int id)
{
  return _children[id];
}

template < class D > double
option_node <
D >::get_weight (int id)
{
  return _weights[id];
}

template < class D > unsigned int
option_node <D >::n_children ()
{
  return _children.size ();
}

template < class D >
void
option_node <D >::sample (std::vector<int>& _sample)
{
}


template < class D > std::vector < double >
option_node <D >::eval (dataset & X)
{
  std::vector < int >
    rows;
  rows.resize (X.shape[0]);
  for (unsigned int i = 0; i < X.shape[0]; i++)
    rows[i] = i;

  return eval (X, rows);
}


template < class D > std::vector < double >
option_node <D >::eval (dataset & X, std::vector < int >&row_idx)
{
  std::vector < double >
    lls;
  lls.resize (row_idx.size (), 0.0);

  std::vector < std::vector < double >>
    children_ll;
  for (unsigned int i = 0; i < n_children (); i++)
    children_ll.push_back (_children[i]->eval (X, row_idx));

  std::vector < double >
    log_weights;
  for (unsigned int i = 0; i < _weights.size (); i++)
    log_weights.push_back (log (_weights[i]));
  unsigned int
    row_idx_size = row_idx.size ();
  for (unsigned int i = 0; i < row_idx_size; i++)
    {
      // log-sum-exp trick
      children_ll[0][i] += log_weights[0];
      double
        max_log_val = children_ll[0][i];
      for (unsigned int k = 1; k < n_children (); k++)
        {
          children_ll[k][i] += log_weights[k];
          if (children_ll[k][i] > max_log_val)
            max_log_val = children_ll[k][i];
        }
      double
        lse = 0.0;
      for (unsigned int k = 0; k < n_children (); k++)
        lse += exp (children_ll[k][i] - max_log_val);
      lls[i] = max_log_val + log (lse);
    }
  return lls;
}

#endif
