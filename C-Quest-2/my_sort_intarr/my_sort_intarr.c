/*
** ETNA PROJECT, 2021
** Pointers and arrays
** File description:
** 		Exercise #5 of day #8 : sorts int in an array
*/

void my_swap(int *a, int *b);

void my_sort_intarr(int *array, int size)
{
    int index1 = 0;
    int index2 = 1;
    int flag = 1;

    while (flag == 1) {
	flag = 0;
	index1 = 0;
	index2 = 1;
	for (int i = 0; i < size - 1; i++) {
	    if (array[index1] > array[index2]) {
		my_swap(&array[index1], &array[index2]);
		flag = 1;
	    }
	    index1++;
	    index2++;
	}
	if (flag == 0) {
	    break;
	}
    }
}


void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
