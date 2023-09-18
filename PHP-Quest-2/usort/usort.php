<?php
    function is_longer($string1, $string2)
    {
        if (strlen($string1) > strlen($string2)) {
            return 1;
        } else {
            return 0;
        }
    }

    function is_alphabetically_superior($string1, $string2)
    {
        if (strcmp($string1, $string2) > 0) {
            return 1;
        }
        if (strcmp($string1, $string2) == 0) {
            return 0;
        } else {
            return -1;
        }
    }

    function insert_word($tab, $string)
    {
        $flag = 0;
        $temp_tab = array();

        foreach($tab as $key => $val) {
            if ($flag == 0) {
                if (is_longer($string, $val) >= 0) {
                    if (is_longer($string, $val) == 0) {
                        array_push($temp_tab, $string);
                        $flag = 1;
                    } else {
                        if (is_alphabetically_superior($string, $val) == 1) {
                            array_push($temp_tab, $string);
                            $flag = 1;
                        }
                    }
                }
            }
            array_push($temp_tab, $val);
        }
        if ($flag == 0) {
            array_push($temp_tab, $string);
        }
        return $temp_tab;
    }

    function print_tab($tab)
    {
        foreach($tab as $key => $val) {
            echo $val . "\n";
        }
    }

    $word_tab = array();

    for ($i = 1; $i < $argc; $i++) {
        $word_tab = insert_word($word_tab, $argv[$i]);
    }

    print_tab($word_tab);

?>