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

#include "cnet.h"

cnet::cnet ()
{
  node::init_id_counter ();
}

std::vector < double >
cnet::eval (dataset & X)
{
  return _root->eval (X);
}

bool
cnet::is_pdf ()
{
  int l = 16;
  std::vector < std::vector < int >>result = { {} };
  std::vector < std::vector < int >>pools;

  for (int i = 0; i < l; ++i)
    {
      std::vector < int >v = { 0, 1 };
      pools.push_back (v);
    }

  for (auto & pool:pools)
    {
      std::vector < std::vector < int >>new_result;
      for (auto & partial:result)
        {
          for (auto & v:pool)
            {
              std::vector < int >new_partial (partial);
              new_partial.push_back (v);
              new_result.push_back (new_partial);
            }
        }
      result = new_result;
    }

  dataset X;
  X.shape[0] = pow (2, l);
  X.shape[1] = l;
  X.data = result;

  std::vector < double >lls = eval (X);

  double sum = 0.0;
  for (auto & v:lls)
    sum += exp (v);

  std::cout << "Is pdf: " << " " << X.shape[0] << " " <<
    result.size () << " " << std::setprecision (10) << sum;

  return (sum == 1.0);
}

void
cnet::compute_stats ()
{
  double m_depth = 0.0;
  std::queue < std::shared_ptr < node > >nodes_to_process;
  nodes_to_process.push (_root);
  while (!nodes_to_process.empty ())
    {
      std::shared_ptr < node > current_node = nodes_to_process.front ();
      nodes_to_process.pop ();

      if (current_node->get_type () == TREE_NODE)
        {
          _n_tree_nodes++;
          if (current_node->_depth > _max_depth)
            _max_depth = current_node->_depth;
          m_depth += current_node->_depth;
        }
      else if (current_node->get_type () == OR_NODE)
        {
          _n_or_nodes++;
          nodes_to_process.push (std::static_pointer_cast < or_node >
                                 (current_node)->get_left_child ());
          nodes_to_process.push (std::static_pointer_cast < or_node >
                                 (current_node)->get_right_child ());
        }
      else if (current_node->get_type () == OPTION_NODE)
        {
          _n_option_nodes++;
          for (unsigned int i = 0;
               i < std::static_pointer_cast < option_node >
                 (current_node)->n_children (); i++)
            nodes_to_process.push (std::static_pointer_cast < option_node >
                                   (current_node)->get_child (i));
        }
    }
  _mean_depth = m_depth / _n_tree_nodes;
}

