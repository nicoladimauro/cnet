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

#include "dataset.h"

// FUNCTIONS

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    int i=0;
    while (getline(ss, item, delim)) {
        elems[i] = item;
        i++;
    }
}

int splits(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    int i=0;
    while (getline(ss, item, delim)) {
        i++;
    }
    return i;
}


dataset::dataset(const std::string file_name){
	std::ifstream data_file;
	std::string line;

    
    std::cout << "Loading data: ";
    
    int rows = 0, cols = 0;
    
	data_file.open(file_name);

    SOFT_ASSERT(data_file, " error: " + file_name + " not found!");

    while (getline(data_file, line)){
        if (line.length())
            rows++;
        if (rows == 1)
            cols = splits(line,',');
    }
    data_file.close();
	

    std::cout << rows << " and " << cols << " cols" << std::endl;
    data.resize(rows);
    for (int i=0; i<rows; i++)
        data[i].resize(cols);

	int r = 0;
    std::vector<std::string> tokens;
    tokens.resize(cols);
    data_file.open(file_name);
	if (data_file){
		while (getline(data_file, line))
			if (line.length()){
				split(line,',', tokens);
				for(unsigned int i = 0; i < tokens.size(); i++)
                    data[r][i] = atoi(tokens[i].c_str());
                r++;
			}
		data_file.close();
	}

	shape[0] = data.size();
	shape[1] = data[0].size();

	sparsity = 0;
    for (int i=0; i<shape[0]; i++){
        std::vector<int> example;
		for (int j=0; j<shape[1]; j++)
			if (data[i][j] != 0){
				example.push_back(j);
				sparsity++;
			}
        lil_data.push_back(example);
    }
	sparsity /= shape[0]*shape[1];
}

