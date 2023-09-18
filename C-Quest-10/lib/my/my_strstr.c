/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #5 of day #9 : check for a pattern in a string
*/

#include <stddef.h>

char *my_strstr(char *str, const char *to_find)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0' && to_find[j] != '\0') {
        if (str[i] == to_find[j]) {
            i++;
            j++;
        } else {
            i++;
            j = 0;
        }

        if (to_find[j] != '\0' && str[i] == '\0') {
            return NULL;
        }

        if (to_find[j] == '\0') {
            return &str[i - j];
        }
    }

    return &str[i];
}
