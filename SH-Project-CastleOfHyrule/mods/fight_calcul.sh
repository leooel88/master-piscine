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
while IFS=',' read -r id name hp mp str int def res spd luck race class rarity
do
        if [ $first_line -ne 0 ]
        then
                if [ "$id" = "$currentEnemieId" ]
                then
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

if [ "$currentEnemieId" != "11" ]
then
        first_line=0
        while IFS=',' read -r id name hp mp str int def res spd luck race class rarity
        do
                if [ $first_line -ne 0 ]
                then
                        if [ "$name" = "$enemieName" ]
                        then
                                enemieNormalHp="$hp"
                        fi
                else
                        first_line=$(($first_line+1))
                fi

        done < ../data_files/enemies.csv
else
        first_line=0
        while IFS=',' read -r id name hp mp str int def res spd luck race class rarity
        do
                if [ $first_line -ne 0 ]
                then
                        if [ "$name" = "$enemieName" ]
                        then
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
while IFS=',' read -r id name hp mp str int def res spd luck race class rarity
do
        if [ $first_line -ne 0 ]
        then
                if [ "$id" = "1" ]
                then
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
while IFS=',' read -r id name hp mp str int def res spd luck race class rarity
do
        if [ $first_line -ne 0 ]
        then
                if [ "$name" = "$playerName" ]
                then
                        playerNormalHp="$hp"
                fi
        else
                first_line=$(($first_line+1))
        fi

done < ../data_files/players.csv



if [ "$playerSpd" -ge "$enemieSpd" ]
then
	if [ "$playerOption" = "1" ] #Attaque
	then
		percentDef=$(echo "scale=2; $enemieDef/100" | bc)
		playerDamages=$(echo "scale=2; $playerStr - $playerStr*$percentDef" | bc)
		playerDamages2=$(echo "scale=2; $playerStr - $playerStr*$percentDef" | bc)

		playerDamages=$(echo "scale=0; -$playerDamages/1" |bc)
		damageToEnemie=$(echo "scale=0; $playerDamages2/1" | bc)

		source ./replace_str_characters.sh "$currentEnemieId" "$playerDamages" "0"
	else
		if [ "$playerOption" = "2" ] #Defense
		then
			playerHeal=$(echo "$playerNormalHp/2" | bc)
			healedToPlayer="$playerHeal"
			source ./replace_str_characters.sh "1" "$playerHeal" "1"
		fi
	fi

	dodgeProb=$(echo "$playerSpd - $enemieSpd" | bc)
        dodgeRand=$((1 + $RANDOM % 100))

        if [ "$dodgeRand" -gt "$dodgeProb" ]
        then
		percentDef=$(echo "scale=2; $playerDef/100" | bc)
                enemieDamages=$(echo "scale=2; $enemieStr - $enemieStr*$percentDef" | bc)
		enemieDamages2=$(echo "scale=2; $enemieStr - $enemieStr*$percentDef" | bc)

		enemieDamages=$(echo "scale=0; -$enemieDamages/1" |bc)
		damageToPlayer=$(echo "scale=0; $enemieDamages2/1" |bc)

		damageToPlayer="$enemieStr"
		source ./replace_str_characters.sh "1" "$enemieDamages" "1"
	else
		echo "Great! You are very fast! You dodged the enemie's attack!"
		damageToPlayer=0
	fi
else
		percentDef=$(echo "scale=2; $playerDef/100" | bc)
                enemieDamages=$(echo "scale=2; $enemieStr - $enemieStr*$percentDef" | bc)
		enemieDamages2=$(echo "scale=2; $enemieStr - $enemieStr*$percentDef" | bc)


		enemieDamages=$(echo "scale=0; -$enemieDamages/1" |bc)
		damageToPlayer=$(echo "scale=0; $enemieDamages2/1" |bc)

                source ./replace_str_characters.sh "1" "$enemieDamages" "0"

	if [ "$playerOption" = "1" ] #Attaque
        then
		dodgeProb=$(echo "$enemieSpd - $playerSpd" | bc)
		dodgeRand=$((1 + $RANDOM % 100))

		if [ "$dodgeRand" -gt "$dodgeProb" ]
                then
			percentDef=$(echo "scale=2; $enemieDef/100" | bc)
                	playerDamages=$(echo "scale=2; $playerStr - $playerStr*$percentDef" | bc)
			playerDamages2=$(echo "scale=2; $playerStr - $playerStr*$percentDef" | bc)


			playerDamages=$(echo "scale=0; -$playerDamages/1" |bc)
			damageToEnemie=$(echo "scale=0; $playerDamages2/1" |bc)

                	source ./replace_str_characters.sh "$currentEnemieId" "$playerDamages" "0"
		else
			echo "Oops! The enemie is too fast! He dodged your attack.."
			damageToEnemie=0
		fi
	else
        	if [ "$playerOption" = "2" ] #Defense
        	then
                	playerHeal=$(echo "$playerNormalHp/2" | bc)
                	healedToPlayer="$playerHeal"
                	source ./replace_str_characters.sh "1" "$playerHeal" "1"
        	fi
	fi
fi
