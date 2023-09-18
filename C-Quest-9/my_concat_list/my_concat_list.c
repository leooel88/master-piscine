/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**              Exercise #4 of day #15 : puts the elements of a begin2 list at the end of a begin1 list.
*/

#include "../include/my_list.h"
#include <stdlib.h>

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
