/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #9 of day #9 : puts every letter of every word in it in lowercase
*/

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
