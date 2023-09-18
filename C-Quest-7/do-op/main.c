/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**              Exercise #3 of day #13 : computes an operation
**              File : Main function
*/

#include "do-op.h"

int main (int argc, char **argv) {
    int a = 0;
    int b = 0;

    if (argc != 4) {
	my_putchar('P');
	return 84;
    }
    a = my_getnbr(argv[1]);
    b = my_getnbr(argv[3]);

    return print_op(a, b, get_op(argv[2]));
}
