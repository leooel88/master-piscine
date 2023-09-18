#!/bin/bash

if [ ! -n $1 ]
then
        exit
else
        if [ $1 != "--list" ]
        then
                exit
        fi
fi

file=$2

###### PRINT COMPLETED ######
printCompleted() {

if [ $1 = "0" ]
then
	echo "=== Ongoing ==="
fi

if [ $1 = "1" ]
then
	echo "=== Completed ==="
fi

if [ $1 = "2" ]
then
	echo "=== Failed ==="
fi

first_line=0
none=1

while IFS=';' read -r id name description quest_type completion_state quest_giver date_of_start date_of_completion reward
do
        if [ $first_line -ne 0 ]
        then
		if [ ! -z "$id" ] && [ ! -z "$name" ] && [ ! -z "$quest_type" ] && [ ! -z "$completion_state" ] && [ ! -z "$quest_giver" ] && [ ! -z "$date_of_start" ]
               	then
                       	if [ $completion_state = $1 ]
			then
				echo "#"$id" "$name
				if [ $none -eq 1 ]
				then
					none=0
				fi
			fi
  		fi
	else
              	first_line=1
	fi
done < $file

if [ $none -eq 1 ]
then
	echo "None"
fi
}

###### MAIN ######

printCompleted "0"
printCompleted "1"
printCompleted "2"
