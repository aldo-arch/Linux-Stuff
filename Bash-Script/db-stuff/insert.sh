 #! /bin/bash
insvar="insert into Persona values ('65','Emer','Mbiemer','email.yahoo.com','0668924818','44','Femer')"
#********************************************
# lidhemi me databazen 
# dhe ekzekutojme query nga scripti
#********************************************

/usr/bin/mysql -u root << eof
use shop;
$insvar
eof

#fundi i skriptit
