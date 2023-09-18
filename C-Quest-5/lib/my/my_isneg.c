/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #4 of day #7 : check if passed parameter is negative or positive
*/

#include <unistd.h>

void my_putchar(char *c);

void my_isneg(int n)
{
    if (n < 0) {
	my_putchar('N');
    } else {
        my_putchar('P');
    }
}
