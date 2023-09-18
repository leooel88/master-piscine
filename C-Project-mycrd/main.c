/*
** ETNA PROJECT, 2021
** main.c
** File description:
** main.c
*/

#include "./include/my_crd.h"
#include "./include/my_structure_converter.h"

void my_print_int(long long n)
{
    if (n == 0)
        return ;
    if (n < 0) {
        my_putchar('-');
        return my_print_int(n * (-1));
    }
    my_print_int(n / 10);
    my_putchar((n % 10) + 48);
    return;
}

void my_handle_nbr(char **cmd_line, int **flags, int *i, int *result)
{
    if ((*cmd_line)[(*i)] == ' ') {
        (*flags)[0] = 0;
        (*flags)[1] = 1;
    }
    else if ((*cmd_line)[(*i)] != '\n' && (((*cmd_line)[(*i)] - 48 < 0) || ((*cmd_line)[(*i)] - 48 > 9)))
        (*result) = 0;
        return;
    (*i) = (*i) + 1;
    (*result) = -1;
}

void my_handle_delete_or_create(char **cmd_line, int **flags, int *i, int *result)
{
    if ((*cmd_line)[(*i)] == 'D') {
        (*flags)[1] = 0;
        (*flags)[2] = 1;
    }
    else if (((*cmd_line)[(*i)] - 48 >= 0) && ((*cmd_line)[(*i)] - 48 <= 9)) {
        (*flags)[1] = 0;
        (*flags)[0] = 1;
    } else
        (*result) =  0;
        return;
    (*i) = (*i) + 1;
    (*result) = -1;
}

void my_handle_delete(char **cmd_line, int **flags, int *i, int *result)
{
    if ((*cmd_line)[(*i)] == '\n') {
        (*flags)[2] = 0;
        (*flags)[0] = 1;
    } else
        (*result) = 0;
        return;
    (*i) = (*i) + 1;
    (*result) = -1;
}

void my_go_through_file(char **cmd_line, int **flags, int *i, int *result)
{
    while ((*cmd_line)[(*i)] != '\0') {
        if ((*flags)[0]) {
            my_handle_nbr(cmd_line, flags, i, result);
            if ((*result) != -1)
                return;
        }
        else if ((*flags)[1]) {
            my_handle_delete_or_create(cmd_line, flags, i, result);
            if ((*result) != -1)
                return;
        }
        else if ((*flags)[2]) {
            my_handle_delete(cmd_line, flags, i, result);
            if ((*result) != -1)
                return;
        }
    }
}

int test_cmd(char *cmd_line)
{
    int i = 0;
    int *flags = malloc(sizeof(int) * 3);
    int result = 0;

    if (my_strlen(cmd_line) == 0)
        return 1;
    if ((cmd_line[i] - 48) < 0 || (cmd_line[i] - 48 > 9))
        return 0;
    my_go_through_file(&cmd_line, &flags, &i, &result);
    if (result != -1)
        return result;
    if (cmd_line[i - 1] != '\n')
        return 0;
    return 1;
}

long long my_get_nbr(char *str)
{
    long long result = 0;
    int i = 0;
    long long sign = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign *= -1;
        }
        i++;
    }

    while ((str[i] - 48) >= 0 && (str[i] - 48 <= 9)) {
        result *= 10;
        result += (str[i] - 48);
        i++;
    }
    return sign * result;
}

void my_print_create(binary_tree_t **tree, char **line, int *i, long long *nbr_1, long long *result)
{
    int j = 0;
    long long nbr_2 = 0;
    char *nbr_str_2 = malloc (51 * sizeof(char));

    while ((*line)[(*i)] != '\0') {
        nbr_str_2[j] = (*line)[(*i)];
        j++;
        (*i) = (*i) + 1;
    }
    nbr_str_2[(*i)] = '\0';
    nbr_2 = my_get_nbr(nbr_str_2);
    (*result) = create_cmd(*nbr_1, nbr_2, tree);
    my_print_int((*result));
    my_putchar('\n');
    free(nbr_str_2);
}

void my_print_find(binary_tree_t **tree, long long *nbr_1, long long *result)
{
    (*result) = find_cmd((*nbr_1), tree);
    my_print_int((*result));
    my_putchar('\n');
}

void my_print_delete(binary_tree_t **tree, long long *nbr_1, long long *result, int *SWITCH)
{
    (*result) = delete_cmd((*nbr_1), tree, SWITCH);
    my_print_int((*result));
    my_putchar('\n');
}

void my_extract_nbr(char **line, int *i, long long *nbr_1)
{
    char *nbr_str_1 = malloc (51 * sizeof(char));

    while ((*line)[(*i)] != '\0' && (*line)[(*i)] != ' ') {
        nbr_str_1[(*i)] = (*line)[(*i)];
        (*i) = (*i) + 1;
    }
    nbr_str_1[(*i)] = '\0';
    (*nbr_1) = my_get_nbr(nbr_str_1);
    free(nbr_str_1);
}
void my_line_controller (char *line, binary_tree_t **tree, int *SWITCH)
{
    int i = 0;
    long long result = 0;
    long long nbr_1 = 0;

    if (my_strlen(line) == 0)
        return ;
    my_extract_nbr(&line, &i, &nbr_1);
    if (line[i] == '\0') {
        my_print_find(tree, &nbr_1, &result);
    }
    else if (line[i] == ' ') {
        i++;
        if (line[i] == '+' || line[i] == '-' || ((line[i] - 48) >= 0 && (line[i] - 48 <= 9))) {
            my_print_create(tree, &line, &i, &nbr_1, &result);
        }
        else if (line[i] == 'D') {
            my_print_delete(tree, &nbr_1, &result, SWITCH);
        }
    }
}

int main (void)
{
    int SWITCH = 0;
    binary_tree_t *general_tree = malloc(sizeof(binary_tree_t));
    general_tree = NULL;
    char *line = NULL;
    size_t n = 0;
    while (getline(&line, &n, stdin) != -1) {
        my_line_controller(line, &general_tree, &SWITCH);
        free(line);
        line = NULL;
    }
    free(general_tree);
    return 0;
}
