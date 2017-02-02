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

#include "cltree.h"
#include "dataset.h"

#define TREE_NODE 0
#define OR_NODE 1
#define OPTION_NODE 2

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
	int _scope_length;
	// std::weak_ptr used to break circular references of std::shared_ptr,
	// no memory leak
	std::weak_ptr < node > _parent;
	std::vector < int >_row_idx;
	int _depth;

	int get_id () const;
	node_type get_type () const;
	virtual std::vector < double >eval (dataset &) = 0;
	virtual std::vector < double >eval (dataset &, std::vector < int >&) = 0;
};

class tree_node:public node
{
	std::shared_ptr < cltree > _tree;
 public:
	tree_node (std::shared_ptr < cltree >);
	void fit (dataset &, double);
	std::vector < double >eval (dataset &);
	std::vector < double >eval (dataset &, std::vector < int >&);
};


class or_node:public node
{
 private:
	std::shared_ptr < node > _left_child;
	std::shared_ptr < node > _right_child;
	double _left_weight;
	double _right_weight;
	int _or_feature;
 public:
	int get_or_feature ();
	double get_left_weight ();
	double get_right_weight ();

	void set_left_child (const std::shared_ptr < node > &);
	void set_right_child (const std::shared_ptr < node >);
	std::shared_ptr < node > get_left_child ();
	std::shared_ptr < node > get_right_child ();
	or_node (std::shared_ptr < tree_node > &, std::shared_ptr < tree_node > &,
					 double, double, int);

	std::vector < double >eval (dataset &);
	std::vector < double >eval (dataset &, std::vector < int >&);
};


class option_node:public node
{
	std::vector < std::shared_ptr < or_node > >_children;
	std::vector < double >_weights;
 public:
	option_node ();
	option_node (std::vector < std::shared_ptr < or_node > >&,
							 std::vector < double >&);
	void push_back_child (const std::shared_ptr < or_node >);
	void push_back_weight (const double);
	std::shared_ptr < or_node > get_child (int);
	double get_weight (int);
	int n_children ();
	std::vector < double >eval (dataset &);
	std::vector < double >eval (dataset &, std::vector < int >&);
};


#endif
