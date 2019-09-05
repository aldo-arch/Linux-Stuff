#!/bin/bash

# funksionet
ok() { echo -e '\e[32m'$1'\e[m'; } # e gjelber

EXPECTED_ARGS=3
E_BADARGS=65
MYSQL=`which mysql`
 
Q1="CREATE DATABASE IF NOT EXISTS $1;"
Q2="GRANT ALL ON *.* TO '$2'@'localhost' IDENTIFIED BY '$3';"
Q3="FLUSH PRIVILEGES;"
SQL="${Q1}${Q2}${Q3}"
 
if [ $# -ne $EXPECTED_ARGS ]
then
  echo "Perdorimi: $0 emer_databaze_e_re emer_perdoruesi_i_ri fjalekalim"
  exit $E_BADARGS
fi
 
$MYSQL -uroot -p -e "$SQL"

ok "Databaza $1 dhe perdoruesi $2 u krijuan me password-in $3"
