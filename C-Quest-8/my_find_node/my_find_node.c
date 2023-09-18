/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**              Exercise #4 of day #14 : returns the address of the first node occurence, which contains data
**			equal to the reference data. If no such node is found, NULL should be returned
*/

#include "../include/my_list.h"
#include <stdlib.h>

linked_list_t *my_find_node(linked_list_t *list, const int data_ref)
{
    if (list == NULL) {
	return NULL;
    }

    linked_list_t *result = malloc(sizeof(linked_list_t*));
    result->data = list->data;
    result->next = list->next;

    while (result != NULL) {
	if (result->data == data_ref) {
	    return result;
	}
	result = result->next;
    }
    return NULL;
}
