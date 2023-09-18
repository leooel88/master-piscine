/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #2 of day #15 : removes the last node of the list.
**			The address of the list's first node is returned.
*/

#include "../include/my_list.h"
#include <stdlib.h>

linked_list_t *my_pop_back_from_list(linked_list_t *list)
{
    if (list == NULL) {
	return NULL;
    }

    linked_list_t *curr_node = malloc(sizeof(linked_list_t*));
    curr_node = list;

    linked_list_t *delete_node = malloc(sizeof(linked_list_t*));
    delete_node = list;

    if (list->next == NULL) {
	return NULL;
    }

    while (curr_node->next != NULL) {
	if (curr_node->next->next == NULL) {
	    delete_node = curr_node->next;
	    curr_node->next = NULL;
	    free(delete_node);
	    return list;
	}
	curr_node = curr_node->next;
    }
    return NULL;
}