bool
cnet::make_or_node (dataset & X, std::shared_ptr < tree_node > n,
                    double node_ll, double &best_left_ll,
                    double &best_right_ll,
                    std::shared_ptr < tree_node > &left_tree_node,
                    std::shared_ptr < tree_node > &right_tree_node,
                    double alpha)
{

  double best_ll = node_ll;

  std::shared_ptr < cltree > best_left_clt;
  std::shared_ptr < cltree > best_right_clt;

  std::vector < int >best_left_data_row_index, best_right_data_row_index;
  std::vector < int >scope_split;

  int split_feature;

  if (verbose)
    std::cout << "  -> Trying to split...  ";
  int n_scope_size = n->_scope.size ();
  for (int i = 0; i < n_scope_size; i++)
    {
      if (n->_scope[i])
        {
          std::shared_ptr < cltree > left_clt =
            std::make_shared < cltree > ();
          std::shared_ptr < cltree > right_clt =
            std::make_shared < cltree > ();

          int rows_left = 0;
          int rows_right = 0;
          std::vector < int >left_data_row_index, right_data_row_index;

          int n_row_idx_size = n->_row_idx.size ();
          for (int j = 0; j < n_row_idx_size; j++)
            if (X.data[n->_row_idx[j]][i])
              {
                rows_right++;
                right_data_row_index.push_back (n->_row_idx[j]);
              }
            else
              {
                rows_left++;
                left_data_row_index.push_back (n->_row_idx[j]);
              }

          if (rows_left > 0 && rows_right > 0)
            {

              std::vector < int >scope = n->_scope;
              scope[i] = 0;

              left_clt->fit (X, rows_left, left_data_row_index, scope,
                             n->_scope_length - 1, alpha);
              right_clt->fit (X, rows_right, right_data_row_index, scope,
                              n->_scope_length - 1, alpha);

              double left_ll =
                mean (left_clt->eval (X, left_data_row_index, scope));
              double right_ll =
                mean (right_clt->eval (X, right_data_row_index, scope));
              double split_ll =
                ((left_ll +
                  log ((double) rows_left / (rows_left + rows_right))) *
                 rows_left + (right_ll +
                              log ((double) rows_right /
                                   (rows_left +
                                    rows_right))) * rows_right) / (rows_left +
                                                                   rows_right);

              if (split_ll > best_ll)
                {
                  best_left_ll = left_ll;
                  best_right_ll = right_ll;
                  best_ll = split_ll;
                  best_left_clt = left_clt;
                  best_right_clt = right_clt;
                  best_right_data_row_index = right_data_row_index;
                  best_left_data_row_index = left_data_row_index;
                  split_feature = i;
                  scope_split = scope;
                }
            }
        }
    }

  if (best_ll > node_ll)
    {
      if (verbose)
        {
          std::
            cout << "Splitting on " << split_feature << " [#l: " <<
            best_left_data_row_index.
            size () << ", #r: " << best_right_data_row_index.
            size () << "]" << std::endl;
          std::cout.flush ();
        }

      double left_w, right_w;
      left_w = (double) best_left_data_row_index.size () /
        (best_left_data_row_index.size () +
         best_right_data_row_index.size ());
      right_w =
        (double) best_right_data_row_index.size () /
        (best_left_data_row_index.size () +
         best_right_data_row_index.size ());


      left_tree_node = std::make_shared < tree_node > (best_left_clt);
      right_tree_node = std::make_shared < tree_node > (best_right_clt);

      left_tree_node->_scope = scope_split;
      right_tree_node->_scope = scope_split;
      left_tree_node->_scope_length = n->_scope_length - 1;
      right_tree_node->_scope_length = n->_scope_length - 1;


      left_tree_node->_row_idx = best_left_data_row_index;
      right_tree_node->_row_idx = best_right_data_row_index;

      left_tree_node->_depth = n->_depth + 1;
      right_tree_node->_depth = n->_depth + 1;

      if (n == _root)
        {
          _root =
            std::make_shared < or_node > (left_tree_node, right_tree_node,
                                          left_w, right_w, split_feature);
          left_tree_node->_parent = _root;
          right_tree_node->_parent = _root;
        }
      else
        {
          if (std::static_pointer_cast < or_node >
              (n->_parent.lock ())->get_left_child () == n)
            {
              std::static_pointer_cast < or_node >
                (n->_parent.lock ())->set_left_child (std::make_shared < or_node >
                                                      (left_tree_node, right_tree_node,
                                                       left_w, right_w, split_feature));

              left_tree_node->_parent =
                std::static_pointer_cast < or_node >
                (n->_parent.lock ())->get_left_child ();
              right_tree_node->_parent =
                std::static_pointer_cast < or_node >
                (n->_parent.lock ())->get_left_child ();
              std::static_pointer_cast < or_node >
                (n->_parent.lock ())->get_left_child ()->_parent = n->_parent;
            }
          else
            {
              std::static_pointer_cast < or_node >
                (n->_parent.lock ())->set_right_child (std::make_shared <or_node >
                                                       (left_tree_node, right_tree_node,
                                                        left_w, right_w, split_feature));

              left_tree_node->_parent =
                std::static_pointer_cast < or_node >
                (n->_parent.lock ())->get_right_child ();
              right_tree_node->_parent =
                std::static_pointer_cast < or_node >
                (n->_parent.lock ())->get_right_child ();
              std::static_pointer_cast < or_node >
                (n->_parent.lock ())->get_right_child ()->_parent =
                n->_parent;
            }
        }
      return true;
    }
  return false;
}

void
cnet::fit (dataset & X, paramsexp & input_parameters)
{
  unsigned int min_instances = input_parameters.min_instances;
  unsigned int min_features = input_parameters.min_features;


  std::map < int, double >node_training_ll;
  std::shared_ptr < cltree > root_cltree (new cltree ());
  std::shared_ptr < tree_node > n;

  root_cltree->fit (X, input_parameters.alpha);
  _root = std::make_shared < tree_node > (root_cltree);

  node_training_ll[_root->get_id ()] = mean (root_cltree->eval (X));


  if (verbose)
    std::cout << "Fitting the starting tree... ";

  for (unsigned int i = 0; i < X.shape[1]; i++)
    _root->_scope.push_back (1);
  _root->_scope_length = X.shape[1];

  for (unsigned int i = 0; i < X.shape[0]; i++)
    _root->_row_idx.push_back (i);
  _root->_depth = 1;

  if (verbose)
    std::cout << "ll: " << node_training_ll[_root->get_id ()] << std::endl;

  std::queue < std::shared_ptr < tree_node > >nodes_to_process;
  if (_root->_row_idx.size () > min_instances
      && _root->_scope_length > min_features)
    nodes_to_process.push (std::dynamic_pointer_cast < tree_node > (_root));

  while (!nodes_to_process.empty ())
    {
      n = nodes_to_process.front ();
      nodes_to_process.pop ();

      if (verbose)
        {
          std::cout << "Node Id " << n->get_id () << ", # instances " << n->
            _row_idx.size () << ", scope length " << n->
            _scope_length << ", local ll " << node_training_ll[n->
                                                               get_id ()] <<
            std::endl;
          std::cout.flush ();
        }

      double best_left_ll, best_right_ll;
      std::shared_ptr < tree_node > best_left_node, best_right_node;

      if (make_or_node
          (X, n, node_training_ll[n->get_id ()], best_left_ll, best_right_ll,
           best_left_node, best_right_node, input_parameters.alpha))
        {
          node_training_ll[best_left_node->get_id ()] = best_left_ll;
          node_training_ll[best_right_node->get_id ()] = best_right_ll;
          if (best_left_node->_scope_length > min_features
              && best_left_node->_row_idx.size () > min_instances)
            nodes_to_process.push (best_left_node);
          if (best_right_node->_scope_length > min_features
              && best_right_node->_row_idx.size () > min_instances)
            nodes_to_process.push (best_right_node);
        }
      else
        {
          if (verbose)
            {
              std::cout << "no splitting" << std::endl;
              std::cout.flush ();
            }
        }
      best_left_node.reset ();
      best_right_node.reset ();
    }
}

