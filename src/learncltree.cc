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

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <getopt.h>
#include <chrono>

#include "cltree.h"
#include "dataset.h"
#include "utils.h"


int
main (int argc, char **argv)
{


	// setting default values
	char *data_file_name = NULL;
	int min_instances = 100;
	int min_features = 4;

	int iarg = 0;

	while (iarg != -1)
		{
			iarg = getopt (argc, argv, "hi:d:s:");
			switch (iarg)
				{
				case 'h':
					break;

				case 'i':
					data_file_name = optarg;
					break;

				case 'd':
					min_instances = atoi (optarg);
					break;

				case 's':
					min_features = atoi (optarg);
					break;
				}
		}

	if (data_file_name == NULL)
		{
			std::cout << "The dataset name is required!" << std::endl;
			return 0;
		}

	// print options
	std::cout << "Parameters -- data:" << data_file_name << " min_instances:" <<
		min_instances << " min_features:" << min_features << std::endl;

	// loading data


	dataset train_data (data_file_name);
	std::cout << "Loaded " << train_data.
		shape[0] << " instances on " << train_data.
		shape[1] << " variables, sparsity: " << train_data.sparsity << std::endl;

	cltree C;
	auto t1 = std::chrono::high_resolution_clock::now ();
	C.fit (train_data, 1);
	std::cout << "Training ll: " << mean (C.eval (train_data)) << std::endl;
	auto t2 = std::chrono::high_resolution_clock::now ();
	std::cout << "Elapsed time: "
						<< std::chrono::duration_cast < std::chrono::seconds > (t2 - t1).count ()
						<< " seconds, "
						<< std::chrono::duration_cast < std::chrono::milliseconds >
		(t2 - t1).count () << " milliseconds\n";

}
