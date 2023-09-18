/*
** ETNA PROJECT, 2021
** Pointers and arrays
** File description:
** 		Exercise #2 of day #8 : return a string reversed
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(const char *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char temp = str[i];

    while (i < j) {
 	temp = str[i];
	str[i] = str[j];
	str[j] = temp;

	i++;
        j--;
    }
    return str;
}

int my_strlen(const char *str)
{
    int i = 0;
    do {
	i++;
    } while(str[i] != '\0');
    return i;
}
