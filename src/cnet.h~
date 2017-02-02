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

#ifndef _CNET
#define _CNET

#include <iostream>
#include <queue>
#include <memory>
#include <map>
#include <random>
#include <algorithm>
#include <iomanip>      // std::setprecision

#include "dataset.h"
#include "cltree.h"
#include "nodes.h"
#include "params.h"
#include "utils.h"
#include "globals.h"

class cnet{
 public:
	cnet();
	virtual void fit(dataset &X, paramsexp &);
	virtual std::vector<double> eval(dataset &X);
	int _n_or_nodes = 0;
	int _n_tree_nodes = 0;
	int _n_option_nodes = 0;
	int _max_depth = 0;
	double _mean_depth = 0.0;
	void compute_stats();
	bool is_pdf();
 protected:
	std::shared_ptr<node> _root;
	bool make_or_node(dataset& , std::shared_ptr<tree_node>, double, double&, double&, std::shared_ptr<tree_node>&, std::shared_ptr<tree_node>&, double);
};

class xcnet : public cnet {
public:
	void fit(dataset &X, paramsexp &);
protected:
    bool make_or_node(dataset&, std::shared_ptr<tree_node> n, std::shared_ptr<tree_node> &, std::shared_ptr<tree_node> &, double);

};

class optioncnet : public cnet {
public:
    void fit(dataset &X, paramsexp &);
protected:
    bool make_option_node(dataset&, std::shared_ptr<tree_node>, int, std::vector<std::shared_ptr<tree_node> > &, std::vector<std::shared_ptr<tree_node> > &,
    std::vector<double>&,std::vector<double>&, double);
};

class optionxcnet : public xcnet {
public:
    void fit(dataset &X, paramsexp &);
protected:
    bool make_option_node(dataset&, std::shared_ptr<tree_node>, int, std::vector<std::shared_ptr<tree_node> > &, std::vector<std::shared_ptr<tree_node> > &,
    std::vector<double>&,std::vector<double>&, double);
};

#endif
