<?php
    function is_negative($n)
    {
        if (!is_int($n)) {
            echo "Le parametre n'est pas un Int\n";
        }
        elseif ($n < 0) {
            echo "True\n";
        }
        else {
            echo "False\n";
        }
    }
?>