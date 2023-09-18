/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**           Exercise #5 of day #14 : removes all nodes containing data equal to the reference data.
*/

#include "../include/my_list.h"
#include <stdlib.h>

linked_list_t *my_pop_front_from_list(linked_list_t *list);

void my_delete_nodes(linked_list_t **list, const int data_ref)
{
    if (list == NULL || *list == NULL) {
        return;
    }

    if ((*list)->data == data_ref) {
	my_delete_nodes(&((*list)->next), data_ref);
	*list = my_pop_front_from_list(*list);
    } else {
	my_delete_nodes(&((*list)->next), data_ref);
    }
}

linked_list_t *my_pop_front_from_list(linked_list_t *list)
{
    if (list == NULL || list->next == NULL) {
        return NULL;
    } else {
        linked_list_t *temp_first = malloc(sizeof(linked_list_t));
        temp_first = list->next;
        free (list);

        return temp_first;
    }
}
