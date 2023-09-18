/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #7 of day #9 : copy the n first characters of a string in a destination string
*/

char *my_strncat(char *dest, const char *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }

    while (src[j] != '\0' && j < nb) {
	dest[i + j] = src[j];
        j++;
    }

    dest[i + j] = '\0';
    return (dest);
}
