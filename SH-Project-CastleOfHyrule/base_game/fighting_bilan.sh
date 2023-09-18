#!/bin/bash
#fight.sh

revive=0
playerName=""
playerHp=""
enemieName=""
enemieHp=""
first_line=0

while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
    if [[ $first_line -ne 0 ]] ; then
        if [[ "$id" = "1" ]] ; then
            playerName="$name"
            playerHp="$hp"
        fi
    else
        first_line=$(($first_line+1))
    fi
    
done < ../data_files/environment.csv

first_line=0

while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
    if [[ $first_line -ne 0 ]] ; then
        if [[ "$id" = "$currentEnemieId" ]] ; then
            enemieName="$name"
            enemieHp="$hp"
        fi
    else
        first_line=$(($first_line+1))
    fi
done < ../data_files/environment.csv

if [[ $playerHp -le 0 ]] ; then
    echo -e "\nCongrats $playerName you reached hell, now You have a second life to spend here !\n"
    echo -e "Do you prefer to suffer[0], fight again[1] or try again[2]?"
    read -p "" revive
    if [[ $revive -eq 0 ]] ; then
        echo -e "\n"
        read -t 3 -p "Well, well, well, we finally met again"
        echo -e "\n\n"
        read -t 3 -p "$playerName turned around, he see Golden Ganon, a terrible enemy."
        echo -e "\n"
        read -t 4 -p "$playerName will never see a sunrise ever."
        exit 0
    elif [[ $revive -eq 1 ]] ; then
        echo -e "\n"
        read -t 3 -p "Hylia arrived as soon as you called her."
        echo -e "\n\n"
        read -t 3 -p "You'll have a second chance to recue the princess $playerName."
        source ./replace_str_characters "1" "100" "1"
    elif [[ $revive -eq 2 ]] ; then
        echo -e "\n"
        read -t 3 -p "So you choose to abandon yours ?"
        echo -e "\n"
        read -t 3 -p "Well, that's why I doesn't trust anyone..."
        echo -e "\n"
        read -t 3 -p "Alright, I give you this chance."
        echo -e "\t\t===================================================\n\n"
        echo -e "\n\n\n\n\n\n\n"
        echo -e "\t\t===================================================\n\n"
        source hyrule_castle.sh
        exit 0
    fi
elif [[ $currentEnemieId -eq 11 && $enemieHp -le 0 ]] ; then
    echo -e "\n\t\t\t\t===================================================\n\n"
    echo -e "\n\n\t\tCongratulations $playerName !!\n\n\t"
    read -t 2 -p "You defeated $enemieName and save the lands around their plunder !"
    echo -e "\n"
    read -t 6 -p "Thank you $playerName. But our princess is in another castle!"
    echo -e "\n\n\n"
    read -t 6 -p "Hylia see ur frustrated face, she looked at you and whispered something in your ears."
    echo -e "\n\n"
    read -t 9 -p "The others turned and saw the face of $playerName light up."
    echo -e "\n\n"
    read -t 5 -p "$playerName got up and climbed on the stone in front of them."
    echo -e "\n\n\n"
    read -t 6 -p "- My very dear friends"
    echo -e "\n"
    read -t 3 -p "On the way to a new adventure !"
    echo -e "\n\n\n\n\n\n\t\t\t==============THANKS FOR PLAYING===============\n"
    echo -e "\n\n\n\tMade by ETNA M1 students\n"
    echo -e "\t\t ---RESSAYRE Leo---\n"
    echo -e "\t\t---GOUALIER Sacha---\n"
    read -t 9 -p ""
    read -t 9 -p ""
    read -t 9 -p ""
    read -t 9 -p ""
    read -t 9 -p ""
    read -t 9 -p ""
    echo -e "\n\n\n\tWaw you stayed a long time !\n\n"
    echo -e "Here is a cafe to help you hold"
    source ../.senseo.sh
    exit 0
elif [[ $enemieHp -le 0 ]] ; then
    currentFightId=$(($currentFightId+1))
    currentEnemieId=$(($currentEnemieId+1))
    ext=""
    if [[ $currentFightId -eq 2 ]] ; then
        ext="nd"
    elif [[ $currentFightId -eq 3 ]] ; then
        ext="rd"
    elif [[ $currentFightId -ge 4 ]] ; then
        ext="th"
    fi
    echo -e "\n$enemieName died!\n\t\t"
    read -n 1 -r -s -p "=== Press any key to climb the "$currentFightId""$ext" floor==="
    echo -e "\n\n"
else
    if [[ $optionChoosen -eq 1 ]] ; then
        echo -e "\nYou attacked and dealt "$damageToEnemie" damages!\n"
    elif [[ $optionChoosen -eq 2 ]] ; then
        echo -e "\nYou drink a fresh water and recover your vitality\n"
    else
        echo -e "\n$enemieName attacked and dealt "$damageToPlayer" damages!\n"
        return
    fi
fi
