#!/bin/bash
# gloabal x and y
x=200
y=100
 
math(){
  # local variable x and y with passed args	
  local x=$1
  y=$2
  echo $(( $x + $y ))
}
 
echo "x: $x and y: $y"
# call function 
 
echo "Calling math() with x: $x and y: $y"
math 5 10
 

echo "x: $x and y: $y after calling math()"
echo $(( $x + $y ))
