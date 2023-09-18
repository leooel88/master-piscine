/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #2 of day #9 : copy n character from a string in a destination string
*/

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    while (i < n) {
        if (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        } else {
            dest[i] = '\0';
            i++;
        }
    }
    dest[i] = '\0';
    return dest;
}
