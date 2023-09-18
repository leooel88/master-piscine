#!/bin/bash

###### Pick rarity ######
pickRarity() {
    chosenRarity=$((1 + $RANDOM % 100))
    if [[ $chosenRarity -le 50 ]] ; then
	chosenRarity=1
    else
	if [[ $chosenRarity -le 80 ]] ; then
	    chosenRarity=2
	else
	    if [[ $chosenRarity -le 95 ]] ; then
	        chosenRarity=3
	    else
	        if [[ $chosenRarity -le 99 ]] ; then
	            chosenRarity=4
	        else
	            if [[ $chosenRarity -le 100 ]] ; then
	                chosenRarity=5
	            fi
	        fi
	    fi
	fi
    fi
    echo "$chosenRarity"
}

player=0
boss=0
enemie=0

tempRarity="$(pickRarity)"

#Set first line
echo "id,name,hp,mp,str,int,def,res,spd,luck,race,class,rarity" >../data_files/environment.csv

#Set player
first_line=0
while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do 
    if [[ $first_line -ne 0 ]] ; then
	if [[ "$id" = "$tempRarity" ]] ; then
	    echo "1,"$name","$hp","$mp","$str","$int","$def","$res","$spd","$luck","$race","$class","$rarity >>../data_files/environment.csv
	fi
    else
	first_line=$(($first_line+1))
    fi
done < ../data_files/players.csv

#Set enemies
count=2

while [[ $count -lt 11 ]] ; do
    tempRarity="$(pickRarity)"
    nbEnemiesRarity=0
    first_line=0
    while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
	if [[ $first_line -ne 0 ]] ; then
	    if [[ "$rarity" = "$tempRarity" ]] ; then
		nbEnemiesRarity=$(($nbEnemiesRarity+1))
	    fi
	else
	    first_line=$(($first_line+1))
	fi
    done < ../data_files/enemies.csv
    chosenEnemieId=$((1 + $RANDOM % $nbEnemiesRarity))
    first_line=0
    countEnemiesRarity=1
    while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
	if [[ $first_line -ne 0 ]] ; then
	    if [[ "$rarity" = "$tempRarity" ]] && [[ "$chosenEnemieId" = "$countEnemiesRarity" ]] ; then
		echo $count","$name","$hp","$mp","$str","$int","$def","$res","$spd","$luck","$race","$class","$rarity >>../data_files/environment.csv
		break
	    else
		if [ "$rarity" = "$tempRarity" ]
		then
		    countEnemiesRarity=$(($countEnemiesRarity+1))
		fi
	    fi
	else
	    first_line=$(($first_line+1))
	fi
    done < ../data_files/enemies.csv
    count=$(($count+1))
done

#Set boss

tempRarity="$(pickRarity)"
nbBossesRarity=0
first_line=0
while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
    if [[ $first_line -ne 0 ]] ; then
        if [[ "$rarity" = "$tempRarity" ]] ; then
            nbBossesRarity=$(($nbBossesRarity+1))
        fi
    else
        first_line=$(($first_line+1))
    fi
done < ../data_files/bosses.csv

chosenBossId=$((1 + $RANDOM % $nbBossesRarity))
first_line=0
countBossesRarity=1
while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
    if [[ $first_line -ne 0 ]] ; then
        if [[ "$rarity" = "$tempRarity" ]] && [[ "$chosenBossId" = "$countBossesRarity" ]] ; then
            echo "11,"$name","$hp","$mp","$str","$int","$def","$res","$spd","$luck","$race","$class","$rarity >>../data_files/environment.csv
            break
        else
            if [[ "$rarity" = "$tempRarity" ]] ; then
                countBossesRarity=$(($countBossesRarity+1))
            fi
        fi
    else
        first_line=$(($first_line+1))
    fi
done < ../data_files/bosses.csv
