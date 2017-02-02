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
#ifndef _CLTREE
#define _CLTREE

#include <cmath>
#include <limits>
#include <iostream>
#include <vector>
#include <cassert>

#include "dataset.h"
#include "globals.h"
#include <rarray>

void minumum_spanning_tree (rarray < double, 2 > &, int n, int *);

class cltree
{
	rarray < double, 2 > _log_probs;
	rarray < double, 4 > _log_j_probs;
	rarray < double, 3 > _log_factors;
	int _n_vars;
	int *_tree;
	bool _fitted;
	void compute_log_probs (dataset &, double);
	void compute_log_probs (dataset & X, std::vector < int >&,
													std::vector < int >&, int, double);
public:
		cltree ();
		std::vector < double >eval (dataset &);
		std::vector < double >eval (dataset &, std::vector < int >&,
																std::vector < int >&);
	void fit (dataset &, double);
	void fit (dataset &, int, std::vector < int >&, std::vector < int >&, int,
						double);
	 ~cltree ();
};


#endif
