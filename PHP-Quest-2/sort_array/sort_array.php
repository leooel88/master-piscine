<?php
    function insert_in_sorted_array($tab, $nbr) {
        $flag = 0;
        $temp_tab = array();
        foreach($tab as $key => $val) {
            if ($flag == 0 && $val > $nbr) {
                array_push($temp_tab, $nbr);
                $flag = 1;
            }
            array_push($temp_tab, $val);
        }
        if ($flag == 0) {
            array_push($temp_tab, $nbr);
        }
        return $temp_tab;
    }
    function sort_array($tab)
    {
        $temp_tab = array();
        foreach($tab as $key => $val) {
            $temp_tab = insert_in_sorted_array($temp_tab, $val);
        }
        return $temp_tab;
    }
?>