/*
** ETNA PROJECT, 2021
** Pointers and arrays
** File description:
** 		Exercise #2 of day #8 : returns the number of character in a string
*/

int my_strlen(const char *str)
{
    int i = 0;

    while(str[i] != '\0'){
	i++;
    }

    return i;
}