bool
xcnet::make_or_node (dataset & X,
                     std::shared_ptr < tree_node > n,
                     std::shared_ptr < tree_node > &left_node,
                     std::shared_ptr < tree_node > &right_node, double alpha)
{

  std::vector < int >candidate_splits;

  for (unsigned int i = 0; i < n->_scope.size (); i++)
    if (n->_scope[i])
      candidate_splits.push_back (i);
  shuffle (candidate_splits.begin(), candidate_splits.end(), random_generator);

  while (candidate_splits.size())
    {
      int splitFeature = candidate_splits.back();
      candidate_splits.pop_back();

      std::shared_ptr < cltree > left_clt (new cltree);
      std::shared_ptr < cltree > right_clt (new cltree);

      int rows_left = 0;
      int rows_right = 0;
      std::vector < int >left_data_row_index, right_data_row_index;

      unsigned int n_row_idx_size = n->_row_idx.size ();
      for (unsigned int j = 0; j < n_row_idx_size; j++)
        if (X.data[n->_row_idx[j]][splitFeature])
          {
            rows_right++;
            right_data_row_index.push_back (n->_row_idx[j]);
          }
        else
          {
            rows_left++;
            left_data_row_index.push_back (n->_row_idx[j]);
          }

      if (rows_left > 0 && rows_right > 0)
        {

          if (verbose)
            {
              std::
                cout << "Splitting on " << splitFeature << " [#l: " << rows_left
                     << ", #r: " << rows_right << "]" << std::endl;
              std::cout.flush ();
            }

          std::vector < int >children_scope = n->_scope;
          children_scope[splitFeature] = 0;

          double left_w, right_w;
          left_w = (double) rows_left / (rows_left + rows_right);
          right_w = (double) rows_right / (rows_left + rows_right);

          std::shared_ptr < cltree > left_clt (new cltree);
          std::shared_ptr < cltree > right_clt (new cltree);

          std::shared_ptr < tree_node > left_tree_node (new tree_node (left_clt));
          std::shared_ptr < tree_node >
            right_tree_node (new tree_node (right_clt));
          left_tree_node->_scope = children_scope;
          right_tree_node->_scope = children_scope;
          left_tree_node->_scope_length = n->_scope_length - 1;
          right_tree_node->_scope_length = n->_scope_length - 1;
          left_tree_node->_row_idx = left_data_row_index;
          right_tree_node->_row_idx = right_data_row_index;

          left_tree_node->_depth = n->_depth + 1;
          right_tree_node->_depth = n->_depth + 1;

          left_node = left_tree_node;
          right_node = right_tree_node;

          if (n == _root)
            {
              _root =
                std::make_shared < or_node >
                (or_node
                 (left_tree_node, right_tree_node, left_w, right_w,
                  splitFeature));
              left_tree_node->_parent = _root;
              right_tree_node->_parent = _root;
            }
          else
            {
              if (std::static_pointer_cast < or_node >
                  (n->_parent.lock ())->get_left_child () == n)
                {
                  std::static_pointer_cast < or_node >
                    (n->_parent.lock ())->set_left_child (std::make_shared <
                                                          or_node >
                                                          (or_node
                                                           (left_tree_node,
                                                            right_tree_node,
                                                            left_w, right_w,
                                                            splitFeature)));
                  left_tree_node->_parent =
                    std::static_pointer_cast < or_node >
                    (n->_parent.lock ())->get_left_child ();
                  right_tree_node->_parent =
                    std::static_pointer_cast < or_node >
                    (n->_parent.lock ())->get_left_child ();
                  std::static_pointer_cast < or_node >
                    (n->_parent.lock ())->get_left_child ()->_parent = n->_parent;
                }
              else
                {
                  std::static_pointer_cast < or_node >
                    (n->_parent.lock ())->set_right_child (std::make_shared <
                                                           or_node >
                                                           (or_node
                                                            (left_tree_node,
                                                             right_tree_node,
                                                             left_w, right_w,
                                                             splitFeature)));

                  left_tree_node->_parent =
                    std::static_pointer_cast < or_node >
                    (n->_parent.lock ())->get_right_child ();
                  right_tree_node->_parent =
                    std::static_pointer_cast < or_node >
                    (n->_parent.lock ())->get_right_child ();
                  std::static_pointer_cast < or_node >
                    (n->_parent.lock ())->get_right_child ()->_parent =
                    n->_parent;
                }
            }
          return true;
        }
    }
  return false;
}


