#!/bin/bash

#Fight infos
fightNb="$1"
currentEnemieId="$2"

#Enemie infos
enemieName=""
enemieHp=""
enemieMp=""
enemieStr=""
enemieInt=""
enemieDef=""
enemieRes=""
enemieSpd=""
enemieLuck=""
enemieRace=""
enemieClass=""
enemieRarity=""

first_line=0
while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
    if [[ $first_line -ne 0 ]] ; then
	if [[ "$id" = "$currentEnemieId" ]] ; then
	    enemieName="$name"
	    enemieHp="$hp"
	    enemieMp="$mp"
	    enemieStr="$str"
	    enemieInt="$int"
	    enemieDef="$def"
	    enemieRes="$res"
	    enemieSpd="$spd"
	    enemieLuck="$luck"
	    enemieRace="$race"
	    enemieClass="$class"
	    enemieRarity="$rarity"
	fi
    else
	first_line=$(($first_line+1))
    fi
    
done < ../data_files/environment.csv

#Enemie normal HP
enemieNormalHp=""

if [[ "$currentEnemieId" != "11" ]] ; then
    first_line=0
    while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
	if [[ $first_line -ne 0 ]] ; then
	    if [[ "$name" = "$enemieName" ]] ; then
	        enemieNormalHp="$hp"
	    fi
	else
	    first_line=$(($first_line+1))
	fi
        
    done < ../data_files/enemies.csv
else
    first_line=0
    while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
        if [[ $first_line -ne 0 ]] ; then
            if [[ "$name" = "$enemieName" ]] ; then
                enemieNormalHp="$hp"
            fi
        else
            first_line=$(($first_line+1))
        fi
        
    done < ../data_files/bosses.csv
fi
#Player infos
playerName=""
playerHp=""
playerMp=""
playerStr=""
playerInt=""
playerDef=""
playerRes=""
playerSpd=""
playerLuck=""
playerRace=""
playerClass=""
playerRarity=""

first_line=0
while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
    if [[ $first_line -ne 0 ]] ; then
        if [[ "$id" = "1" ]] ; then
            playerName="$name"
            playerHp="$hp"
            playerMp="$mp"
            playerStr="$str"
            playerInt="$int"
            playerDef="$def"
            playerRes="$res"
            playerSpd="$spd"
            playerLuck="$luck"
            playerRace="$race"
            playerClass="$class"
            playerRarity="$rarity"
        fi
    else
        first_line=$(($first_line+1))
    fi
done < ../data_files/environment.csv

#Player normal HP
playerNormalHp=""

first_line=0
while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
    if [[ $first_line -ne 0 ]] ; then
        if [[ "$name" = "$playerName" ]] ; then
            playerNormalHp="$hp"
        fi
    else
        first_line=$(($first_line+1))
    fi
done < ../data_files/players.csv

#Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo "========== FIGHT "$fightNb" =========="
echo ""
printf "${RED}$enemieName${NC} \n"
echo ""
printf "${NC}HP: "

echo "enemieHp :"$enemieHp
count=0

while [[ "$count" -lt "$enemieNormalHp" ]] ; do
    if [[ "$count" -lt "$enemieHp" ]] ; then
	printf "I"
    else
	printf " "
    fi
    count=$(($count+1))
done

printf " "$enemieHp"/"$enemieNormalHp"\n"
echo ""
printf "${GREEN}$playerName${NC} \n"
printf "${NC}HP: "

count=0

while [[ "$count" -lt "$playerNormalHp" ]] ; do
    if [[ "$count" -lt "$playerHp" ]] ; then
        printf "I"
    else
        printf " "
    fi
    count=$(($count+1))
done

printf " "$playerHp"/"$playerNormalHp"\n"
echo ""
