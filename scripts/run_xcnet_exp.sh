#!/bin/bash                                                                                                                                            

# script for repoducing the results reported in the paper 

mkdir -p exp/

# grid on a single cnet with tree as leaf distribution
# ------------------------------------------------------------------------------------
mkdir -p exp/cnet
./learncnet --problem=accidents --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/accidents.log
./learncnet --problem=baudio --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/baudio.log
./learncnet --problem=bnetflix --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/cwekb.log
./learncnet --problem=dna --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/dna.log
./learncnet --problem=kdd --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0  > exp/cnet/kdd.log
./learncnet --problem=msweb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/msweb.log
./learncnet --problem=plants --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/plants.log
./learncnet --problem=tmovie --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/tmovie.log
./learncnet --problem=ad --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/ad.log
./learncnet --problem=bbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/bbc.log
./learncnet --problem=book --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/book.log
./learncnet --problem=cr52 --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/cr52.log
./learncnet --problem=jester --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/jester.log
./learncnet --problem=msnbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/msnbc.log
./learncnet --problem=nltcs --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/pumbs.log
./learncnet --problem=tretail --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/tretail.log
./learncnet --problem=kosarek --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/kosarek.log

# grid on a single xcnet with tree as leaf distribution
# ------------------------------------------------------------------------------------
mkdir -p exp/xcnet
./learncnet --problem=accidents --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/accidents.log
./learncnet --problem=baudio --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/baudio.log
./learncnet --problem=bnetflix --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/cwekb.log
./learncnet --problem=dna --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/dna.log
./learncnet --problem=kdd --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/kdd.log
./learncnet --problem=msweb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/msweb.log
./learncnet --problem=plants --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/plants.log
./learncnet --problem=tmovie --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/tmovie.log
./learncnet --problem=ad --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/ad.log
./learncnet --problem=bbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/bbc.log
./learncnet --problem=book --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/book.log
./learncnet --problem=cr52 --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/cr52.log
./learncnet --problem=jester --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/jester.log
./learncnet --problem=msnbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/msnbc.log
./learncnet --problem=nltcs --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/pumbs.log
./learncnet --problem=tretail --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/tretail.log
./learncnet --problem=kosarek --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/kosarek.log

# grid on a single cnet with pob as leaf distribution
# ------------------------------------------------------------------------------------
mkdir -p exp/cnet-pob
./learncnet --problem=accidents --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/accidents.log
./learncnet --problem=baudio --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/baudio.log
./learncnet --problem=bnetflix --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/bnetflix.log
./learncnet --problem=c20ng --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/c20ng.log
./learncnet --problem=cwebkb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/cwekb.log
./learncnet --problem=dna --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/dna.log
./learncnet --problem=kdd --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0  --leaf-distribution=bernoulli > exp/cnet-pob/kdd.log
./learncnet --problem=msweb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/msweb.log
./learncnet --problem=plants --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/plants.log
./learncnet --problem=tmovie --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/tmovie.log
./learncnet --problem=ad --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/ad.log
./learncnet --problem=bbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/bbc.log
./learncnet --problem=book --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/book.log
./learncnet --problem=cr52 --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/cr52.log
./learncnet --problem=jester --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/jester.log
./learncnet --problem=msnbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/msnbc.log
./learncnet --problem=nltcs --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/nltcs.log
./learncnet --problem=pumsb_star --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/pumbs.log
./learncnet --problem=tretail --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/tretail.log
./learncnet --problem=kosarek --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/cnet-pob --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/cnet-pob/kosarek.log

# grid on a single xcnet with pob as leaf distribution
# ------------------------------------------------------------------------------------
mkdir -p exp/xcnet-pob
./learncnet --problem=accidents --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/accidents.log
./learncnet --problem=baudio --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/baudio.log
./learncnet --problem=bnetflix --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/bnetflix.log
./learncnet --problem=c20ng --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/c20ng.log
./learncnet --problem=cwebkb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/cwekb.log
./learncnet --problem=dna --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/dna.log
./learncnet --problem=kdd --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/kdd.log
./learncnet --problem=msweb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/msweb.log
./learncnet --problem=plants --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/plants.log
./learncnet --problem=tmovie --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/tmovie.log
./learncnet --problem=ad --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/ad.log
./learncnet --problem=bbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/bbc.log
./learncnet --problem=book --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/book.log
./learncnet --problem=cr52 --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/cr52.log
./learncnet --problem=jester --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/jester.log
./learncnet --problem=msnbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/msnbc.log
./learncnet --problem=nltcs --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/nltcs.log
./learncnet --problem=pumsb_star --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/pumbs.log
./learncnet --problem=tretail --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/tretail.log
./learncnet --problem=kosarek --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/xcnet-pob --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 --leaf-distribution=bernoulli > exp/xcnet-pob/kosarek.log