void
xcnet::fit (dataset & X, paramsexp & input_parameters)
{

  unsigned int min_instances = input_parameters.min_instances;
  unsigned int min_features = input_parameters.min_features;

  // initially set the root of the network being a tree_node
  std::shared_ptr < cltree > root_cltree (new cltree);
  _root = std::make_shared < tree_node > (root_cltree);

  for (unsigned int i = 0; i < X.shape[1]; i++)
    _root->_scope.push_back (1);
  _root->_scope_length = X.shape[1];
  for (unsigned int i = 0; i < X.shape[0]; i++)
    _root->_row_idx.push_back (i);
  _root->_depth = 1;

  std::queue < std::shared_ptr < tree_node > >nodes_to_process;
  if (_root->_row_idx.size () > min_instances
      && _root->_scope_length > min_features)
    nodes_to_process.push (std::dynamic_pointer_cast < tree_node > (_root));
  else
    std::static_pointer_cast < tree_node > (_root)->fit (X,
                                                         input_parameters.
                                                         alpha);

  std::shared_ptr < tree_node > n;



  while (!nodes_to_process.empty ())
    {
      n = nodes_to_process.front ();
      nodes_to_process.pop ();

      if (verbose)
        std::cout << "Node Id " << n->get_id () << ", # instances " <<
          n->_row_idx.size () << ", scope length " << n->
          _scope_length << std::endl;

      std::shared_ptr < tree_node > left_node, right_node;
      if (make_or_node (X, n, left_node, right_node, input_parameters.alpha))
        {

          if (left_node->_scope_length > min_features
              && left_node->_row_idx.size () > min_instances)
            nodes_to_process.push (left_node);
          else
            left_node->fit (X, input_parameters.alpha);
          if (right_node->_scope_length > min_features
              && right_node->_row_idx.size () > min_instances)
            nodes_to_process.push (right_node);
          else
            right_node->fit (X, input_parameters.alpha);
        }
      else
        {
          n->fit (X, input_parameters.alpha);
          if (verbose)
            {
              std::cout << "no splitting" << std::endl;
              std::cout.flush ();
            }
        }
    }
}


