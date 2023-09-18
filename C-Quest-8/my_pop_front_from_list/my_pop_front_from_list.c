/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**           Exercise #2 of day #14 : removes the first node of the list.
**		The address of the list's first node is returned.
*/

#include "../include/my_list.h"
#include <stdlib.h>

linked_list_t *my_pop_front_from_list(linked_list_t *list)
{
    if (list == NULL || list->next == NULL) {
	return NULL;
    } else {
	linked_list_t *temp_first = malloc(sizeof(linked_list_t*));
        temp_first = list->next;
        free (list);

        return temp_first;
    }
}
