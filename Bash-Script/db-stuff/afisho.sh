#! /bin/bash

#**************************
# shkruajme nje query sql
#**************************

qry="select * from Persona"

#********************************************
# lidhemi me databazen 
# dhe ekzekutojme query nga scripti
#********************************************

/usr/bin/mysql -u root << eof
use shop;
$qry
eof

#fundi i skriptit
