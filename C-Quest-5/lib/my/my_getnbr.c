/*
** ETNA PROJECT, 2021
** Pointers and arrays
** File description:
** 		Exercise #1 of day #8 : displays a string letter by letter
*/

int my_getnbr(const char *str)
{
    int i = 0;
    int stop_loop = 0;
    int result = 0;
    int sign = 0;

    while (stop_loop != 1) {
	if (str[i] == 45) {
	    sign = 1;
	}
	else if (str[i] == 43) {
	    sign = 0;
	}
	else if (str[i] >= 48 && str[i] <= 57) {
	    if (result < 214748364 || ((result == 214748364) && (str[i] <= 55))) {
		result *= 10;
            	result += str[i] - 48;
	    } else {
		return 0;
	    }
	}
	else if (str[i] < 48 || str[i] > 57) {
	    if (sign == 0) {
		return result;
	    } else {
		return -result;
	    }
	} else {
	    return 1;
	}
	i++;
    }
    return 0;
}
