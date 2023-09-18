/*
** ETNA PROJECT, 2021
** my_crd
** File description:
** 		Implements the basic linkes-list structure and it's methods
*/

#include "../include/my_crd.h"
#include "../include/my_structure_converter.h"

void print_list(linked_list_t *list)
{
    int i = 0;
    linked_list_t *curr_node = malloc(sizeof(linked_list_t));
    curr_node = list;
    while (curr_node != NULL) {
        printf("[%d] Key : %d | Value : %d\n", i, curr_node->key, curr_node->value);
        curr_node = curr_node->next;
        i++;
    }
}

long long my_push_front_to_list(long long key, long long value, linked_list_t **list)
{
    long long key_found = 0;
    if (list == NULL || (*list) == NULL) {
        linked_list_t *temp = malloc(sizeof(linked_list_t));
        temp->key = key;
        temp->value = value;
        temp->next = NULL;
        (*list) = temp;
        return (*list)->key;
    }
    key_found = my_find_replace_val_list(key, value, list);
    if (key_found != -1) {
        return key_found;
    }

    linked_list_t *result = malloc (sizeof(linked_list_t));
    result->key = key;
    result->value = value;
    result->next = *list;
    (*list) = result;
    return (*list)->key;
}

linked_list_t *my_pop_front_from_list(linked_list_t **list)
{
    if (list == NULL || (*list) == NULL) {
        return NULL;
    }
    linked_list_t *result = malloc (sizeof(linked_list_t));
    linked_list_t *temp = malloc (sizeof(linked_list_t));
    temp = *list;
    (*list) = (*list)->next;
    return *list;
}

long long my_pop_key_from_list(long long key, linked_list_t **list)
{
    long long result = 0;

    linked_list_t *curr_node = malloc (sizeof(linked_list_t));
    curr_node = *list;

    if (list == NULL || (*list) == NULL)
        return -1;
    if (curr_node->key == key) {
        result = curr_node->key;
        (*list) = my_pop_front_from_list(&curr_node);
        return result;
    }

    while (curr_node->next != NULL)
    {
        if (curr_node->next->key == key) {
            result = curr_node->next->key;
            curr_node->next = my_pop_front_from_list(&curr_node->next);
            return result;
        }
        curr_node = curr_node->next;
    }
    free(curr_node);
    return -1;
}

long long my_find_key_list(long long key, linked_list_t **list)
{
    int result = 0;
    linked_list_t *curr_node = malloc (sizeof(linked_list_t));
    curr_node = *list;

    if (list == NULL || (*list) == NULL){
        return -1;
    }
    while (curr_node != NULL) {
        if (curr_node->key == key)
            return curr_node->value;
        curr_node = curr_node->next;
    }
    free(curr_node);
    return -1;
}

long long my_find_replace_val_list(long long key, long long value, linked_list_t **list)
{
    long long result = 0;
    linked_list_t *curr_node = malloc (sizeof(linked_list_t));
    curr_node = *list;

    if (list == NULL || (*list) == NULL)
        return -1;
    
    while (curr_node != NULL) {
        if (curr_node->key == key) {
            curr_node->value = value;
            int result = curr_node->key;
            free(curr_node);
            return result;
        }
            
        curr_node = curr_node->next;
    }
    free(curr_node);
    return -1;
}