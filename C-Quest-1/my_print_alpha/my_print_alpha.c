/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #1 of day #7 : print all the alphabet in lowercase
*/

#include <unistd.h>

void my_putchar(char c);

void my_print_alpha(void)
{
    for (char i = 'a'; i <= 'z' ; i++) {
	my_putchar(i);
    }
    my_putchar('\n');
}
