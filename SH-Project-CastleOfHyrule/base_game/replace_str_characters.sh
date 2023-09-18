#!/bin/bash
#replace_str_characters.sh

line=$1
i=0

while IFS=',' read -r id name hp mp str int def res spd luck race class rarity ; do
      if [[ $i -eq $line ]] ; then
          search_str="$id,$name,$hp,$mp,$str,$int,$def,$res,$spd,$luck,$race,$class,$rarity"
          save_id="$id"
          save_name="$name"
          save_hp="$hp"
          save_mp="$mp"
          save_str="$str"
          save_int="$int"
          save_def="$def"
          save_res="$res"
          save_spd="$spd"
          save_luck="$luck"
          save_race="$race"
          save_class="$class"
          save_rarity="$rarity"
      fi
      i=$(($i+1))
done < ../data_files/environment.csv

modif_hp=$2
modif_mp=0
modif_str=0
modif_int=0
modif_def=0
modif_res=0
modif_spd=0
modif_luck=0

new_hp=$(($save_hp+$modif_hp))
new_mp=$(($save_mp+$modif_mp))
new_str=$(($save_str+$modif_str))
new_int=$(($save_int+$modif_int))
new_def=$(($save_def+$modif_def))
new_res=$(($save_res+$modif_res))
new_spd=$(($save_spd+$modif_spd))
new_luck=$(($save_luck+$modif_luck))

if [[ $new_hp -gt $playerNormalHp && $3 -eq 1 ]] ; then
    new_hp=$playerNormalHp
fi

replace_str=""$save_id","$save_name","$new_hp","$new_mp","$new_str","$new_int","$new_def","$new_res","$new_spd","$new_luck","$save_race","$save_class","$save_rarity""

if [[ $search_str != "" && $replace_str != "" ]] ; then
    sed -i "s/$search_str/$replace_str/i" ../data_files/environment.csv
fi
