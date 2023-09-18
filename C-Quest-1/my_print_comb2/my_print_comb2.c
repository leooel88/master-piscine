/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #7 of day #7 : print in ascending order, all the different combinations of two 
** 			two-digit numbers
*/

#include <unistd.h>

void my_putchar(char c);

void my_print_comb2(void)
{
    for (int i = '0'; i <= '9'; i++) {
	for (int j = '0'; j <= '9'; j++) {
	    for (int k = '0'; k <= '9'; k++) {
	        for (int l = '0'; l <= '9'; l++) {
		    if (i != k || j != l) {
			if (i < k || (i == k && j < l)) {
			    my_putchar(i);
                            my_putchar(j);
                            my_putchar(' ');
                            my_putchar(k);
                            my_putchar(l);

			    if (i != '9' || j != '8' || k != '9' || l != '9') {
                                my_putchar(',');
                                my_putchar(' ');
                            }
			}
		    }
		}
	    }
	}
    }
}
