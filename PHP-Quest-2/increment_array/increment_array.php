<?php
    function increment_array($tab, $incr)
    {
        if (!is_int($incr)) {
            echo "L'increment n'est pas un Int";
            return ;
        }
        $temp_tab = array();
        foreach($tab as $key => $val) {
            if (!is_int($val)) {
                echo "L'index " . ($key) . " n'est pas un Int";
                return ;
            }
            array_push($temp_tab, ($val + $incr));
        }
        return $temp_tab;
    }
?>