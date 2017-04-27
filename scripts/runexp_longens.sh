#!/bin/bash                                                                                                                                            

mkdir -p exp/longensxcnet

# ensemble xcnet

./learnenscnet --problem=accidents --min-inst=300 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/accidents.log
./learnenscnet --problem=baudio --min-inst=500 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/baudio.log
./learnenscnet --problem=bnetflix --min-inst=300 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=2000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.2 --ensemble --k 1000 > exp/longensxcnet/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=1000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.5 --ensemble --k 1000 > exp/longensxcnet/cwekb.log
./learnenscnet --problem=dna --min-inst=300 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/dna.log
./learnenscnet --problem=kdd --min-inst=2000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.2 --ensemble --k 1000 > exp/longensxcnet/kdd.log
./learnenscnet --problem=msweb --min-inst=2000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/msweb.log
./learnenscnet --problem=plants --min-inst=300 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/plants.log
./learnenscnet --problem=tmovie --min-inst=1000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.2 --ensemble --k 1000 > exp/longensxcnet/tmovie.log
./learnenscnet --problem=ad --min-inst=1000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/ad.log
./learnenscnet --problem=bbc --min-inst=500 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/bbc.log
./learnenscnet --problem=book --min-inst=2000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/book.log
./learnenscnet --problem=cr52 --min-inst=2000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.2 --ensemble --k 1000 > exp/longensxcnet/cr52.log
./learnenscnet --problem=jester --min-inst=500 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.5 --ensemble --k 1000 > exp/longensxcnet/jester.log
./learnenscnet --problem=msnbc --min-inst=2000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/msnbc.log
./learnenscnet --problem=nltcs --min-inst=500 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.2 --ensemble --k 1000 > exp/longensxcnet/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=300 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/pumbs.log
./learnenscnet --problem=tretail --min-inst=2000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.2 --ensemble --k 1000 > exp/longensxcnet/tretail.log
./learnenscnet --problem=kosarek --min-inst=2000 --min-feat=4 --output-dir=exp/longensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1 --ensemble --k 1000 > exp/longensxcnet/kosarek.log

