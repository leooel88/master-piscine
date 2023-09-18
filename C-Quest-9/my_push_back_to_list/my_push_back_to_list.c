
/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #1 of day #15 : inserts the new node with data value at the end of the list. The address of the list's last node is returned
*/

#include <stdlib.h>
#include "../include/my_list.h"

linked_list_t *my_push_back_to_list(int value, linked_list_t *list)
{
    linked_list_t *result = malloc(sizeof(linked_list_t*));
    if (list == NULL) {
        result->data = value;
	result->next = NULL;
	return result;
    }
    else if (list->next == NULL) {
	result->data = value;
        result->next = NULL;
	list->next = result;
	return result;
    }
    else {
	return my_push_back_to_list(value, list->next);
    }
}
