#!/bin/bash

read -p "Enter an integer: " int1
if (( $int1 == 0 ))
then
    echo "Zero"
elif (( $int1 < 0 ))
then
    echo "Negative"
else
    if (( $((int1%2)) == 0 ))
    then
        echo "Even"
    else
        echo "Odd"
    fi
fi
