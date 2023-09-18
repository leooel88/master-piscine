/*
** ETNA PROJECT, 2021
** colors.c
** File description:
** colors.c
*/

#include "abc.h"

void put_colors(int n, char c)
{
    my_putstr("\033[0;4");
    my_putchar((n % 8) + 49);
    my_putchar('m');
    my_putchar(c);
    my_putstr("\033[0m");
}
