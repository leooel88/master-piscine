/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #5 of day #7 : displays E for even, or O for odd
*/

#include <unistd.h>

void my_putchar(char c);

void my_iseven(int n)
{
    if ((n%2) == 0) {
        my_putchar('E');
    } else {
	my_putchar('O');
    }
}