bool
optioncnet::make_option_node (dataset & X, std::shared_ptr < tree_node > n,
                              unsigned int option_node_length,
                              std::vector < std::shared_ptr < tree_node >
                              >&left_nodes,
                              std::vector < std::shared_ptr < tree_node >
                              >&right_nodes,
                              std::vector < double >&best_left_ll,
                              std::vector < double >&best_right_ll,
                              double alpha)
{

  std::vector < std::shared_ptr < cltree > >best_left_clt;
  std::vector < std::shared_ptr < cltree > >best_right_clt;

  std::vector < double >best_ll;

  std::vector < std::vector < int >>best_left_data_row_index,
    best_right_data_row_index;
  std::vector < std::vector < int >>scope_split;

  std::vector < int >split_feature;

  if (verbose)
    std::cout << "  Making an option node  " << std::endl;

  int scope_size = n->_scope.size ();
  for (int i = 0; i < scope_size; i++)
    {
      if (n->_scope[i])
        {

          std::shared_ptr < cltree > left_clt (new cltree);
          std::shared_ptr < cltree > right_clt (new cltree);

          int rows_left = 0;
          int rows_right = 0;
          std::vector < int >left_data_row_index, right_data_row_index;

          int n_row_idx_size = n->_row_idx.size ();
          for (int j = 0; j < n_row_idx_size; j++)
            if (X.data[n->_row_idx[j]][i])
              {
                rows_right++;
                right_data_row_index.push_back (n->_row_idx[j]);
              }
            else
              {
                rows_left++;
                left_data_row_index.push_back (n->_row_idx[j]);
              }

          if (rows_left > 0 && rows_right > 0)
            {

              std::vector < int >scope = n->_scope;
              scope[i] = 0;

              left_clt->fit (X, rows_left, left_data_row_index, scope,
                             n->_scope_length - 1, alpha);
              right_clt->fit (X, rows_right, right_data_row_index, scope,
                              n->_scope_length - 1, alpha);

              double left_ll =
                mean (left_clt->eval (X, left_data_row_index, scope));
              double right_ll =
                mean (right_clt->eval (X, right_data_row_index, scope));
              double split_ll =
                ((left_ll +
                  log ((double) rows_left / (rows_left + rows_right))) *
                 rows_left + (right_ll +
                              log ((double) rows_right /
                                   (rows_left +
                                    rows_right))) * rows_right) / (rows_left +
                                                                   rows_right);

              if (best_left_clt.size () < option_node_length)
                {
                  best_left_clt.push_back (left_clt);
                  best_right_clt.push_back (right_clt);
                  best_left_ll.push_back (left_ll);
                  best_right_ll.push_back (right_ll);
                  best_ll.push_back (split_ll);
                  best_left_data_row_index.push_back (left_data_row_index);
                  best_right_data_row_index.push_back (right_data_row_index);
                  split_feature.push_back (i);
                  scope_split.push_back (scope);
                }
              else
                {
                  int minPos = 0;
                  double minValue = best_ll[0];
                  for (unsigned int k = 1; k < option_node_length; k++)
                    if (best_ll[k] < minValue)
                      {
                        minPos = k;
                        minValue = best_ll[k];
                      }
                  best_left_clt[minPos] = left_clt;
                  best_right_clt[minPos] = right_clt;
                  best_left_ll[minPos] = left_ll;
                  best_right_ll[minPos] = right_ll;
                  best_ll[minPos] = split_ll;
                  best_left_data_row_index[minPos] = left_data_row_index;
                  best_right_data_row_index[minPos] = right_data_row_index;
                  split_feature[minPos] = i;
                  scope_split[minPos] = scope;
                }
            }
        }
    }

  if (verbose)
    {
      std::cout << "on features ";
      for (unsigned int k = 0; k < split_feature.size (); k++)
        std::cout << split_feature[k] << " ";
      std::cout << std::endl;
      std::cout.flush ();
    }

  if (split_feature.size () <= 1)
    return false;

  std::vector < std::shared_ptr < or_node > >or_nodes;
  std::vector < double >weights;

  for (unsigned int k = 0; k < split_feature.size (); k++)
    {

      double left_w, right_w;
      left_w = (double) best_left_data_row_index[k].size () /
        (best_left_data_row_index[k].size () +
         best_right_data_row_index[k].size ());
      right_w =
        (double) best_right_data_row_index[k].size () /
        (best_left_data_row_index[k].size () +
         best_right_data_row_index[k].size ());

      std::shared_ptr < tree_node >
        left_tree_node (new tree_node (best_left_clt[k]));
      std::shared_ptr < tree_node >
        right_tree_node (new tree_node (best_right_clt[k]));

      left_nodes.push_back (left_tree_node);
      right_nodes.push_back (right_tree_node);

      left_tree_node->_scope = scope_split[k];
      right_tree_node->_scope = scope_split[k];
      left_tree_node->_scope_length = n->_scope_length - 1;
      right_tree_node->_scope_length = n->_scope_length - 1;


      left_tree_node->_row_idx = best_left_data_row_index[k];
      right_tree_node->_row_idx = best_right_data_row_index[k];

      left_tree_node->_depth = n->_depth + 1;
      right_tree_node->_depth = n->_depth + 1;

      weights.push_back ((double) 1 / split_feature.size ());
      or_nodes.push_back (std::make_shared < or_node >
                          (or_node
                           (left_tree_node, right_tree_node, left_w, right_w,
                            split_feature[k])));
      left_tree_node->_parent = or_nodes.back ();
      right_tree_node->_parent = or_nodes.back ();
    }

  if (n == _root)
    {
      _root =
        std::make_shared < option_node > (option_node (or_nodes, weights));
      for (unsigned int k = 0; k < split_feature.size (); k++)
        or_nodes[k]->_parent = _root;
    }
  else
    {
      if (std::static_pointer_cast < or_node >
          (n->_parent.lock ())->get_left_child () == n)
        {
          std::static_pointer_cast < or_node >
            (n->_parent.lock ())->set_left_child (std::make_shared <
                                                  option_node >
                                                  (option_node
                                                   (or_nodes, weights)));

          for (unsigned int k = 0; k < split_feature.size (); k++)
            or_nodes[k]->_parent =
              std::static_pointer_cast < or_node >
              (n->_parent.lock ())->get_left_child ();
          std::static_pointer_cast < or_node >
            (n->_parent.lock ())->get_left_child ()->_parent = n->_parent;
        }
      else
        {
          std::static_pointer_cast < or_node >
            (n->_parent.lock ())->set_right_child (std::make_shared <
                                                   option_node >
                                                   (option_node
                                                    (or_nodes, weights)));
          for (unsigned int k = 0; k < split_feature.size (); k++)
            or_nodes[k]->_parent =
              std::static_pointer_cast < or_node >
              (n->_parent.lock ())->get_right_child ();

          std::static_pointer_cast < or_node >
            (n->_parent.lock ())->get_right_child ()->_parent = n->_parent;
        }
    }
  return true;
}

