#!/bin/bash
declare -i result=0
declare -i a=$1
if [ $a -lt 10 ]
then
    a=10
else 
    a+=1
fi
while [ $a -lt $2 ]
do
    if [ $a -ge 100 ]
    then
        break
    fi
    result+=1
    if [ $a = 42 ]
    then 
	result+=1
    fi
    a+=1
done
echo $result
