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

#ifndef _PARAMS
#define _PARAMS

#include <string>
#include <vector>
#include <iostream>

class params
{
 public:
  std::string problem_name;
  std::vector < int >min_instances;
  std::vector < int >min_features;
  int seed;
  std::vector < double >alpha;
  std::string out_path;
  std::string model;
  std::vector < int >option_length;
  bool ensemble;
  unsigned int max_components;

  friend std::ostream & operator<< (std::ostream & os, const params &);
};


class paramsexp
{
 public:
  std::string problem_name;
  int min_instances;
  int min_features;
  double alpha;
  std::string out_path;
  std::string model;
  std::vector < int >option_length;
  bool ensemble;
  int max_components;
};



#endif
