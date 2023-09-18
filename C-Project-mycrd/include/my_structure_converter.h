/*
** ETNA PROJECT, 2021
** Pointers and arrays
** File description:
**      Bridge between main and the whole structure
*/

#include "./my_crd.h"

// Basic structure definition
// typedef struct linked_list
// {
//     long long key;
//     long long value;
//     struct linked_list *next;
// } linked_list_t;

// long long my_push_front_to_list(long long key, long long value, linked_list_t **list);
// linked_list_t *my_pop_front_from_list(linked_list_t **list);
// long long my_pop_key_from_list(long long key, linked_list_t **list);
// long long my_find_key_list(long long key, linked_list_t **list);
// long long my_find_replace_val_list(long long key, long long value, linked_list_t **list);
// void print_list(linked_list_t *list);

//  Binary tree
typedef struct binary_tree
{
    long long key;
    long long value;
    struct binary_tree *left;
    struct binary_tree *right;
} binary_tree_t;

long long my_add_to_tree(long long key, long long value, binary_tree_t **tree);
long long my_pop_from_tree(long long key, binary_tree_t **tree, int *SWITCH);
long long my_insert_in_tree(long long key, long long value, binary_tree_t **tree);
long long my_delete_rec_from_tree(long long key, binary_tree_t **tree, int *SWITCH);
binary_tree_t *my_find_and_return_tree(long long key, binary_tree_t *tree);
long long my_find_in_tree(long long key, binary_tree_t *tree);
long long my_find_replace_val_tree(long long key, long long value, binary_tree_t **tree);
long long *my_max_tree(binary_tree_t *tree);
long long *my_min_tree(binary_tree_t *tree);
binary_tree_t *my_checknull_create (long long key, long long value, binary_tree_t **tree);
void my_rec_delete(binary_tree_t **tree, int *SWITCH);
long long get_height_tree(binary_tree_t *tree);
void print_tree(binary_tree_t *tree);
void  node_print(binary_tree_t *this, int current_level, int max_level);

//Function that has to be implemented
long long create_cmd(long long key, long long value, binary_tree_t **tree);
long long delete_cmd(long long key, binary_tree_t **tree, int *SWITCH);
long long find_cmd(long long key, binary_tree_t **tree);

