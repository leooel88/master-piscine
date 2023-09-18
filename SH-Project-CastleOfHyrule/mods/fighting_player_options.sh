#!/bin/bash

playerChooseOption=0

while [[ $playerChooseOption -eq 0 ]] ; do
    echo -e "\n\n============================================= ${BOLD}OPTIONS${NC} ========================================"
    echo -e "\n\n"
    echo -e "                +==============+                             +=============+"
    echo -e "                ||            ||                             ||           ||"
    echo -e "                || ${BOLD}ATTACK - 1${NC} ||                             || ${BOLD}HEAL  - 2${NC} ||"
    echo -e "                ||            ||                             ||           ||"
    echo -e "                +==============+                             +=============+"
    echo -e "\n\n"
    read -p "What do you want to do $playerName ?" optionChoosen
    if [[ $optionChoosen = "1" ]] ; then
        source ./fight_calcul.sh "$optionChoosen" "$currentEnemieId"
        playerChooseOption=1
    elif [[ $optionChoosen = "2" ]] ; then
        source ./fight_calcul.sh "$optionChoosen" "$currentEnemieId"
        playerChooseOption=1
    else
        echo -e "\nDid you read correctly ?\n"
        echo -e "You have to choose an option to face against your destiny !\n"
    fi
done
