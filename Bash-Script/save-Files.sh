#! /bin/bash
echo "Saving files in current directory in file savethem."
exec > $$savethem
for i in *
do
if [ $i == $$savethem ]
        then
        continue
fi
echo "==========================================================="
echo "File: $i"
echo "==========================================================="
cat "$i"
done
