#! /bin/bash

if [[ $1 == -d? ]]
	then
		del=$(echo $1 | cut -b3)
		shift
	else
		del=:
fi
IFS=$del
set $*
for i
	do
	echo $i
done
