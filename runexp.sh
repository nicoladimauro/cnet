#!/bin/bash                                                                                                                                            

mkdir -p exp/
mkdir -p exp/cnet
mkdir -p exp/xcnet
mkdir -p exp/optionxcnet
mkdir -p exp/ensxcnet
mkdir -p exp/optioncnet
mkdir -p exp/enscnet

# cnet

./learncnet --problem=accidents --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/accidents.log
./learncnet --problem=baudio --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/baudio.log
./learncnet --problem=bnetflix --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/cwekb.log
./learncnet --problem=dna --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/dna.log
./learncnet --problem=kdd --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0  > exp/cnet/kdd.log
./learncnet --problem=msweb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/msweb.log
./learncnet --problem=plants --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/plants.log
./learncnet --problem=tmovie --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/tmovie.log
./learncnet --problem=ad --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/ad.log
./learncnet --problem=bbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/bbc.log
./learncnet --problem=book --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/book.log
./learncnet --problem=cr52 --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/cr52.log
./learncnet --problem=jester --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/jester.log
./learncnet --problem=msnbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/msnbc.log
./learncnet --problem=nltcs --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/pumbs.log
./learncnet --problem=tretail --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/tretail.log
./learncnet --problem=kosarek --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/cnet/kosarek.log

# xcnet

./learncnet --problem=accidents --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/accidents.log
./learncnet --problem=baudio --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/baudio.log
./learncnet --problem=bnetflix --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/cwekb.log
./learncnet --problem=dna --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/dna.log
./learncnet --problem=kdd --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/kdd.log
./learncnet --problem=msweb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/msweb.log
./learncnet --problem=plants --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/plants.log
./learncnet --problem=tmovie --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/tmovie.log
./learncnet --problem=ad --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/ad.log
./learncnet --problem=bbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/bbc.log
./learncnet --problem=book --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/book.log
./learncnet --problem=cr52 --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/cr52.log
./learncnet --problem=jester --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/jester.log
./learncnet --problem=msnbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/msnbc.log
./learncnet --problem=nltcs --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/pumbs.log
./learncnet --problem=tretail --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/tretail.log
./learncnet --problem=kosarek --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=0.1,0.2,0.5,1.0,2.0 > exp/xcnet/kosarek.log


# optionxcnet

./learncnet --problem=accidents --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/accidents.log
./learncnet --problem=baudio --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/baudio.log
./learncnet --problem=bnetflix --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/cwekb.log
./learncnet --problem=dna --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/dna.log
./learncnet --problem=kdd --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/kdd.log
./learncnet --problem=msweb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/msweb.log
./learncnet --problem=plants --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/plants.log
./learncnet --problem=tmovie --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/tmovie.log
./learncnet --problem=ad --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/ad.log
./learncnet --problem=bbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/bbc.log
./learncnet --problem=book --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/book.log
./learncnet --problem=cr52 --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/cr52.log
./learncnet --problem=jester --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/jester.log
./learncnet --problem=msnbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/msnbc.log
./learncnet --problem=nltcs --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/pumbs.log
./learncnet --problem=tretail --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/tretail.log
./learncnet --problem=kosarek --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optionxcnet/kosarek.log

# ensemble xcnet

./learnenscnet --problem=accidents --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/accidents.log
./learnenscnet --problem=baudio --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/baudio.log
./learnenscnet --problem=bnetflix --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/cwekb.log
./learnenscnet --problem=dna --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/dna.log
./learnenscnet --problem=kdd --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/kdd.log
./learnenscnet --problem=msweb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/msweb.log
./learnenscnet --problem=plants --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/plants.log
./learnenscnet --problem=tmovie --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/tmovie.log
./learnenscnet --problem=ad --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/ad.log
./learnenscnet --problem=bbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/bbc.log
./learnenscnet --problem=book --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/book.log
./learnenscnet --problem=cr52 --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/cr52.log
./learnenscnet --problem=jester --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/jester.log
./learnenscnet --problem=msnbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/msnbc.log
./learnenscnet --problem=nltcs --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/pumbs.log
./learnenscnet --problem=tretail --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/tretail.log
./learnenscnet --problem=kosarek --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/ensxcnet/kosarek.log

# optioncnet

./learncnet --problem=accidents --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0 > exp/optioncnet/accidents.log
./learncnet --problem=baudio --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/baudio.log
./learncnet --problem=bnetflix --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/cwekb.log
./learncnet --problem=dna --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/dna.log
./learncnet --problem=kdd --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/kdd.log
./learncnet --problem=msweb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/msweb.log
./learncnet --problem=plants --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/plants.log
./learncnet --problem=tmovie --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/tmovie.log
./learncnet --problem=ad --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/ad.log
./learncnet --problem=bbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/bbc.log
./learncnet --problem=book --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/book.log
./learncnet --problem=cr52 --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/cr52.log
./learncnet --problem=jester --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/jester.log
./learncnet --problem=msnbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/msnbc.log
./learncnet --problem=nltcs --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/pumbs.log
./learncnet --problem=tretail --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/tretail.log
./learncnet --problem=kosarek --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=0.1,0.2,0.5,1.0,2.0  > exp/optioncnet/kosarek.log


# ensemble cnet

./learnenscnet --problem=accidents --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/accidents.log
./learnenscnet --problem=baudio --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/baudio.log
./learnenscnet --problem=bnetflix --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/cwekb.log
./learnenscnet --problem=dna --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/dna.log
./learnenscnet --problem=kdd --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/kdd.log
./learnenscnet --problem=msweb --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/msweb.log
./learnenscnet --problem=plants --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/plants.log
./learnenscnet --problem=tmovie --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/tmovie.log
./learnenscnet --problem=ad --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/ad.log
./learnenscnet --problem=bbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/bbc.log
./learnenscnet --problem=book --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/book.log
./learnenscnet --problem=cr52 --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/cr52.log
./learnenscnet --problem=jester --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/jester.log
./learnenscnet --problem=msnbc --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/msnbc.log
./learnenscnet --problem=nltcs --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/pumbs.log
./learnenscnet --problem=tretail --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0 --ensemble --k 40 > exp/enscnet/tretail.log
./learnenscnet --problem=kosarek --min-inst=500,1000,2000 --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=0.1,0.2,0.5,1.0,2.0  --ensemble --k 40 > exp/enscnet/kosarek.log

