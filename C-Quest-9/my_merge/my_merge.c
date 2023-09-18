 /*
** ETNA PROJECT, 2021
** First program in C
** File description:
**              Exercise #6 of day #15 : integrates the elements of a sorted list, begin2, into another sorted list, begin1, 
**		so that begin1 remains sorted in ascending order.
*/

#include "../include/my_list.h"
#include <stdlib.h>
#include <stdio.h>

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2);
void my_sort_list(linked_list_t **begin);
void sorting_round(linked_list_t *list);
int is_sorted(linked_list_t *list);

void my_merge(linked_list_t **begin1, linked_list_t *begin2)
{
    if (begin2 == NULL)
        return ;
    my_concat_list(begin1, begin2);
    my_sort_list(begin1);
}

void my_sort_list(linked_list_t **begin)
{
    if (begin == NULL || *begin == NULL) {
	return ;
    }

    int flag = 0;
    while (flag == 0) {
	sorting_round(*begin);
        flag = is_sorted(*begin);
    }
}

int is_sorted(linked_list_t *list)
{
    if (list == NULL || list->next == NULL) {
	return 1;
    } else if (list->data > list->next->data){
	return 0;
    } else {
	return is_sorted(list->next);
    }
}

void sorting_round(linked_list_t *list)
{
    if (list == NULL || list->next == NULL) {
	return ;
    }

    if (list->data > list->next->data) {
	int temp = list->data;
	list->data = list->next->data;
	list->next->data = temp;
    }
    sorting_round(list->next);
}

void my_concat_list(linked_list_t **begin1, linked_list_t *begin2)
{
    if (begin1 == NULL || (*begin1) == NULL) {
        (*begin1) = begin2;
        return ;
    }
    else if (begin2 == NULL) {
	    return ;
    }

    while ((*begin1)->next != NULL) {
	    begin1 = &((*begin1)->next);
    }
    (*begin1)->next = begin2;
}