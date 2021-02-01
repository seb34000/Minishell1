/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "../include/shell.h"

int main(int ac, char **av, char **env)
{
    shell_t shell = {0};

    init_struct(&shell, env);
    get_command(&shell);
}