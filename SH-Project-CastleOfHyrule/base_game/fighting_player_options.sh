#!/bin/bash

playerChooseOption=0

while [[ $playerChooseOption -eq 0 ]] ; do
    echo "---OPTIONS-----------"
    echo "1. Attack   2. Heal"
    read -p "" optionChoosen
    if [[ $optionChoosen -eq 1 ]] ; then
        source ./fight_calcul.sh "$optionChoosen" "$currentEnemieId"
        playerChooseOption=1
    elif [[ $optionChoosen -eq 2 ]] ; then
        source ./fight_calcul.sh "$optionChoosen" "$currentEnemieId"
        playerChooseOption=1
    else
        echo -e "\nDid you read correctly ?\n"
        echo -e "You have to choose an option to face against your destiny !\n"
    fi
done
