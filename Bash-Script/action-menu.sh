#!/bin/bash

read -p "Integer1: " int1
read -p "Integer2: " int2
echo "======================"
printf "Menu: \n[a] Addition\n[b]Subtraction\n[c]Multiplication\n[d]Division\n"
echo "======================"
read -p "Zgjidhni nje vlere: " choice
res=0
case $choice in
a)
    ((res=int1+int2))
;;
b)
    ((res=int1-int2))
;;
c)
    ((res=int1*int2))
;;
d)
    ((res=int1/int2))
;;
*)
    echo "Invalid input"
esac
echo "The result is: " $res
