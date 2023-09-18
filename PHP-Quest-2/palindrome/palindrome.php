<?php
    function palindrome($string = "")
    {
        $string = preg_replace('/\s+/', '', trim($string));
        $string = strtolower($string);
        $length = strlen($string);

        for ($i = 0; $i < (int)($length/2); $i++) {
            if (strcmp(substr($string, $i, 1), substr($string, (-$i - 1), 1)) != 0) {
                echo "False\n";
                return ;
            }
        }
        echo "True\n";
    }
?>