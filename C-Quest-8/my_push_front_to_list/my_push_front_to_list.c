/*
** ETNA PROJECT, 2021
** First program in C
** File description:
** 		Exercise #1 of day #14 : inserts the new node with data value at the beginning of the list.
**			The address of the list's first node is returned.
*/

#include "../include/my_list.h"
#include <stdlib.h>

linked_list_t *my_push_front_to_list(int value, linked_list_t *list)
{
    linked_list_t *result = malloc (sizeof(linked_list_t*));
    result->data = value;
    result->next = list;
    return result;
}
