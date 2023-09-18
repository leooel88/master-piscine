/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**              Exercise #3 of day #10 : plits a string into words
*/

#include <stdlib.h>

int count_chars(const char *str, int index);
int count_words(const char *str);

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
	    result[current_word_index] = '\0';
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
            if((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122) && (str[i] < 47 || str[i] > 57)) {
                into_word = 0;
                result++;
            }
        }
        else if (into_word == 0 && ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122) || (str[i] >= 48 && str[i] <= 57))) {
            into_word = 1;
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
