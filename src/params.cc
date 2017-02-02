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

#include "params.h"

std::ostream & operator<< (std::ostream & os, const params & pars)
{
  os << "[Parameters --" <<
    "problem:" << pars.problem_name << " min_instances:";
  for (int i = 0; i < pars.min_instances.size (); i++)
    os << pars.min_instances[i] << " ";
  os << " min_features:";
  for (int i = 0; i < pars.min_features.size (); i++)
    os << pars.min_features[i] << " ";
  os << " alpha:";
  for (int i = 0; i < pars.alpha.size (); i++)
    os << pars.alpha[i] << " ";
  os << " model:" << pars.model;
  os << " option_length:";
  for (int i = 0; i < pars.option_length.size (); i++)
    os << pars.option_length[i] << " ";
  os << " ensemble:" << pars.ensemble <<
    " k:" << pars.max_components <<
    " seed:" << pars.seed << " out_dir:" << pars.out_path << " ]\n";

  return os;
}
