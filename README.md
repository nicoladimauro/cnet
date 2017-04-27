# cnet: Cutset Networks implementation in C++

Cutset Networks have been introduced as weighted probabilistic model trees having tree-structured models as the leaves
of an OR tree. They exploit context-specific independencies by embedding Pearl’s conditioning algorithm. 

## Download and Compile

```
git clone --recursive https://github.com/nicoladimauro/cnet.git
cd cnet
cmake . -DCMAKE_BUILD_TYPE=Debug
make
```

## Usage

### Learn Cutset Netowrk

```
Usage: cnet [OPTIONS]...

  -h, --help                    Print help and exit
  -V, --version                 Print version and exit
      --problem=STRING          Input problem name
      --min-inst=INT            Minimum number of instances for a slice
                                  (default=`500')
      --min-feat=INT            Minimum number of features for a slice
                                  (default=`4')
      --alpha=DOUBLE            Pseudocounts for the smoothing  (default=`1')
      --output-dir=STRING       Output dir path  (default=`exp')
      --model=STRING            The model to use  (possible values="cnet",
                                  "xcnet", default=`cnet')
      --leaf-distribution=STRING
                                Distribution for the leaf node  (possible
                                  values="cltree", "bernoulli",
                                  "mix-bernoulli" default=`cltree')
      --kbm=INT                 The number of ensemble components for bernoulli
                                  mixture  (default=`5')
      --seed=INT                Seed for the random generator  (default=`117')
      --verbose                 Verbosity flag  (default=off)
```

#### Example

```
./learncnet --problem=accidents --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 
```
### Learn Ensembles of Cutset Netowrk

```
Usage: cnet [OPTIONS]...

  -h, --help                    Print help and exit
  -V, --version                 Print version and exit
      --problem=STRING          Input problem name
      --min-inst=INT            Minimum number of instances for a slice
                                  (default=`500')
      --min-feat=INT            Minimum number of features for a slice
                                  (default=`4')
      --alpha=DOUBLE            Pseudocounts for the smoothing  (default=`1')
      --output-dir=STRING       Output dir path  (default=`exp')
      --model=STRING            The model to use  (possible values="cnet",
                                  "xcnet", default=`cnet')
      --ensemble                Whether to build an ensemble model
                                  (default=off)
      --k=INT                   The number of ensemble components
                                  (default=`5')
      --leaf-distribution=STRING
                                Distribution for the leaf node  (possible
                                  values="cltree", "bernoulli",
                                  "mix-bernoulli" default=`cltree')
      --kbm=INT                 The number of ensemble components for bernoulli
                                  mixture  (default=`5')
      --seed=INT                Seed for the random generator  (default=`117')
      --verbose                 Verbosity flag  (default=off)
```

#### Example
```
./learnenscnet --problem=accidents --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 
```

## License

The MIT License
