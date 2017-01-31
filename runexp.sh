MIN_INST=200,500,1000,2000
ALPHA=0.1,0.2,0.5,1.0,2.0

# cnet

./learncnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA
./learncnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/cnet --model=cnet --alpha=$ALPHA

# xcnet

./learncnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA
./learncnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/xcnet --model=xcnet --alpha=$ALPHA


# optionxcnet

./learncnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA
./learncnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optionxcnet --model=optionxcnet --option-length=5,4,2 --alpha=$ALPHA

# ensemble xcnet

./learnenscnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/ensxcnet --model=xcnet --option-length=5,4,2 --alpha=$ALPHA --ensemble --k 40

# optioncnet

./learncnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 
./learncnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/optioncnet --model=optioncnet --option-length=5,4,2 --alpha=$ALPHA 


# ensemble cnet

./learnenscnet --problem=accidents --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=baudio --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=bnetflix --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=c20ng --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=cwebkb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=dna --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=kdd --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=msweb --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=plants --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=tmovie --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=ad --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=bbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=book --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=cr52 --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=jester --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=msnbc --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=nltcs --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=pumsb_star --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=tretail --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40
./learnenscnet --problem=kosarek --min-inst=$MIN_INST --min-feat=4 --output-dir=exp/enscnet --model=cnet  --alpha=$ALPHA --ensemble --k 40

