/*
** ETNA PROJECT, 2021
** abc.h
** File description:
** abc.h
*/

#ifndef ABC_H_
#define ABC_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_MAX 2147483647
#define INT_MIN -214748348

char *my_readline(void);
int my_strlen(const char *str);
void my_putchar(char c);

#endif
