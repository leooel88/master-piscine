/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**              Exercise #5 of day #15 : reates a new element and inserts it into a sorted list, so that the list remains sorted in ascending order.
*/

#include "../include/my_list.h"
#include <stdlib.h>

linked_list_t *my_add_rec(linked_list_t *begin, int data);
int is_sorted(linked_list_t *list);

void my_add_in_sorted_list(linked_list_t **begin, int data)
{
    if (!(is_sorted(*begin))) {
	return ;
    }
    else if (begin == NULL || (*begin) == NULL) {
        (*begin) = malloc(sizeof(linked_list_t));
        (*begin)->data = data;
        (*begin)->next = NULL;
        return ;
    }
    (*begin) = my_add_rec(*begin, data);
}

linked_list_t *my_add_rec(linked_list_t *begin, int data)
{
    if (begin == NULL) {
	linked_list_t *new_node = malloc(sizeof(linked_list_t));
        new_node->data = data;
        new_node->next = NULL;
	return new_node;
    }
    if (begin->data > data) {
	linked_list_t *new_node = malloc(sizeof(linked_list_t));
	new_node->data = data;
	new_node->next = begin;
	return new_node;
    } else {
	begin->next = my_add_rec(begin->next, data);
	return begin;
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
