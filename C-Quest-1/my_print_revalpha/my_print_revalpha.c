/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #2 of day #7 : inverted alphabet
*/

void my_putchar(char c);

void my_print_revalpha(void)
{
    for (char i = 'z'; i >= 'a'; i--) {
	my_putchar(i);
    }
}
