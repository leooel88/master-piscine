/*
** ETNA PROJECT, 2021
** my_crd
** File description:
** 		This function allows you to read a line of less than 50 characters from the standard input.
**      The function does not take any parameter and returns an allocated string, dont forget to free().
*/

#include "../include/my_crd.h"

char *my_readline(void)
{
    char    *buff;
    ssize_t size;

    buff = malloc(sizeof(*buff) * (50 + 1));
    if (buff == NULL)
        return NULL;
    size = read(0, buff, 50);
    if (size > 1) {
        buff[size] = '\0';
        return buff;
    }
    free(buff);
    return NULL;
}
