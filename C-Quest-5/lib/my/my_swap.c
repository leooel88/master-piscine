/*
** ETNA PROJECT, 2021
** Pointers and arrays
** File description:
** 		Exercise #4 of day #8 : swap's the content two integer
*/

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
