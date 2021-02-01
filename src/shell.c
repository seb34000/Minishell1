/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** shell
*/

#include "../include/shell.h"

void get_path(shell_t *shell)
{
    char *path_bin = NULL;
    bool test = false;
    int test2 = 0;
    var_env_t *env = shell->envt;

    for (; env; env = env->next) {
        test2 = my_strncmp(env->value, "PATH=", 5);
        if (test2 == 0) {
            test = true;
            break;
        }
    }
    path_bin = (test = true) ? my_strdup_debug(&env->value[5], \
    path_bin): my_strdup_debug(\
    "/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin", path_bin);
    parsing_path(path_bin, shell);
}

void command_tcheck(char *cmd)
{
    for (int i = 0; cmd[i]; i++) {
        if ((cmd[i] == 92) && (cmd[i + 1] == 't' || cmd[i + 1] == 'n')) {
            cmd[i] = ' ';
            cmd[i + 1] = ' ';
        }
    }
}

void get_command2(shell_t *shell)
{
    if (find_cmd_built(shell) == false) {
        get_path(shell);
        get_finaly_path(shell);
        lauch_exec(shell);
    }
}

void get_command(shell_t *shell)
{
    char *cmd = NULL;
    size_t len = 0;

    prompt_shell(shell);
    while (getline(&cmd, &len, stdin) > 0) {
        command_tcheck(cmd);
        if (cmd != NULL && have_a_letter(cmd) == true) {
            shell->cmd_arg = split_string(cmd);
            get_command2(shell);
        }
        prompt_shell(shell);
    }
    if (isatty(STDIN_FILENO) == 1)
        my_putchar('\n');
}