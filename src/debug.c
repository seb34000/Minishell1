/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "../include/shell.h"

bool debug(shell_t *shell)
{
    int i = 0;

    for (;shell->cmd_arg[i]; i++);
    if (i == 0)
        return (false);
    return (true);
}