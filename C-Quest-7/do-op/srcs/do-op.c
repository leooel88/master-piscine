/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #3 of day #13 : computes an operation
**		File : Functions used in main
*/

#include "do-op.h"

void my_putchar(char c);
void my_putnbr(int n);
int my_getnbr(char *n);
int print_op (int a, int b, char op);
char get_op(char *c);

int print_op (int a, int b, char op) {
    int res = 0;
    if (op == 43) {
	res = a + b;
	my_putnbr(res);
	return 0;
    }
    else if (op == 45) {
	res = a - b;
	my_putnbr(res);
	return 0;
    }
    else if (op == 42) {
	res = a * b;
	my_putnbr(res);
	return 0;
    }
    else if (op == 47) {
	if (b == 0) {
            return 84;
        }
	res = a / b;
	my_putnbr(res);
	return 0;
    }
    else if (op == 37) {
	if (b == 0) {
	    return 84;
	}
	res = a % b;
	my_putnbr(res);
    }
    else if (op == '\0') {
	my_putchar('0');
    } else {
	return 84;
    }
    return 84;
}

void my_putnbr(int n)
{
    if (n == -2147483648) {
        my_putchar('0');
        return ;
    }
    else if (n < 0) {
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

int my_getnbr(char *n)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (n[i] == 45 || n[i] == 43) {
	if (n[i] == 45) {
	    sign *= -1;
	}
	i++;
    }
    if (n[i] < 48 || n[i] > 57)
	return 0;

    while (n[i] >= 48 && n[i] <= 57) {
	result *= 10;
	result += (n[i] - 48);
	i++;
    }
    return sign * result;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

char get_op(char *c)
{
    if (c[0] == 43 || c[0] == 45 || c[0] == 42 || c[0] == 47 || c[0] == 37) {
	return  c[0];
    } else {
	return '\0';
    }
}
