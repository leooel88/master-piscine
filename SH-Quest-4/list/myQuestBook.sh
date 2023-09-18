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

first_line=0

while IFS=';' read -r id name description quest_type completion_state quest_giver date_of_start date_of_completion reward
do
	if [ $first_line -ne 0 ]
	then
		if [ ! -z "$id" ] && [ ! -z "$name" ] && [ ! -z "$quest_type" ] && [ ! -z "completion_state" ] && [ ! -z "$quest_giver" ] && [ ! -z "date_of_start" ]
		then
			echo "#"$id" "$name
		fi
	else
		first_line=1
	fi
done < $2
