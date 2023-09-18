/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**              Exercise #2 of day #10 : turns the command-line given arguments into a single string
*/

#include <stdlib.h>

int count_args(int argc, char **argv);

char *my_concat_params(int argc, char **argv)
{
    int i = 0;
    int nb_arg = count_args(argc, argv);
    int current_res_char = 0;
    int j = 0;

    char *result = (char*) malloc (i);
    nb_arg = 0;

    while (nb_arg < argc) {
	j = 0;
	while (argv[nb_arg][j] != '\0') {
	    result[current_res_char] = argv[nb_arg][j];
	    current_res_char++;
	    j++;
        }

	nb_arg++;

	if (nb_arg < argc) {
	    result[current_res_char] = '\n';
            current_res_char++;
	}
    }
    result[current_res_char] = '\0';
    return result;
}

int count_args(int argc, char **argv)
{
    int result = 0;
    while (nb_arg < argc) {
        i += sizeof(argv[argc - nb_arg]) + sizeof(char);
        result++;
    }
    return result;
}