void
optioncnet::fit (dataset & X, paramsexp & input_parameters)
{
  unsigned int option_depth = input_parameters.option_length.size ();
  unsigned int option_node_length;


  unsigned int min_instances = input_parameters.min_instances;
  unsigned int min_features = input_parameters.min_features;
  std::map < int, double >node_training_ll;
  std::shared_ptr < cltree > root_cltree (new cltree);
  std::shared_ptr < tree_node > n;

  root_cltree->fit (X, input_parameters.alpha);
  _root = std::make_shared < tree_node > (root_cltree);
  node_training_ll[_root->get_id ()] = mean (root_cltree->eval (X));

  if (verbose)
    std::cout << "Fitting the starting tree... ";

  for (unsigned int i = 0; i < X.shape[1]; i++)
    _root->_scope.push_back (1);
  _root->_scope_length = X.shape[1];
  for (unsigned int i = 0; i < X.shape[0]; i++)
    _root->_row_idx.push_back (i);
  _root->_depth = 1;

  if (verbose)
    std::cout << "ll: " << node_training_ll[_root->get_id ()] << std::endl;

  std::queue < std::shared_ptr < tree_node > >nodes_to_process;
  if (_root->_row_idx.size () > min_instances
      && _root->_scope_length > min_features)
    nodes_to_process.push (std::dynamic_pointer_cast < tree_node > (_root));

  while (!nodes_to_process.empty ())
    {
      n = nodes_to_process.front ();
      nodes_to_process.pop ();

      if (verbose)
        {
          std::cout << "Node Id " << n->get_id () << ", # instances " << n->
            _row_idx.size () << ", scope length " << n->
            _scope_length << ", local ll " << node_training_ll[n->
                                                               get_id ()] <<
            std::endl;
          std::cout.flush ();
        }
      bool option_node_created = false;
      if (n->_depth <= option_depth)
        {
          option_node_length = input_parameters.option_length[n->_depth - 1];
          std::vector < std::shared_ptr < tree_node > >leftNodes, rightNodes;
          std::vector < double >leftLL, rightLL;
          option_node_created =
            make_option_node (X, n, option_node_length, leftNodes, rightNodes,
                              leftLL, rightLL, input_parameters.alpha);
          if (option_node_created)
            for (unsigned int k = 0; k < leftNodes.size (); k++)
              {
                node_training_ll[leftNodes[k]->get_id ()] = leftLL[k];
                node_training_ll[rightNodes[k]->get_id ()] = rightLL[k];
                if (leftNodes[k]->_scope_length > min_features
                    && leftNodes[k]->_row_idx.size () > min_instances)
                  nodes_to_process.push (leftNodes[k]);
                if (rightNodes[k]->_scope_length > min_features
                    && rightNodes[k]->_row_idx.size () > min_instances)
                  nodes_to_process.push (rightNodes[k]);
              }
        }
      if (!option_node_created)
        {

          double best_left_ll, best_right_ll;
          std::shared_ptr < tree_node > best_left_node, best_right_node;

          if (make_or_node
              (X, n, node_training_ll[n->get_id ()], best_left_ll,
               best_right_ll, best_left_node, best_right_node,
               input_parameters.alpha))
            {
              node_training_ll[best_left_node->get_id ()] = best_left_ll;
              node_training_ll[best_right_node->get_id ()] = best_right_ll;
              if (best_left_node->_scope_length > min_features
                  && best_left_node->_row_idx.size () > min_instances)
                nodes_to_process.push (best_left_node);
              if (best_right_node->_scope_length > min_features
                  && best_right_node->_row_idx.size () > min_instances)
                nodes_to_process.push (best_right_node);
            }
          else
            {
              if (verbose)
                {
                  std::cout << "no splitting" << std::endl;
                  std::cout.flush ();
                }
            }
        }
    }
}


