/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** destroy
*/

#include "../include/shell.h"

void destroy_path_bin(shell_t *shell)
{
    int i = 0;

    for (; shell->path_bin[i]; i++) {
        free (shell->path_bin[i]);
        shell->path_bin[i] = NULL;
    }
}