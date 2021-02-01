/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** list
*/

#include "../include/shell.h"

int get_unset_index(char *value, var_env_t *env)
{
    var_env_t *search_cell = env;
    int i = 1;

    while (my_strncmp(search_cell->value, value, my_strlen(value)) != 0) {
        search_cell = search_cell->next;
        i++;
    }
    return (i);
}

var_env_t *create_list(char *value)
{
    var_env_t *new_cell = malloc(sizeof(var_env_t));

    if (!new_cell)
        return (NULL);
    new_cell->value = value;
    new_cell->next = NULL;
    new_cell->index = 0;

    return (new_cell);
}

void set_env(var_env_t **list, char *var, int index)
{
    var_env_t *new = NULL;

    if (!list)
        return ;
    new = malloc(sizeof(var_env_t));
    my_memset(new, 0, sizeof(var_env_t));
    new->value = my_strdup(var);
    new->next = (*list);
    new->index = index;
    (*list) = new;
}

int unset_env2(var_env_t **list, char *value)
{
    var_env_t *tmp = *list;
    var_env_t *prev = malloc(sizeof(var_env_t));
    int idx = 0;

    my_memset(prev, 0, sizeof(var_env_t));
    if (tmp != NULL \
    && my_strncmp(tmp->value, value, my_strlen(value) == 0)) {
        idx = (*list)->index;
        *list = tmp->next;
        free (tmp->value);
        free (tmp);
        tmp = NULL;
        return (idx);
    }
    while (tmp != NULL \
    && my_strncmp(tmp->value, value, my_strlen(value)) != 0) {
        idx = tmp->index;
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return (idx);
    prev->next = tmp->next;
    free (tmp);
    return (idx);
}

int unset_env(var_env_t **list, unsigned int unset_index)
{
    var_env_t *save = NULL;
    unsigned int i = 1;

    if (!list)
        return (-1);
    for (;i < unset_index; i++) {
        (*list) = (*list)->next;
        save = (*list);
    }
    if ((*list)->next != NULL) {
        save = (*list);
        free ((*list)->value);
        free ((*list));
        (*list) = NULL;
    } else if ((*list)->next == NULL) {
        free ((*list)->value);
        free ((*list));
        save->next = NULL;
    }
    return (i);
}