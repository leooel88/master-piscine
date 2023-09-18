<?php
    function check_word_char($char)
    {
        $ascii_val = ord($char);
        if (($ascii_val < 48 || $ascii_val > 57) && ($ascii_val < 65 || $ascii_val > 90) && ($ascii_val < 97 || $ascii_val > 122)) {
            return 0;
        } else {
            return 1;
        }
    }

    function add_word_to_tab($string, $tab)
    {
        // echo "String : " . $string . "\n";
        $flag = 0;
        $temp_tab = array();

        foreach($tab as $key => $val) {
            if (strcmp(array_key_first($val), $string) > 0) {
                if ($flag == 0) {
                    array_push($temp_tab, [$string => 1]);
                }
                $flag = 1;
                array_push($temp_tab, [array_key_first($val) => $val[array_key_first($val)]]);
            }
            elseif (strcmp(array_key_first($val), $string) == 0) {
                array_push($temp_tab, [array_key_first($val) => $val[array_key_first($val)] + 1]);
                $flag = 1;
            } else {
                array_push($temp_tab, [array_key_first($val) => $val[array_key_first($val)]]);
            }
        }
        if ($flag == 0) {
            array_push($temp_tab, [$string => 1]);
        }
        return $temp_tab;
    }

    function print_tab($tab) {
        $i = 0;
        foreach($tab as $key => $val) {
            echo array_key_first($val) . " => " . $val[array_key_first($val)] . "\n";
        }
    }

    if (!isset($argv[0]) || !isset($argv[1])) {
        return ;
    }

    if (is_dir($argv[1])) {
        echo $argv[1] . ": FILE: Is a directory\n";
        return ;
    }
    if (!file_exists($argv[1])) {
        echo $argv[1] . ": FILE: No such file or directory\n";
        return ;
    }
    if (!is_readable($argv[1])) {
        echo $argv[1] . ": FILE: Permission denied\n";
        return ;
    }
    if (!fopen($argv[1], "r")) {
        echo $argv[1] . ": FILE: Cannot open file\n";
        return ;
    }

    $total_string = fread(fopen($argv[1], "r"), filesize($argv[1]));
    $length = filesize($argv[1]);
    $start_word = 0;
    $current_word = "";
    $word_tab = array();
    $in_word = 0;

    while ($start_word < $length) {
        $current_letter = substr($total_string, $start_word, 1);
        if (check_word_char($current_letter)) {
            $in_word = 1;
            $current_word = $current_word . $current_letter;
        } else {
            if ($in_word == 1) {
                $word_tab = add_word_to_tab($current_word, $word_tab);
                $current_word = "";
                $in_word = 0;
            }
        }
        $start_word++;
    }
    print_tab($word_tab);
?>