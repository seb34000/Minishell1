/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_cd
*/

#include "../include/shell.h"

int get_idx_path(char *path)
{
    int i = 0;
    for (;path[i]; i++);
    for (;path[i] != '/'; i--);
    return (i);
}

void cd_error(shell_t *shell, char *path)
{
    my_putstr(shell->cmd_arg[1]);
    my_putstr_nl(": No such file or directory.");
    free(path);
}

void cd_error_dir(shell_t *shell, char *path)
{
    my_putstr(shell->cmd_arg[1]);
    my_putstr_nl(": Not a directory.");
    free(path);
}

void cd_error_dir2(shell_t *shell)
{
    my_putstr(shell->cmd_arg[1]);
    my_putstr_nl(": Not a directory.");
}

void my_cd(shell_t *shell)
{
    if (shell->cmd_arg[1] == NULL) {
        cd_home(shell);
    } else if (my_strncmp(shell->cmd_arg[1], "..", 2) == 0) {
        cd_dir_test(shell);
    } else if (my_strncmp(shell->cmd_arg[1], "/", 1) == 0) {
        cd_dir(shell);
    } else {
        cd_dir_test(shell);
    }
}