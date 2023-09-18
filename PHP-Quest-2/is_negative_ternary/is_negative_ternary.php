<?php
    function is_negative_ternary($n)
    {
        echo (!is_int($n)) ? ("Le parametre n'est pas un Int\n") : (($n < 0) ? ("True\n") : ("False\n"));
    }
?>