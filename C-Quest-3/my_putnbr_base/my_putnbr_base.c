/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #11 of day #9 : converts and displays a decimal number into a number in a given base
*/

#include <unistd.h>

void my_putchar(char c);
int my_strcmp(const char *s1, const char *s2);
int my_fromdecimal_tohexa(int n);
int get_base(const char *base);

void my_putnbr_base(int nbr, const char *base)
{
    if (nbr < -2147483647) {
	my_putchar('0');
	return ;
    }

    int my_base = get_base(base);
    int remainder = nbr % (my_base + 1);
    int division_res = nbr / (my_base + 1);

    if (my_base == 1) {
	if (division_res != 0) {
	    my_putnbr_base(division_res, base);
	}
	my_putchar(48 + remainder);
    }
    else if (get_base(base) == 15) {
	if (division_res != 0) {
	    my_putnbr_base(division_res, base);
	}
	my_putchar(my_fromdecimal_tohexa(remainder));
    }
}

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    int s1_val = 0;
    int s2_val = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
	if (s1[i] != '\0') {
	    s1_val += s1[i];
	}
	if (s2[i] != '\0') {
	    s2_val += s2[i];
	}
	i++;
    }

    return s1_val - s2_val;
}


int get_base(const char *base)
{
    char chaine_hex[] = "0123456789ABCDEF";
    char chaine_bin[] = "01";

    if (my_strcmp(chaine_bin, base) == 0) {
	return 1;
    }
    else if (my_strcmp(chaine_hex, base) == 0) {
	return 15;
    } else {
	return 0;
    }
}

int my_fromdecimal_tohexa(int n)
{
    if (n == 10) {
	return 65;
    }
    else if (n == 11) {
	return 66;
    }
    else if (n == 12) {
	return 67;
    }
    else if (n == 13) {
	return 68;
    }
    else if (n == 14) {
	return 69;
    }
    else if (n == 15) {
	return 70;
    } else {
	return n + 48;
    }
}
