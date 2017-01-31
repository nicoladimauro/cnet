MIN_INST=200,500,1000,2000
ALPHA=0.1,0.2,0.5,1.0,2.0

# cnet

./learncnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/accidents.log
./learncnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/baudio.log
./learncnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/cwekb.log
./learncnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/dna.log
./learncnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA  > exp/cnet/kdd.log
./learncnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/msweb.log
./learncnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/plants.log
./learncnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/tmovie.log
./learncnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/ad.log
./learncnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/bbc.log
./learncnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/book.log
./learncnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/cr52.log
./learncnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/jester.log
./learncnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/msnbc.log
./learncnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/pumbs.log
./learncnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/tretail.log
./learncnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA > exp/cnet/kosarek.log

# xcnet

./learncnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/accidents.log
./learncnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/baudio.log
./learncnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/cwekb.log
./learncnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/dna.log
./learncnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/kdd.log
./learncnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/msweb.log
./learncnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/plants.log
./learncnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/tmovie.log
./learncnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/ad.log
./learncnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/bbc.log
./learncnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/book.log
./learncnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/cr52.log
./learncnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/jester.log
./learncnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/msnbc.log
./learncnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/pumbs.log
./learncnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/tretail.log
./learncnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA > exp/xcnet/kosarek.log


# optionxcnet

./learncnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/accidents.log
./learncnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/baudio.log
./learncnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/cwekb.log
./learncnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/dna.log
./learncnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/kdd.log
./learncnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/msweb.log
./learncnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/plants.log
./learncnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/tmovie.log
./learncnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/ad.log
./learncnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/bbc.log
./learncnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/book.log
./learncnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/cr52.log
./learncnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/jester.log
./learncnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/msnbc.log
./learncnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/pumbs.log
./learncnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/tretail.log
./learncnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA > exp/optionxcnet/kosarek.log

# ensemble xcnet

./learnenscnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/accidents.log
./learnenscnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/baudio.log
./learnenscnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/cwekb.log
./learnenscnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/dna.log
./learnenscnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/kdd.log
./learnenscnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/msweb.log
./learnenscnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/plants.log
./learnenscnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/tmovie.log
./learnenscnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/ad.log
./learnenscnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/bbc.log
./learnenscnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/book.log
./learnenscnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/cr52.log
./learnenscnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/jester.log
./learnenscnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/msnbc.log
./learnenscnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/pumbs.log
./learnenscnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/tretail.log
./learnenscnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40 > exp/ensxcnet/kosarek.log

# optioncnet

./learncnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA > exp/optioncnet/accidents.log
./learncnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/baudio.log
./learncnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/bnetflix.log
./learncnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/c20ng.log
./learncnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/cwekb.log
./learncnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/dna.log
./learncnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/kdd.log
./learncnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/msweb.log
./learncnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/plants.log
./learncnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/tmovie.log
./learncnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/ad.log
./learncnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/bbc.log
./learncnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/book.log
./learncnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/cr52.log
./learncnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/jester.log
./learncnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/msnbc.log
./learncnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/nltcs.log
./learncnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/pumbs.log
./learncnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/tretail.log
./learncnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA  > exp/optioncnet/kosarek.log


# ensemble cnet

./learnenscnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/accidents.log
./learnenscnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/baudio.log
./learnenscnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/bnetflix.log
./learnenscnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/c20ng.log
./learnenscnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/cwekb.log
./learnenscnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/dna.log
./learnenscnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/kdd.log
./learnenscnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/msweb.log
./learnenscnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/plants.log
./learnenscnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/tmovie.log
./learnenscnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/ad.log
./learnenscnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/bbc.log
./learnenscnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/book.log
./learnenscnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/cr52.log
./learnenscnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/jester.log
./learnenscnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/msnbc.log
./learnenscnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/nltcs.log
./learnenscnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/pumbs.log
./learnenscnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/tretail.log
./learnenscnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40 > exp/enscnet/kosarek.log

