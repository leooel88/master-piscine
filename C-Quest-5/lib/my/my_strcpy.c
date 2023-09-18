/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise # of day #9 : copy a string in a destination string
*/

char *my_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0') {
	dest[i] = src[i];
        i++;
    }
    dest[i]='\0';
    return dest;
}
