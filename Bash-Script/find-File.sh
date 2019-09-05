#!/bin/bash

usage(){
	echo "Perdorimi: findFile emer_file"
	exit 1
}
 
# funksioni is_file_exits
# $f -> mban argumentin qe i kaloi scriptit
is_file_exits(){
	local f="$1"
	if [[ -f "$f" ]]; then
	 return 0 
	else
	 return 1
	fi
}

# therritet usage() nqs emri i skedarit nuk vendoset
if [[ $# -eq 0 ]]; then
 usage
fi 

# therritet is_file_exits
if ( is_file_exits "$1" )
then
 echo "Skedari u gjet"
else  
 echo "Skedari nuk u gjet"
fi