# grid on an ensemble ot 40 models of cnet with tree as leaf distribution
# ------------------------------------------------------------------------------------
mkdir -p exp/enscnet
./learnenscnet --problem=accidents --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/accidents.log
./learnenscnet --problem=baudio --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/baudio.log
./learnenscnet --problem=bnetflix --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/cwekb.log
./learnenscnet --problem=dna --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/dna.log
./learnenscnet --problem=kdd --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/kdd.log
./learnenscnet --problem=msweb --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/msweb.log
./learnenscnet --problem=plants --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/plants.log
./learnenscnet --problem=tmovie --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/tmovie.log
./learnenscnet --problem=ad --min-inst=,10002000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/ad.log
./learnenscnet --problem=bbc --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/bbc.log
./learnenscnet --problem=book --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/book.log
./learnenscnet --problem=cr52 --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/cr52.log
./learnenscnet --problem=jester --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/jester.log
./learnenscnet --problem=msnbc --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/msnbc.log
./learnenscnet --problem=nltcs --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/pumbs.log
./learnenscnet --problem=tretail --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2 --ensemble --k 40 > exp/enscnet/tretail.log
./learnenscnet --problem=kosarek --min-inst=1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2  --ensemble --k 40 > exp/enscnet/kosarek.log

# grid on an ensemble ot 40 models of xcnet with tree as leaf distribution
# ------------------------------------------------------------------------------------
mkdir -p exp/ensxcnet
./learnenscnet --problem=accidents --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/accidents.log
./learnenscnet --problem=baudio --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/baudio.log
./learnenscnet --problem=bnetflix --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/cwekb.log
./learnenscnet --problem=dna --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/dna.log
./learnenscnet --problem=kdd --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/kdd.log
./learnenscnet --problem=msweb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/msweb.log
./learnenscnet --problem=plants --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/plants.log
./learnenscnet --problem=tmovie --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/tmovie.log
./learnenscnet --problem=ad --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/ad.log
./learnenscnet --problem=bbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/bbc.log
./learnenscnet --problem=book --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/book.log
./learnenscnet --problem=cr52 --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/cr52.log
./learnenscnet --problem=jester --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/jester.log
./learnenscnet --problem=msnbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/msnbc.log
./learnenscnet --problem=nltcs --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/pumbs.log
./learnenscnet --problem=tretail --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/tretail.log
./learnenscnet --problem=kosarek --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/kosarek.log

# grid on an ensemble ot 40 models of xcnet with pob as leaf distribution
# ------------------------------------------------------------------------------------
mkdir -p exp/ensxcnetb
./learnenscnet --problem=accidents --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/accidents.log
./learnenscnet --problem=baudio --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/baudio.log
./learnenscnet --problem=bnetflix --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/cwekb.log
./learnenscnet --problem=dna --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/dna.log
./learnenscnet --problem=kdd --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/kdd.log
./learnenscnet --problem=msweb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/msweb.log
./learnenscnet --problem=plants --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/plants.log
./learnenscnet --problem=tmovie --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/tmovie.log
./learnenscnet --problem=ad --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/ad.log
./learnenscnet --problem=bbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/bbc.log
./learnenscnet --problem=book --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/book.log
./learnenscnet --problem=cr52 --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/cr52.log
./learnenscnet --problem=jester --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/jester.log
./learnenscnet --problem=msnbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/msnbc.log
./learnenscnet --problem=nltcs --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/pumbs.log
./learnenscnet --problem=tretail --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/tretail.log
./learnenscnet --problem=kosarek --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnetb/kosarek.log

# grid on an ensemble ot 500 models of xcnet with tree as leaf distribution
# ------------------------------------------------------------------------------------
mkdir -p exp/ensxcnetbl
./learnenscnet --problem=accidents --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/accidents.log
./learnenscnet --problem=baudio --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/baudio.log
./learnenscnet --problem=bnetflix --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/cwekb.log
./learnenscnet --problem=dna --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/dna.log
./learnenscnet --problem=kdd --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/kdd.log
./learnenscnet --problem=msweb --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/msweb.log
./learnenscnet --problem=plants --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/plants.log
./learnenscnet --problem=tmovie --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/tmovie.log
./learnenscnet --problem=ad --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/ad.log
./learnenscnet --problem=bbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/bbc.log
./learnenscnet --problem=book --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/book.log
./learnenscnet --problem=cr52 --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/cr52.log
./learnenscnet --problem=jester --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/jester.log
./learnenscnet --problem=msnbc --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/msnbc.log
./learnenscnet --problem=nltcs --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/pumbs.log
./learnenscnet --problem=tretail --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/tretail.log
./learnenscnet --problem=kosarek --min-inst=300,500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnetbl --model=xcnet  --alpha=0.1 --ensemble --k 500 > exp/ensxcnetbl/kosarek.log