bool
optionxcnet::make_option_node (dataset & X, std::shared_ptr < tree_node > n,
                               unsigned int option_node_length,
                               std::vector < std::shared_ptr < tree_node >
                               >&left_nodes,
                               std::vector < std::shared_ptr < tree_node >
                               >&right_nodes,
                               std::vector < double >&best_left_ll,
                               std::vector < double >&best_right_ll,
                               double alpha)
{

  std::vector < std::shared_ptr < cltree > >best_left_clt;
  std::vector < std::shared_ptr < cltree > >best_right_clt;

  std::vector < double >best_ll;

  std::vector < std::vector < int >>best_left_data_row_index,
    best_right_data_row_index;
  std::vector < std::vector < int >>scope_split;

  std::vector < int >split_feature;

  if (verbose)
    std::cout << "  Making an option node  " << std::endl;

  std::vector < int >candidate_splits;

  for (unsigned int i = 0; i < n->_scope.size (); i++)
    if (n->_scope[i])
      candidate_splits.push_back (i);

  shuffle (candidate_splits.begin(), candidate_splits.end(), random_generator);

  for (unsigned int k = 0; k < option_node_length; k++)
    {
      bool found_feature = false;
      while (candidate_splits.size() && !found_feature)
        {
          unsigned int i = candidate_splits.back();
          candidate_splits.pop_back();

          if (n->_scope[i])
            {

              std::shared_ptr < cltree > left_clt (new cltree);
              std::shared_ptr < cltree > right_clt (new cltree);

              int rows_left = 0;
              int rows_right = 0;
              std::vector < int >left_data_row_index, right_data_row_index;

              for (unsigned int j = 0; j < n->_row_idx.size (); j++)
                if (X.data[n->_row_idx[j]][i])
                  {
                    rows_right++;
                    right_data_row_index.push_back (n->_row_idx[j]);
                  }
                else
                  {
                    rows_left++;
                    left_data_row_index.push_back (n->_row_idx[j]);
                  }

              if (rows_left > 0 && rows_right > 0)
                {

                  found_feature = true;
                  std::vector < int >scope = n->_scope;
                  scope[i] = 0;

                  if (best_left_clt.size() < option_node_length)
                    {
                      best_left_clt.push_back (left_clt);
                      best_right_clt.push_back (right_clt);
                      best_left_data_row_index.push_back (left_data_row_index);
                      best_right_data_row_index.push_back (right_data_row_index);
                      split_feature.push_back (i);
                      scope_split.push_back (scope);
                    }
                }
            }
        }
    }

  if (verbose)
    {
      std::cout << "on features ";
      for (unsigned int k = 0; k < split_feature.size (); k++)
        std::cout << split_feature[k] << " ";
      std::cout << std::endl;
      std::cout.flush ();
    }

  if (split_feature.size () <= 1)
    return false;

  std::vector < std::shared_ptr < or_node > >or_nodes;
  std::vector < double >weights;

  // data partitioning among the nodes
  std::vector<std::vector<int>> partition_left(split_feature.size ());
  std::vector<std::vector<int>> partition_right(split_feature.size ());
  std::uniform_int_distribution<int> int_distribution(0,split_feature.size ()-1);

  // making bootstraps

  std::uniform_int_distribution<int> int_distribution_bstr(0,n->_row_idx.size ()-1);
  for (unsigned int j = 0; j < split_feature.size (); j++)
    {
      for (unsigned int k = 0; k < n->_row_idx.size (); k++)
        {
          unsigned id = int_distribution_bstr(random_generator);
          if (X.data[n->_row_idx[id]][split_feature[j]])
            partition_right[j].push_back(n->_row_idx[id]);
          else
            partition_left[j].push_back(n->_row_idx[id]);
        }
    }


  /*
  for (unsigned int j = 0; j < n->_row_idx.size (); j++)
    {
      unsigned comp = int_distribution(random_generator);
      for (unsigned cc=0; cc<split_feature.size (); cc++)
        {
          if (cc!=comp && X.data[n->_row_idx[j]][split_feature[cc]])
            {
              partition_right[cc].push_back(n->_row_idx[j]);
            }
          else
            {
              partition_left[cc].push_back(n->_row_idx[j]);
            }
        }
    }
  */
  /*
  for (unsigned int j = 0; j < n->_row_idx.size (); j++)
    {
      unsigned comp = int_distribution(random_generator);
      if (X.data[n->_row_idx[j]][split_feature[comp]])
        {
          partition_right[comp].push_back(n->_row_idx[j]);
        }
      else
        {
          partition_left[comp].push_back(n->_row_idx[j]);
        }
    }
  */
  for (unsigned int j = 0; j < split_feature.size (); j++)
    {
      if (partition_left[j].size()>0)
        best_left_data_row_index[j] = partition_left[j];
      if (partition_right[j].size()>0)
        best_right_data_row_index[j] = partition_right[j];
     }

  for (unsigned int k = 0; k < split_feature.size (); k++)
    {

      double left_w, right_w;
      left_w = (double) best_left_data_row_index[k].size () /
        (best_left_data_row_index[k].size () +
         best_right_data_row_index[k].size ());
      right_w =
        (double) best_right_data_row_index[k].size () /
        (best_left_data_row_index[k].size () +
         best_right_data_row_index[k].size ());

      std::shared_ptr < tree_node >
        left_tree_node (new tree_node (best_left_clt[k]));
      std::shared_ptr < tree_node >
        right_tree_node (new tree_node (best_right_clt[k]));

      left_nodes.push_back (left_tree_node);
      right_nodes.push_back (right_tree_node);

      left_tree_node->_scope = scope_split[k];
      right_tree_node->_scope = scope_split[k];
      left_tree_node->_scope_length = n->_scope_length - 1;
      right_tree_node->_scope_length = n->_scope_length - 1;


      left_tree_node->_row_idx = best_left_data_row_index[k];
      right_tree_node->_row_idx = best_right_data_row_index[k];

      left_tree_node->_depth = n->_depth + 1;
      right_tree_node->_depth = n->_depth + 1;

      //        weights.push_back ((double) (best_left_data_row_index[k].size () +
      //                                         best_right_data_row_index[k].size ()) / n->_row_idx.size ());
      weights.push_back ((double) 1 / split_feature.size ());
      or_nodes.push_back (std::make_shared < or_node >
                          (or_node
                           (left_tree_node, right_tree_node, left_w, right_w,
                            split_feature[k])));
      left_tree_node->_parent = or_nodes.back ();
      right_tree_node->_parent = or_nodes.back ();
    }

  if (n == _root)
    {
      _root =
        std::make_shared < option_node > (option_node (or_nodes, weights));
      for (unsigned int k = 0; k < split_feature.size (); k++)
        or_nodes[k]->_parent = _root;
    }
  else
    {
      if (std::static_pointer_cast < or_node >
          (n->_parent.lock ())->get_left_child () == n)
        {
          std::static_pointer_cast < or_node >
            (n->_parent.lock ())->set_left_child (std::make_shared <
                                                  option_node >
                                                  (option_node
                                                   (or_nodes, weights)));

          for (unsigned int k = 0; k < split_feature.size (); k++)
            or_nodes[k]->_parent =
              std::static_pointer_cast < or_node >
              (n->_parent.lock ())->get_left_child ();
          std::static_pointer_cast < or_node >
            (n->_parent.lock ())->get_left_child ()->_parent = n->_parent;
        }
      else
        {
          std::static_pointer_cast < or_node >
            (n->_parent.lock ())->set_right_child (std::make_shared <
                                                   option_node >
                                                   (option_node
                                                    (or_nodes, weights)));
          for (unsigned int k = 0; k < split_feature.size (); k++)
            or_nodes[k]->_parent =
              std::static_pointer_cast < or_node >
              (n->_parent.lock ())->get_right_child ();

          std::static_pointer_cast < or_node >
            (n->_parent.lock ())->get_right_child ()->_parent = n->_parent;
        }
    }
  return true;
}


