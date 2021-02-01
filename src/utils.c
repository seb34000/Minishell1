/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** utils
*/

#include "../include/shell.h"

void prompt_shell(shell_t *shell)
{
    if (isatty(STDIN_FILENO) == 1)
        write(1, "$> ", 3);
}

void prompt_shell_leave(void)
{
    write(1, "Goodbye my friend\n", 18);
}

void prompt_shell_error(char *str)
{
    my_putstr(str);
    my_putstr_nl(": Command not found");
}

int testeur(shell_t *shell, char *path)
{
    if (access(path, F_OK) == -1) {
        cd_error(shell, path);
        return (-1);
    }
    return (0);
}