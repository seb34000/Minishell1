/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** parsing
*/

#include "../include/shell.h"

unsigned int word_nbr(char const *cmd)
{
    unsigned int i = 0;
    unsigned int word = 0;

    for (; cmd[i]; i++) {
        if (is_a_letter(cmd[i]) && (cmd[i + 1] == ' ') \
        || cmd[i + 1] == '\0' || cmd[i + 1] == '\n' \
        || cmd[i + 1] == '\t')
            word++;
    }
    return (word);
}

void parsing_command(char *cmd, shell_t *shell)
{
    char *ptr = NULL;
    char *sep = " ";
    int i = 0;

    shell->cmd_arg = malloc(sizeof(char *) * (word_nbr(cmd) + 1));
    my_memset(shell->cmd_arg, 0, sizeof(char *) * (word_nbr(cmd) + 1));
    ptr = strtok(cmd, sep);
    while (ptr) {
        shell->cmd_arg[i] = my_strdup(ptr);
        i++;
        ptr = strtok(NULL, sep);
    }
    if (i == 1) {
        shell->cmd_arg[0][my_strlen(shell->cmd_arg[0]) - 1] = '\0';
    }
}

unsigned int nbr_path(char const *path)
{
    unsigned int i = 0;
    unsigned int word = 0;

    for (; path[i]; i++) {
        if (path[i] == ':')
            word++;
    }
    return (word + 1);
}

void parsing_path(char *path, shell_t *shell)
{
    char *ptr = NULL;
    char *sep = ":";
    int i = 0;

    shell->path_bin = malloc(sizeof(char *) * (nbr_path(path) + 4));
    my_memset(shell->path_bin, 0, sizeof(char *) * (nbr_path(path) + 4));
    ptr = strtok(path, sep);
    while (ptr) {
        shell->path_bin[i] = malloc(sizeof(char) * my_strlen(ptr) + 1);
        shell->path_bin[i] = my_strdup(ptr);
        i++;
        ptr = strtok(NULL, sep);
    }
}