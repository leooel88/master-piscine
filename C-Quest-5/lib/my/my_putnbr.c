/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #1 of day #7 : print any given integer
*/

#include <unistd.h>

void my_putchar(char c);

void my_putnbr(int n)
{
    if (n == -2147483648){
	n = 0;
    }
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
    my_putchar(current_unit_number+48);
}
