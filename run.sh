#! /bin/bash
# Remove the list test file if exist
rm list.txt
echo "Writing the log file names to list.txt file..."
sleep 2 
ls ./logs/ > list.txt
echo "Done.."
rm tool
echo "Emptying the results directory..."
sleep 2
rm ./results/*
echo "Done.."
gcc tool.c -o tool
sleep 1 
while read line
do
echo $line
./tool $line
done < list.txt
sleep 1 
echo "Done...Log files created in results directory.."
