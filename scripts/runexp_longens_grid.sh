#!/bin/bash                                                                                                                                            

mkdir -p exp/longensxcnetgridt
mkdir -p exp/longensxcnetgridb

# ensemble xcnet

./learnenscnet --problem=accidents --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/accidents.log
./learnenscnet --problem=baudio --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/baudio.log
./learnenscnet --problem=bnetflix --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/cwekb.log
./learnenscnet --problem=dna --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/dna.log
./learnenscnet --problem=kdd --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/kdd.log
./learnenscnet --problem=msweb --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/msweb.log
./learnenscnet --problem=plants --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/plants.log
./learnenscnet --problem=tmovie --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/tmovie.log
./learnenscnet --problem=ad --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/ad.log
./learnenscnet --problem=bbc --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/bbc.log
./learnenscnet --problem=book --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/book.log
./learnenscnet --problem=cr52 --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/cr52.log
./learnenscnet --problem=jester --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/jester.log
./learnenscnet --problem=msnbc --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/msnbc.log
./learnenscnet --problem=nltcs --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/pumbs.log
./learnenscnet --problem=tretail --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/tretail.log
./learnenscnet --problem=kosarek --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridt --model=xcnet --leaf-distribution=cltree --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridt/kosarek.log

# ensemble bernoulli

./learnenscnet --problem=accidents --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/accidents.log
./learnenscnet --problem=baudio --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/baudio.log
./learnenscnet --problem=bnetflix --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/cwekb.log
./learnenscnet --problem=dna --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/dna.log
./learnenscnet --problem=kdd --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/kdd.log
./learnenscnet --problem=msweb --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/msweb.log
./learnenscnet --problem=plants --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/plants.log
./learnenscnet --problem=tmovie --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/tmovie.log
./learnenscnet --problem=ad --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/ad.log
./learnenscnet --problem=bbc --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/bbc.log
./learnenscnet --problem=book --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/book.log
./learnenscnet --problem=cr52 --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/cr52.log
./learnenscnet --problem=jester --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/jester.log
./learnenscnet --problem=msnbc --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/msnbc.log
./learnenscnet --problem=nltcs --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/pumbs.log
./learnenscnet --problem=tretail --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/tretail.log
./learnenscnet --problem=kosarek --min-inst=100,300,500 --min-feat=4 --output-dir=exp/longensxcnetgridb --model=xcnet --leaf-distribution=bernoulli --alpha=0.1 --ensemble --k 1000 > exp/longensxcnetgridb/kosarek.log

