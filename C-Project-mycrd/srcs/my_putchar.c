/*
** ETNA PROJECT, 2021
** my_crd
** File description:
** 		Write a character on standard output
*/

#include "../include/my_crd.h"

void my_putchar(char c)
{
  write(1, &c, 1);
}