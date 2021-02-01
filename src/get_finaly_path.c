/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** get_finaly_path
*/

#include "../include/shell.h"

char *get_finally_path2(shell_t *shell, size_t *size, char *bin)
{
    int i = 0;

    for (; shell->path_bin[i]; i++) {
        *size = my_strlen(shell->path_bin[i]) + 1 + \
        my_strlen(shell->cmd_arg[0]);
        bin = malloc(sizeof(char) * *size + 2);
        my_strncpy(bin, shell->path_bin[i], my_strlen(shell->path_bin[i]));
        my_strcat(bin, "/");
        my_strcat(bin, shell->cmd_arg[0]);
        if (debug(shell) == false)
            bin[*size - 1] = '\0';
        if (access(bin, F_OK) == 0)
            break ;
        else {
            free(bin);
            bin = NULL;
        }
    }
    return (bin);
}

void get_finaly_path(shell_t *shell)
{
    char *bin = NULL;
    size_t size = 0;

    if (shell->cmd_arg[0][0] != '/' && \
    my_strncmp(shell->cmd_arg[0], "./", 2) != 0) {
        bin = get_finally_path2(shell, &size, bin);
    }
    if (bin == NULL)
        return ;
    if (debug(shell) == true)
        bin[size] = '\0';
    shell->cmd_arg[0] = malloc(sizeof(char) * size + 2);
    shell->cmd_arg[0] = bin;
}