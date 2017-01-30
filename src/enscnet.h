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

#ifndef _ENSCNET
#define _ENSCNET

#include <iostream>
#include <memory>
#include <random>

#include "dataset.h"
#include "params.h"
#include "globals.h"

class ensemble{
 public:
	virtual void fit(dataset &, paramsexp &) = 0;
	virtual std::vector<double> eval(dataset &) = 0;
};

template<class M>
class enscnet : public ensemble{
private:
    std::vector<std::shared_ptr<M> > _models;
    std::vector<double> _weights;
    int _n_models;
public:
    enscnet(int);
    void fit(dataset &, paramsexp &);
    std::vector<double> eval(dataset &);
};

template<class M>
enscnet<M>::enscnet(int n_models){
    _n_models = n_models;
    for (int i=0; i<n_models; i++){
        _models.push_back(std::make_shared<M>(M()));
        _weights.push_back((double) 1 / n_models);
    }
}

template<class M>
void enscnet<M>::fit(dataset& X, paramsexp &input_parameters){
    for (int i=0; i<_n_models; i++){
        _models[i]->fit(X, input_parameters);
    }
}

template<>
void enscnet<cnet>::fit(dataset& X, paramsexp &input_parameters){
    for (int i=0; i<_n_models; i++){
        dataset bootstrap;
    
        bootstrap.shape[0] = X.shape[0];
        bootstrap.shape[1] = X.shape[1];
        bootstrap.sparsity = X.sparsity;
        
        for (int k=0; k<X.shape[0]; k++){
            std::uniform_int_distribution<int> distribution(0, X.shape[0]-1);
            int selected = distribution(random_generator);
            
            bootstrap.data.push_back(X.data[selected]);
            bootstrap.lil_data.push_back(X.lil_data[selected]);
        }
        _models[i]->fit(bootstrap, input_parameters);
    }
}

template<>
void enscnet<optioncnet>::fit(dataset& X, paramsexp &input_parameters){
    for (int i=0; i<_n_models; i++){
        dataset bootstrap;
    
        bootstrap.shape[0] = X.shape[0];
        bootstrap.shape[1] = X.shape[1];
        bootstrap.sparsity = X.sparsity;
        
        for (int k=0; k<X.shape[0]; k++){
            std::uniform_int_distribution<int> distribution(0, X.shape[0]-1);
            int selected = distribution(random_generator);
            
            bootstrap.data.push_back(X.data[selected]);
            bootstrap.lil_data.push_back(X.lil_data[selected]);
        }
        _models[i]->fit(bootstrap, input_parameters);
    }
}

template<class M>
std::vector<double> enscnet<M>::eval(dataset& X){
    std::vector<double> lls;
    lls.resize(X.shape[0], 0.0);

    std::vector<std::vector<double> > modelsLL;
    for (int i=0; i<_n_models; i++)
        modelsLL.push_back(_models[i]->eval(X));

    std::vector<double> logWeights;
    for (int i=0; i<_n_models; i++)
        logWeights.push_back(log(_weights[i]));

    for (int i=0; i<X.shape[0]; i++){
    
        // log-sum-exp trick
        modelsLL[0][i] += logWeights[0];
        double maxLogVal = modelsLL[0][i];
        for (int k=1; k<_n_models; k++){
            modelsLL[k][i] += logWeights[k];
            if ( modelsLL[k][i] > maxLogVal)
                maxLogVal = modelsLL[k][i];
        }
        double lse = 0.0;
        for (int k=0; k<_n_models; k++)
            lse += exp(modelsLL[k][i] - maxLogVal);
        lls[i] = maxLogVal + log(lse);
    }
    return lls;

}


#endif