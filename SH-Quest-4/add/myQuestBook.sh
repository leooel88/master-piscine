#!/bin/bash

if [ ! -n $1 ]
then
        exit
else
        if [ $1 != "--list" ] && [ $1 != "--info" ] && [ $1 != "--add" ]
        then
                echo "The option doesn't exist"
		exit
	fi

	if [ $1 = "--info" ]
	then
		if [ ! -n $2 ]
		then
			echo "No index given"
			exit
		fi
		if [ ! -n $3 ]
		then
			echo "No file given"
			exit
		fi
	fi

	if [ $1 = "--list" ]
	then
		if [ ! -n $2 ]
		then
			echo "No file given"
			exit
		fi
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
done < $file.csv

if [ $none -eq 1 ]
then
	echo "None"
fi
}

###### countDays ######

countDays() {

firstDateY=$(cut -f 1 -d "-"<$1)
firstDateM=$(cut -f 2 -d "-"<$1)
firstDateM=$(echo ${#string})
firstDateD=$(cut -f 3 -d "-"<$1)
firstDateD=$(echo ${#string})

secondDateY=$(cut -f 1 -d "-"<$1)
secondDateM=$(cut -f 2 -d "-"<$1)
secondDateM=$(echo ${#string})
secondDateD=$(cut -f 3 -d "-"<$1)
secondDateD=$(echo ${#string})

let result=($(date +%s -d $firstDateY$firstDateM$firstDateD$)-$(date +%s -d $secondDateY$secondDateM$secondDateD))/86400
echo $result
}



###### MAIN ######

if [ $1 = "--list" ]
then
	printCompleted "0"
	printCompleted "1"
	printCompleted "2"
fi

if [ $1 = "--info" ]
then
	printInfo "$2" "$3"
fi

if [ $1 = "--add" ]
then

	name=""
	description=""
	type=""
	completion=""
	giver=""
	start_date=""
	end_date=""
	reward=""

	nbArg=$#
	count=1
	countInc=2
	while [ $count -lt $nbArg ]
	do
		if [ "${!count}" = "-name" ]
		then
			name=${!countInc}
		fi

		if [ "${!count}" = "-desc" ]
		then
			description=${!countInc}
		fi

		if [ "${!count}" = "-type" ]
		then
			type=${!countInc}
		fi

		if [ "${!count}" = "-completion" ]
                then
                        completion=${!countInc}
                fi

		if [ "${!count}" = "-giver" ]
                then
                        giver=${!countInc}
                fi

		if [ "${!count}" = "-start_date" ]
                then
                        start_date=${!countInc}
                fi

		if [ "${!count}" = "-end_date" ]
                then
                        end_date=${!countInc}
                fi

		if [ "${!count}" = "-reward" ]
                then
                        reward=${!countInc}
                fi

		count=$((count+1))
		countInc=$((countInc+1))
	done

	lastId=0

	while IFS=';' read -r t1 t2 t3 t4 t5 t6 t7 t8
	do
		lastId=$((lastId+1))
	done < ${!#}

	if [ ! -z "$name" ] && [ ! -z "$giver" ] && [ ! -z "$type" ] && [ ! -z "$completion" ] && [ ! -z "$start_date" ]
	then
		echo $lastId";"$name";"$description";"$type";"$completion";"$giver";"$start_date";"$end_date";"$reward >>questbook_data.csv
	fi
fi
