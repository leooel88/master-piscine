/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**           Exercise #2 of day #13 : displays the content of an array created with the previous function
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_struct.h"

int count_chars(const char *str, int index);
int count_words(const char *str);
char *my_strcpy(char *dest, const char *src);
int my_strlen(const char *str);
char **my_str_to_word_array(const char *str);
void my_putstr(const char *str);
void my_putnbr(int n);
void my_putchar(char c);
struct info_param *my_params_to_array(int ac, char **av);

void my_show_params_array(const struct info_param *par)
{
    if (!par || !par[0].str) {
        return ;
    }
    for (int i = 1; par[i].str != 0; i++) {
        my_putstr("str=\"");
        my_putstr(par[i].str);
        my_putstr("\" | length=[");
        my_putnbr(par[i].length);
        my_putstr("] | words=[");
        for (int j = 0; par[i].word_array[j] != NULL; j++) {
            my_putstr("'");
            my_putstr(par[i].word_array[j]);
            my_putstr("'");
            if (par[i].word_array[j + 1] != NULL) {
            my_putstr(", ");
            }
        }
        my_putstr("]");
        my_putchar('\n');
    }
}

void my_putstr(const char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void my_putnbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        my_putnbr(-n);
        return ;
    }
    else if (n == 0) {
        my_putchar('0');
        return ;
    }

    int current_unit_number = n % 10;

    if (n/10 != 0) {
        my_putnbr(n/10);
    }
    my_putchar(current_unit_number + 48);
}