#!/bin/bash
#main.sh

currentEnemieId=2
currentFightId=1
optionChoosen=0
damageToEnemie=0
damageToPlayer=0
healedToPlayer=0
playerChooseOption=0
optionChoosen=0
bossDefeated=0

source ./lore.sh
source ./fighting_set.sh
while [[ 1 ]] ; do
    source ./fighting_player_display.sh "$currentFightId" "$currentEnemieId"
    source ./fighting_player_options.sh
    source ./fighting_bilan.sh
done
