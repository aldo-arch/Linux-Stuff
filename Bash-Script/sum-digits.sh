#!/bin/bash

echo -n "Enter number : "
read n

if [ $n -eq $n 2>/dev/null ]
then
     echo "$inputi eshte integer"
else
    echo "$input nuk eshte integer"
    exit 1
fi 

# store single digit
sd=0
 
# store number of digit 
sum=0
 
# while per te gjetur shumen e shifrave
while [ $n -gt 0 ]
do
    ((sd=n % 10)) # mbetja
    ((n=n / 10))  # shifra tjeter
    ((sum=sum + sd)) # shuma
done
echo  "Shuma eshte $sum"
