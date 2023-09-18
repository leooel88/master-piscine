/*
** ETNA PROJECT, 2021
** First program in C
** File description:
**              Exercise #3 of day #15 : sorts a list in ascending order by comparing data, node-to-node.
*/

#include "../include/my_list.h"
#include <stdlib.h>

int is_sorted(linked_list_t *list);
void sorting_round(linked_list_t *list);

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
