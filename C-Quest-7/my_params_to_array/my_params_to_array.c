/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #1 of day #13 : stores the program's parameters into an array of structures and returns the address of the array's
**			first cell
*/


#include <stdlib.h>
#include "my_struct.h"

int count_chars(const char *str, int index);
int count_words(const char *str);
char *my_strcpy(char *dest, const char *src);
int my_strlen(const char *str);
char **my_str_to_word_array(const char *str);

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param *result = malloc((ac + 1) * sizeof(struct info_param));
    int i;
    for (i = 0; i < ac; i++) {
        result[i].length = my_strlen(av[i]);
        result[i].str = av[i];
        result[i].copy = malloc((result[i].length + 1) * sizeof(char));
        my_strcpy(result[i].copy, av[i]);
        result[i].word_array = my_str_to_word_array(av[i]);
    }
    result[ac].str = '\0';

    return result;
}

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

int my_strlen(const char *str)
{
    int i = 0;

    while(str[i] != '\0'){
        i++;
    }

    return i;
}

char **my_str_to_word_array(const char *str)
{
    int nb_words = count_words(str);
    int i = 0;
    int j = 0;
    int current_word_index = 0;
    int nb_current_word = 0;
    char **result = (char**) malloc ((nb_words + 1) * sizeof(char*));

    while (str[i] != '\0') {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)) {
            nb_current_word = count_chars(str, i);
            result[current_word_index] = (char*) malloc ((nb_current_word + 1) * sizeof(char));
            while (j < nb_current_word) {
                result[current_word_index][j] = str[i];
                j++;
                i++;
            }
            result[current_word_index][j] = '\0';
            nb_current_word = 0;
            current_word_index++;
            j = 0;
        } else {
            i++;
        }
    }
    result[current_word_index] = NULL;
    return result;
}

int count_words(const char *str)
{
    int i = 0;
    int result = 0;
    int into_word = 0;

    while(str[i] != '\0') {
        if (into_word == 1) {
            if((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122) && (str[i] < 48 || str[i] > 57)) {
                into_word = 0;
            }
        }
        else if (into_word == 0 && ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57))) {
            into_word = 1;
            result++;
        }
        i++;
    }
    return result;
}

int count_chars(const char *str, int i)
{
    int result = 0;

    while ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57)) {
        result++;
        i++;
    }
    return result;
}