void
optionxcnet::fit (dataset & X, paramsexp & input_parameters)
{

  unsigned int option_depth = input_parameters.option_length.size ();
  unsigned int option_node_length;

  unsigned int min_instances = input_parameters.min_instances;
  unsigned int min_features = input_parameters.min_features;

  if (verbose)
    std::cout << "Random CNET ... " << std::endl;

  // initially set the root of the network being a tree_node
  std::shared_ptr < cltree > root_cltree (new cltree);
  _root = std::make_shared < tree_node > (root_cltree);

  for (unsigned int i = 0; i < X.shape[1]; i++)
    _root->_scope.push_back (1);
  _root->_scope_length = X.shape[1];
  for (unsigned int i = 0; i < X.shape[0]; i++)
    _root->_row_idx.push_back (i);
  _root->_depth = 1;

  std::queue < std::shared_ptr < tree_node > >nodes_to_process;
  if (_root->_row_idx.size () > min_instances
      && _root->_scope_length > min_features)
    nodes_to_process.push (std::dynamic_pointer_cast < tree_node > (_root));
  else
    std::static_pointer_cast < tree_node > (_root)->fit (X,
                                                         input_parameters.
                                                         alpha);

  std::shared_ptr < tree_node > n;

  while (!nodes_to_process.empty ())
    {
      n = nodes_to_process.front ();
      nodes_to_process.pop ();

      if (verbose)
        std::cout << "Node Id " << n->get_id () << ", # instances " <<
          n->_row_idx.size () << ", scope length " << n->
          _scope_length << std::endl;

      bool option_node_created = false;
      if (n->_depth <= option_depth)
        {
          option_node_length = input_parameters.option_length[n->_depth - 1];
          std::vector < std::shared_ptr < tree_node > >leftNodes, rightNodes;
          std::vector < double >leftLL, rightLL;
          option_node_created =
            make_option_node (X, n, option_node_length, leftNodes, rightNodes,
                              leftLL, rightLL, input_parameters.alpha);
          if (option_node_created)
            for (unsigned int k = 0; k < leftNodes.size (); k++)
              {
                if (leftNodes[k]->_scope_length > min_features
                    && leftNodes[k]->_row_idx.size () > min_instances)
                  nodes_to_process.push (leftNodes[k]);
                else
                  leftNodes[k]->fit (X, input_parameters.alpha);
                if (rightNodes[k]->_scope_length > min_features
                    && rightNodes[k]->_row_idx.size () > min_instances)
                  nodes_to_process.push (rightNodes[k]);
                else
                  rightNodes[k]->fit (X, input_parameters.alpha);
              }
        }
      if (!option_node_created)
        {
          std::shared_ptr < tree_node > left_node, right_node;
          if (make_or_node
              (X, n, left_node, right_node, input_parameters.alpha))
            {

              if (left_node->_scope_length > min_features
                  && left_node->_row_idx.size () > min_instances)
                nodes_to_process.push (left_node);
              else
                left_node->fit (X, input_parameters.alpha);
              if (right_node->_scope_length > min_features
                  && right_node->_row_idx.size () > min_instances)
                nodes_to_process.push (right_node);
              else
                right_node->fit (X, input_parameters.alpha);
            }
          else
            {
              n->fit (X, input_parameters.alpha);
              if (verbose)
                {
                  std::cout << "no splitting" << std::endl;
                  std::cout.flush ();
                }
            }
        }
    }
}
