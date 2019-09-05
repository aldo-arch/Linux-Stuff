#!/bin/bash
function maxnr () {
if [ ! -d "$1" -o $# = 0 ]  
then
echo "vendosni emrin e sakte te direktorise"
return 1
fi
max=0
for fn in $(/bin/ls $1)    
do
thisone=${#fn}
if [ $thisone -gt $max ]      
then
max=$thisone    
fi     
done 
echo "skedari me emrin me te gjate ka  $max karaktere."
}
###fillon ketu###
echo "fillimi i skriptit"
echo "shkruani nje direktori per te marre pergjigjen"
read dir
maxnr $dir
echo "fundi i skriptit"
