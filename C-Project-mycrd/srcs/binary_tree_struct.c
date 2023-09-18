/*
** ETNA PROJECT, 2021
** my_crd
** File description:
** 		Implements the binary-tree structure and it's methods
*/

#include "../include/my_crd.h"
#include "../include/my_structure_converter.h"

binary_tree_t *my_checknull_create (long long key, long long value, binary_tree_t **tree)
{
    (*tree) = malloc(sizeof(binary_tree_t));
    (*tree)->key = key;
    (*tree)->value = value;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    return (*tree);
}

void my_rec_delete(binary_tree_t **tree, int *SWITCH)
{
    if ((*SWITCH) == 1) {
        (*tree)->key = my_max_tree((*tree)->left)[0];
        (*tree)->value = my_max_tree((*tree)->left)[1];
        (*SWITCH) = 0;
        my_delete_rec_from_tree((*tree)->key, &((*tree)->left), SWITCH);
    } else {
        (*tree)->key = my_min_tree((*tree)->right)[0];
        (*tree)->value = my_min_tree((*tree)->right)[1];
        (*SWITCH) = 1;
        my_delete_rec_from_tree((*tree)->key, &((*tree)->right), SWITCH);
    }
}

long long my_add_to_tree(long long key, long long value, binary_tree_t **tree)
{
    long long found_key = 0;
    if (tree == NULL || (*tree) == NULL) {
        (*tree) = malloc(sizeof(binary_tree_t));
        (*tree) = my_checknull_create(key, value, tree);
        return (*tree)->key;
    }
    found_key = my_find_replace_val_tree(key, value, tree);
    if (found_key != -1)
        return found_key;
    return my_insert_in_tree(key, value, tree);
}

long long my_insert_in_tree(long long key, long long value, binary_tree_t **tree)
{
    if (tree == NULL || (*tree) == NULL) {
        (*tree) = malloc(sizeof(binary_tree_t));
        (*tree) = my_checknull_create(key, value, tree);
        return (*tree)->key;
    }
    else if (key < (*tree)->key)
        return my_insert_in_tree(key, value, &((*tree)->left));
    else
        return my_insert_in_tree(key, value, &((*tree)->right));
}

long long my_delete_rec_from_tree(long long key, binary_tree_t **tree, int *SWITCH)
{
    long long result = 0;
    binary_tree_t *deleted_tree = malloc (sizeof(binary_tree_t));
    if (tree == NULL || (*tree) == NULL) {
        return -1;
    }
    if (key > (*tree)->key) {
        if ((*SWITCH) == 0)
            (*SWITCH) = 1;
        else
            (*SWITCH) = 0;
        return my_delete_rec_from_tree(key, &((*tree)->right), SWITCH);
    }
    else if (key < (*tree)->key) {
        if ((*SWITCH) == 0)
            (*SWITCH) = 1;
        else
            (*SWITCH) = 0;
        return my_delete_rec_from_tree(key, &((*tree)->left), SWITCH);
    } else {
        result = (*tree)->key;
        if ((*tree)->left == NULL && (*tree)->right == NULL) {
            (*tree) = NULL;
        }
        else if ((*tree)->left == NULL) {
            deleted_tree = (*tree);
            (*tree) = (*tree)->right;
            free(deleted_tree);
        }
        else if ((*tree)->right == NULL) {
            deleted_tree = (*tree);
            (*tree) = (*tree)->left;
            free(deleted_tree);
        } else {
            my_rec_delete(tree, SWITCH);
        }
        return result;
    }
}

long long *my_max_tree(binary_tree_t *tree)
{
    long long *result = malloc(sizeof(long long) * 2);
    binary_tree_t *curr_tree = malloc(sizeof(binary_tree_t));
    curr_tree = tree;
    result[0] = curr_tree->key;
    result[1] = curr_tree->value;
    while (curr_tree != NULL) {
        if (result[0] < curr_tree->key) {
            result[0] = curr_tree->key;
            result[1] = curr_tree->value;
        }
        curr_tree = curr_tree->right;
    }
    return result;
}

long long *my_min_tree(binary_tree_t *tree)
{
    long long *result = malloc(sizeof(long long) * 2);
    binary_tree_t *curr_tree = malloc(sizeof(binary_tree_t));
    curr_tree = tree;
    result[0] = curr_tree->key;
    result[1] = curr_tree->value;
    while (curr_tree != NULL) {
        if (result[0] > curr_tree->key) {
            result[0] = curr_tree->key;
            result[1] = curr_tree->value;
        }
        curr_tree = curr_tree->left;
    }
    return result;
}

long long my_pop_from_tree(long long key, binary_tree_t **tree, int *SWITCH)
{
    if ((*SWITCH)) {
        (*SWITCH)--;
    } else {
        (*SWITCH)++;
    }
    return my_delete_rec_from_tree(key, tree, SWITCH);
}

binary_tree_t *my_find_and_return_tree(long long key, binary_tree_t *tree)
{
    if (tree == NULL ||  key >= INT_MAX || key <= INT_MIN) {
        return NULL;
    }
    if (key == tree->key) {
        return tree;
    }
    else if (key < tree->key) {
        return my_find_and_return_tree(key, tree->left);
    } else {
        return my_find_and_return_tree(key, tree->right);
    } 
}

long long my_find_in_tree(long long key, binary_tree_t *tree) 
{
    binary_tree_t *temp = malloc (sizeof(binary_tree_t));
    temp = my_find_and_return_tree(key, tree);
    if (temp == NULL) {
        return -1;
    }
    return temp->value;
}

long long my_find_replace_val_tree(long long key, long long value, binary_tree_t **tree)
{
    if (tree == NULL || (*tree) == NULL || key >= INT_MAX || key <= INT_MIN) {
        return -1;
    }
    if (key == (*tree)->key) {
        (*tree)->value = value;
        return (*tree)->key;
    }
    else if (key < (*tree)->key) {
        return my_find_replace_val_tree(key, value, &((*tree)->left));
    } else {
        return my_find_replace_val_tree(key, value, &((*tree)->right));
    } 
}

long long get_height_tree(binary_tree_t *tree)
{
    if(tree == NULL)
        return 0;
    else {
        int left_side;
        int right_side;
        left_side = get_height_tree(tree->left);
        right_side = get_height_tree(tree->right);
        if(left_side > right_side) {
            return left_side + 1;
        } else
            return right_side + 1;
    }
}

void print_tree(binary_tree_t *tree)
{
    printf("Display tree : \n\n");
    node_print(tree, 0, get_height_tree(tree));
    printf("\n\n");
}
 
void  node_print(binary_tree_t *this, int current_level, int max_level)
{
  int i;
 
  if (this) {
    node_print(this->right, current_level + 1, max_level);
    for (i = 0; i < current_level; i++) {
      printf("    ");
    }
    printf("%d\n", this->key);
    node_print(this->left, current_level + 1, max_level);
  } else {
    if (current_level < max_level) {
      node_print(NULL, current_level + 1, max_level);
      for (i = 0; i < current_level; i++) {
        printf("    ");
      }
      printf("..\n");
      node_print(NULL, current_level + 1, max_level);
    }
  }
}