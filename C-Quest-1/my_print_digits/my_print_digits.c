/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #3 of day #7 : print all digits
*/

#include <unistd.h>

void my_putchar(char c);

void my_print_digits(void)
{
    for (int i = 48; i <= 57; i++) {
	my_putchar(i);
    }
}
