/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #6 of day #7 : print all 3 digits (different one from another) number
*/

#include <unistd.h>

void my_putchar(char c);

void my_print_comb(void)
{
    for (int i = 48; i <= 57; i++) {
        for (int j = 48; j <= 57; j++) {
            for (int k = 48; k <= 57; k++) {
                if (i < j && j < k) {
                    my_putchar(i);
                    my_putchar(j);
		    my_putchar(k);
		    if (i !=  55 || j != 56 || k != 57) {
			my_putchar(',');
                        my_putchar(' ');
		    }
		}
	    }
	}
    }
}
