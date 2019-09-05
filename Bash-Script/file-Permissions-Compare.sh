#! /bin/bash
echo "Enter the name of first file: "
read file1
echo "Enter the name of second file: "
read file2
fp1=`ls -l $file1|cut -c 2-10`
fp2=`ls -l $file2|cut -c 2-10`

if [ $fp1 = $fp2 ]
then
echo "Files $file1 and $file2 have same permission $fp1"
else
echo "Permission of first file $file1:"
echo $fp1
echo "Permission of second file $file2:"
echo $fp2
fi
