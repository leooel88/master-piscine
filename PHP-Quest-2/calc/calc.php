<?php
    function calc($op = "+", $nbr = 0)
    {
        $last = getenv('LAST_VAL_CALC');
        switch($op) {
            case "+":
                $last = $last + $nbr;
                break;
            case "-":
                $last = $last - $nbr;
                break;
            case "*":
                $last = $last * $nbr;
                break;
            case "/":
                if ($nbr == 0) {
                    echo "Division by 0!\n";
                } else {
                    $last = $last / $nbr;
                }
                break;
            case "%":
                if ($nbr == 0) {
                    echo "Division by 0!\n";
                } else {
                    $last = $last % $nbr;
                }
                break;
            case "=":
                $last = $nbr;
                break;
        }
        putenv('LAST_VAL_CALC='.$last);
        return $last;
    }
?>