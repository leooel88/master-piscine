/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #10 of day #9 : capitalizes the first letter of each word
*/

char *my_strlowcase(char *str);
char *my_strupcase(char *str);

char *my_strcapitalize(char *str)
{
    int i = 0;
    int world_till_here = 0;

    while (str[i] != '\n') {
	if (world_till_here == 1 && str[i] != ' ' && str[i] != '+' && str[i] != '-') {
	    str[i] = *my_strlowcase(&str[i]);
	}
	else if (world_till_here == 1 && (str[i] == ' ' || str[i] == '+' || str[i] == '-')) {
	    world_till_here = 0;
	}
	else if (world_till_here == 0 && (str[i - 1] == ' ' || str[i - 1] != '+' || str[i - 1] != '-')) {
	    str[i] = *my_strupcase(&str[i]);
	    world_till_here = 1;
	}
	i++;
    }
    return str;
}

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
	if (str[i] >= 65 && str[i] <= 90) {
	    str[i] += 32;
	}
	i++;
    }
    return str;
}

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
	if (str[i] >= 97 && str[i] <= 122) {
	    str[i] -= 32;
	}
	i++;
    }
    return str;
}
