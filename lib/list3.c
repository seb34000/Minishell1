/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** list3
*/

#include "../include/shell.h"

var_env_t *delete_item(var_env_t *curr, char const *str)
{
    var_env_t *next;

    if (curr == NULL) {
        return (NULL);
    } else if (my_strncmp(curr->value, str, my_strlen(str)) == 0) {
        next = curr->next;
        free(curr);
        return (next);
    } else {
        curr->next = delete_item(curr->next, str);
        return (curr);
    }
}