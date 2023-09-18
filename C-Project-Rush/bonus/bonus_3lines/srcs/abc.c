/*
** ETNA PROJECT, 2021
** abc.c
** File description:
** abc.c
*/

#include "abc.h"

void print_abc_square(int n)
{
    int char_a = 97; int count = 0; static const int limit = 2147483647; if ((n < 0) || (n >= limit)) return; for (; count++ < n; char_a++) {
        for (int j = 0; j < 26; char_a++) { my_putchar(char_a); if (char_a >= 122) char_a = 96; if (j++ == 26) j = 0; } if (char_a == 122) char_a = 96; my_putchar('\n'); }
}

void print_abc(int n)
{
    print_abc_square(n);
}
