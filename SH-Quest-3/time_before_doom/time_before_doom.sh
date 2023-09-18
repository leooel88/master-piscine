#!/bin/bash
url=$1
long=$(cut -f 10 -d '"' <(curl -s "$1"))
lat=$(cut -f 14 -d '"' <(curl -s "$1"))
distance=$(cut -f 18 -d '"' <(curl -s "$1"))
speed=$(cut -f 22 -d '"' <(curl -s "$1"))

seconds=$(echo "scale=30; ("$distance"*1000)/"$speed |bc)

minutes=$(echo "scale=30; "$seconds"/60" |bc)

hours=$(echo "scale=30; "$minutes"/60" |bc)

days=$(echo "scale=30; "$hours"/24" |bc)
daysint=$(echo "scale=0; "$days"/1" |bc)

hours=$(echo "scales=30; ("$days"-"$daysint")*24" |bc)
hoursint=$(echo "scale=0; "$hours"/1" |bc)

minutes=$(echo "scales=30; ("$hours"-"$hoursint")*60" |bc)
minutesint=$(echo "scale=0; "$minutes"/1" |bc)

seconds=$(echo "scales=30; ("$minutes"-"$minutesint")*60" |bc)
secondsint=$(echo "scale=0; "$seconds"/1" |bc)

echo "The Angry Moon is located at lat: "$lat", lng: "$long"."
echo "It is "$distance"km away from us, but it is going to fall at a speed of "$speed"m/s."
echo "We have exactly "$daysint" days, "$hoursint" hours, "$minutesint" minutes and "$secondsint" seconds to react."
