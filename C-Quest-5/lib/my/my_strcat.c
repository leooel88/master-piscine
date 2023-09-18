/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #6 of day #9 : concatenates src to dest
*/

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
	i++;
    }

    while (src[j] != '\0') {
	dest[i + j] = src[j];
	j++;
    }
    dest[i + j] = '\0';
    return dest;
}
