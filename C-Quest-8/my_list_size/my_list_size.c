/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**           Exercise #3 of day #14 : returns the number of elements on the list
*/

#include "../include/my_list.h"
#include <stdlib.h>

int my_list_size(const linked_list_t *list)
{

    if (list == NULL) {
	return 0;
    }
    int i = 0;

    linked_list_t *curr_node = malloc(sizeof(linked_list_t*));
    curr_node->data = list->data;
    curr_node->next = list->next;

    while (curr_node != NULL) {
	i++;
	curr_node = curr_node->next;
    }
    return i;
}
