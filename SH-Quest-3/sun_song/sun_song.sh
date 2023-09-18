#!/bin/bash
sunrise=$(cut -c 35-44 <(curl -s "https://api.sunrise-sunset.org/json?lat=48.813875&lng=2.392521&callback=mycallback"))
sunset=$(cut -c 57-66 <(curl -s "https://api.sunrise-sunset.org/json?lat=48.813875&lng=2.392521&callback=mycallback"))
echo "Sunrise is expected at" $sunrise "and sunset at" $sunset"."
