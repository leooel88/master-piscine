#!/bin/bash
#fight_calcul.sh

#Fight infos
playerOption="$1"
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

if [[ "$playerOption" = "1" ]] ; then #Attaque
    playerDamages=$(echo "$playerStr*(-1)" | bc)
    damageToEnemie=$(echo "scale=0; $playerDamages*(-1)" | bc)
    source ./replace_str_characters.sh "$currentEnemieId" "$playerDamages" "0"
else
    if [[ "$playerOption" = "2" ]] ; then #Defense
        playerHeal=$(echo "$playerNormalHp/2" | bc)
	healedToPlayer="$playerHeal"
        source ./replace_str_characters.sh "1" "$playerHeal" "1"
    fi
fi

enemieDamages=$(echo "$enemieStr*(-1)" | bc)
damageToPlayer=$(echo "scale=0; $enemieDamages*(-1)" |bc)

damageToPlayer="$enemieStr"
source ./replace_str_characters.sh "1" "$enemieDamages" "1"
