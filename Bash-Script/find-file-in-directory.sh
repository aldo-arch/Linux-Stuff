#!/bin/bash

if [ $# -ne 2 ]; then
   echo "Usage: file drectory"
   exit 1
fi

match=$1 #fileName
directory=$2
found=0  #set to 1 if file found in the for loop


if [ ! -d "$directory" ]; then
   echo "Kjo  nuk eshte nje direktori e sakte"
   echo "Kerkimi do kryhet ne direktorine aktuale"
   directory="*"
fi

# Try to find file in /etc
for f in $directory
do
  
  if [ $f == "$match" ]; then
     echo "$match file found!"
     found=1 # file found
     break   # break the for looo
  fi
done

# noop file not found
if [ $found -ne 1 ]; then
    echo "$match file nuk u gjet "
fi
