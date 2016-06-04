#! /bin/bash
ls ./logs/ > list.txt
while read line
do
echo $line
./tool $line
#mv ./tools/$line ../results/
done < list.txt
