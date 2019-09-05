#!/bin/bash
echo "vendosni emrin e direktorise per te afishuar nendirektorite e saj"
read dir
if [ ! -d "$1" -o $# = 0 ]  
then
echo "##########################"
fi
veprim0=$(cd "$dir";ls -d */)
if [ -d "$dir" ]
then
echo "listojme vetem nendirektorite e $dir"
echo "$veprim0"
fi
