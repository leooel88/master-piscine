/*
** ETNA PROJECT, 2021
** Pointers and arrays
** File description:
**      Bridge between main and the whole structure
*/

#include "../include/my_structure_converter.h"

//Calls the item creation function : MODIFY LIST & FUNCTION CALLED
long long create_cmd(long long key, long long value, binary_tree_t **tree)
{
    return my_add_to_tree(key, value, tree);
}

//Calls the item deleting function : MODIFY LIST & FUNCTION CALLED
long long delete_cmd(long long key, binary_tree_t **tree, int *SWITCH)
{
    return my_pop_from_tree(key, tree, SWITCH);
}

//Calls the item finding function : MODIFY LIST & FUNCTION CALLED
long long find_cmd(long long key, binary_tree_t **tree)
{
    return my_find_in_tree(key, (*tree));
}





