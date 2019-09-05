#!/bin/bash

read fn 
while [ "$fn" != "" ] 
do 
   basename "$fn"
   read fn 
done
