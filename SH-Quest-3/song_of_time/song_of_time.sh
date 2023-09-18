#!/bin/bash
weekday=$(date +%A)
date=$(date +%d/%m/%Y)
hour=$(date +%H:%M)
printf "Today is %s %s and it is %s.\n" $weekday $date $hour
