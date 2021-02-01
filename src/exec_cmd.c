/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** exec_cmd
*/

#include "../include/shell.h"

int exec(char *path, char **args, shell_t *shell)
{
    pid_t child = 0;
    int sig = 0;

    child = fork();
    if (child == 0) {
        if (execve(path, args, shell->env) == -1)
            prompt_shell_error(shell->cmd_arg[0]);
    }
    waitpid(child, &sig, 0);
    kill(child, SIGTERM);
    if (sig == SIGSEGV)
        my_putstr("Segmentation Fault\n");
    if (sig == SIGFPE)
        my_putstr("Floating Point\n");
}

size_t my_ptrlen(char **tab)
{
    size_t i = 0;

    for (; tab[i]; i++);
    return (i);
}

bool if_is_on_path(char *arg)
{
    if (my_strncmp(arg, "/", 1) == 0 && is_a_letter(arg[1]))
        return (true);
    return (false);
}

int lauch_exec2(char **args, shell_t *shell, char *path, int i, bool test)
{
    if (args[0][0] != '/') {
        prompt_shell_error(args[0]);
        return (-1);
    }
    if (test == false \
    && my_strncmp(&args[0][my_strlen(args[0]) - 3], "pwd", 3) != 0 \
    && my_strncmp(&args[0][my_strlen(args[0]) - 4], "echo", 4) != 0 \
    && my_strncmp(&args[0][my_strlen(args[0]) - 2], "id", 2) != 0 \
    && my_strncmp(&args[0][my_strlen(args[0]) - 3], "cat", 3) != 0 \
    && my_strncmp(&args[0][my_strlen(args[0]) - 2], "rm", 2) != 0) {
        args[i] = malloc(sizeof(char));
        args[i] = my_strdup(".");
        args[i + 1] = NULL;
    } else
        args[i] = NULL;
    exec(path, args, shell);
}

void lauch_exec(shell_t *shell)
{
    char *path = shell->cmd_arg[0];
    int i = 0;
    bool test = false;
    size_t size = my_ptrlen(shell->cmd_arg);
    char **args = malloc(sizeof(char *) * (size + 4));

    my_memset(args, 0, sizeof(char *) * (size + 4));
    for (;i < size; i++) {
        if (i > 0 && if_is_on_path(shell->cmd_arg[i])) {
            if (shell->cmd_arg[i][my_strlen(shell->cmd_arg[i])] == '\n')
                my_strncpy(args[i + 1], shell->cmd_arg[i], \
                my_strlen(shell->cmd_arg[i]) - 1);
            else
                args[i] = my_strdup(shell->cmd_arg[i]);
            test = true;
        } else if (i <= size && shell->cmd_arg[i] != NULL)
            args[i] = my_strdup(shell->cmd_arg[i]);
    }
    if (lauch_exec2(args, shell, path, i, test) == -1)
        return ;
}