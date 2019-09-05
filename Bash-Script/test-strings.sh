#!/bin/bash

read -p "First String: " str1
read -p "Second String: " str2
if [ -z "$str1" ]
then
    echo "The 1st string is null"
elif [ -z "$str2" ]
then
    echo "The 2nd string is null"
else
    if [ $str1 == $str2 ]
    then
         echo "The strings are equal"
    else
        echo "The strings are not equal"
    fi
fi
