#!/bin/sh

adduser()
{
  USER=$1
  PASSWD=$2
  shift ; shift
  COMMENTS=$@
  useradd -c "${COMMENTS}" $USER
  if [ "$?" -ne "0" ]; then
    echo "Krijimi i perdoruesit deshtoi"
    return 1
  fi
  passwd $USER $PASSWD
  if [ "$?" -ne "0" ]; then
    echo "Vendosja e password deshtoi"
    return 2
  fi
  echo "U shtua perdoruesi $USER ($COMMENTS) me password $PASSWORD"
}

## scripti kryesor fillon ketu

adduser alice alice alice test per krijim perdoruesi
ADDUSER_RETURN_CODE=$?
if [ "$ADDUSER_RETURN_CODE" -eq "1" ]; then
  echo "Ndodhi nje gabim gjate krujimit te perdoruesit"
elif [ "$ADDUSER_RETURN_CODE" -eq "2" ]; then 
   echo "Ndhodhi nje gabim gjate vendsojes se passwordit"
else
  echo "Perdoruesi alice u shtua ne sistem."
fi
