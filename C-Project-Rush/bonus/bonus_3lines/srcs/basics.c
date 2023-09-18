/*
** ETNA PROJECT, 2021
** basics.c
** File description:
** basics.c
*/

#include "abc.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (; *str; str++)
        my_putchar(*str);
}
