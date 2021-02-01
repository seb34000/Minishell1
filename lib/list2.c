/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** list2
*/

#include "../include/shell.h"

void print(var_env_t *list)
{
    var_env_t *new = list;
    char c = '\n';

    while (new != NULL && new->value != NULL) {
        write(1, new->value, my_strlen(new->value));
        write (1, &c, 1);
        new = new->next;
    }
}

var_env_t *set_list(char **env)
{
    var_env_t *list = NULL;
    int i = 0;

    list = create_list(env[i]);
    for (i = 1;env[i]; i++)
        set_env(&list, env[i], i);
    list->max = i;
    return (list);
}

var_env_t *search_list(char *find, var_env_t *envt)
{
    var_env_t *list = envt;

    while (list != NULL \
    && my_strncmp(list->value, find, my_strlen(find)) != 0) {
        list = list->next;
    }
    return (list);
}

void swap(var_env_t *temp1, var_env_t *temp2)
{
    int idx = 0;
    char *var = NULL;

    if (temp2->index < temp1->index) {
        idx = temp1->index;
        var = my_strdup(temp1->value);
        temp1->index = temp2->index;
        temp1->value = my_strdup(temp2->value);
        temp2->index = idx;
        temp2->value = my_strdup(temp2->value);
    }
}

void sort_env(var_env_t **envt)
{
    var_env_t *temp1;
    var_env_t *temp2;

    for (temp1 = *envt; temp1 != NULL; temp1 = temp1->next) {
        for (temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next) {
            swap(temp1, temp2);
        }
    }
}
