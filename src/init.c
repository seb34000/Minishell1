/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** init
*/

#include "../include/shell.h"

void init_struct(shell_t *shell, char **env)
{
    int i = 0;
    int j = 0;

    shell->cmd_arg = NULL;
    shell->path_bin = NULL;
    shell->envt = NULL;
    shell->envt = set_list(env);
    shell->env = malloc(sizeof(char *) * (my_ptrlen(env) + 2));
    shell->env = my_memset(shell->env, 0, \
    sizeof(char *) * (my_ptrlen(env) + 1));
    for (;env[i]; i++)
            shell->env[i] = my_strdup(env[i]);
}