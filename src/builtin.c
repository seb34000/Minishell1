/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** builtin
*/

#include "../include/shell.h"

int get_index(shell_t *shell, char const *cmd[])
{
    for (int i = 0; cmd[i]; i++) {
        if (my_strncmp(cmd[i], shell->cmd_arg[0], my_strlen(cmd[i])) == 0) {
            return (i);
        }
    }
    return (-1);
}

bool find_cmd_built(shell_t *shell)
{
    char const *cmd[6] = {"cd", "env", "setenv", "unsetenv", "exit", 0};
    void (*builtin[5])(shell_t *) = \
    {my_cd, my_env, my_setenv, my_unsetenv, my_exit};
    int idx_flag = 0;

    idx_flag = get_index(shell, cmd);
    if (idx_flag != -1) {
        (builtin[idx_flag](shell));
        return (true);
    }
    return (false);
}