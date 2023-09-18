/*
** ETNA PROJECT, 2021
** Pointers and arrays
** File description:
** 		Exercise #1 of day #8 : displays a string letter by letter
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(const char *str)
{
    int i = 0;
    while (str[i] != '\0') {
	my_putchar(str[i]);
	i++;
    }
}
