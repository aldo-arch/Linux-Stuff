#!/bin/bash

function checkroot(){

  if [[ $EUID -ne 0 ]]; then
   	echo "Youre not root!" 
   	exit 1
  else pass # or do something else  
  fi
}
