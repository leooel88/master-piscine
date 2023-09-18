/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**              Exercise #1 of day #10 : allocates memory and copies the string given as argument in it
*/

#include <stdlib.h>

char *my_strdup(const char *src)
{
    int src_size = 0;
    int i = 0;

    while (src[src_size] != '\0') {
	src_size++;
    }

    char *result = (char*) malloc((src_size + 1) * sizeof(char));

    while (src[i] != '\0') {
	result[i] = src[i];
	i++;
    }
    result[i] = '\0';
    return result;
}
