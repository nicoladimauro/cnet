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
#ifndef _UTILS
#define _UTILS

#include <vector>
#include <numeric>
#include <algorithm>

template<class T>
double mean(std::vector<T> v){
    return (double) std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

template<class T>
std::vector<double> log_sum_exp(std::vector<std::vector<T> > models_ll, std::vector<double> log_weight, int n){
	std::vector<double> lls;

	unsigned int lls_size = models_ll[0].size();
	lls.resize(lls_size, 0.0);

	for (int i=0; i<lls_size; i++){
		// log-sum-exp trick
		double maxLogVal = models_ll[0][i] + log_weight[0];
		for (int k=1; k< n; k++)
			if ( (models_ll[k][i] + log_weight[k]) > maxLogVal)
				maxLogVal = models_ll[k][i] + log_weight[k];
		double lse = 0.0;
		for (int k=0; k<n; k++)
			lse += exp(models_ll[k][i] + log_weight[k] - maxLogVal);
		lls[i] = maxLogVal + log(lse);
	}
	return lls;
}


template<class T>
double stdev(std::vector<T> v, double mean){
    
    if (v.size() == 1)
        return 0;
    double accum = 0.0;
    std::for_each (std::begin(v), std::end(v), [&](const double d) {
        accum += (d - mean) * (d - mean);
    });

    return sqrt(accum / (v.size()-1));
}

#endif
