#!/bin/bash

cd
ls -l
read -p "Enter a file name: " filename
if [ -e $filename ]
then
    echo "file exists!"
    if [ -r $filename ]
    then
         status="readable "
    fi
    if [ -w $filename ]
    then
         status=$status"writable "
    fi
    if [ -x $filename ]
    then
         status=$status"executable"
    fi
     echo "file permission: "$status
else
    echo "file does not exist"
fi
