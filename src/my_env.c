/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** switch command
*/

#include "../include/shell.h"

void my_env(shell_t *shell)
{
    print(shell->envt);
}

char *get_newvar(shell_t *shell, char *new_var)
{
    size_t size = 0;

    size = my_strlen(shell->cmd_arg[1]) + 2;
    new_var = malloc(sizeof(char) * size);
    my_memset(new_var, 0, sizeof(char) * size);
    my_strncpy(new_var, shell->cmd_arg[1], size - 2);
    my_strcat(new_var, "=");
    return (new_var);
}

char *get_newvar2(shell_t *shell, char *new_var)
{
    size_t size = 0;

    size = my_strlen(shell->cmd_arg[1]) + my_strlen(shell->cmd_arg[2]) + 2;
    new_var = malloc(sizeof(char) * size);
    my_memset(new_var, 0, sizeof(char) * size);
    my_strcat(new_var, shell->cmd_arg[1]);
    my_strcat(new_var, "=");
    my_strcat(new_var, shell->cmd_arg[2]);
}

void my_setenv(shell_t *shell)
{
    char *new_var = NULL;
    size_t size = 0;

    if (shell->cmd_arg[1] == NULL) {
        print(shell->envt);
        return ;
    }
    if (shell->cmd_arg[2] == NULL) {
        new_var = get_newvar(shell, new_var);
    } else {
        new_var = get_newvar2(shell, new_var);
    }
    set_env(&shell->envt, new_var, shell->envt->max + 1);
    shell->envt->max += 1;
    free (new_var);
}

void my_unsetenv(shell_t *shell)
{
    char *unset = NULL;

    if (shell->cmd_arg[1] == NULL)
        my_putstr("unsetenv: Too few arguments.\n");
    else {
        unset = malloc(sizeof(char) * (my_strlen(shell->cmd_arg[1]) + 2));
        my_memset(unset, 0, sizeof(char) * (my_strlen(shell->cmd_arg[1]) + 2));
        my_strcat(unset, shell->cmd_arg[1]);
        my_strcat(unset, "=");
        shell->envt = delete_item(shell->envt, unset);
    }
}