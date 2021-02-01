/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_cd_dir
*/

#include "../include/shell.h"

char *cd_dir_new(char *new_path, shell_t *shell)
{
    my_memset(new_path, 0, sizeof(char) * \
    (my_strlen(shell->cmd_arg[1]) + my_strlen("PWD=") + 1));
    my_strcat(new_path, "PWD=");
    my_strcat(new_path, shell->cmd_arg[1]);
}

char *cd_dir_old(char *old_path, var_env_t *old)
{
    my_memset(old_path, 0, sizeof(char) * \
    (my_strlen(&old->value[4]) + my_strlen("OLDPWD=") + 1));
    my_strcat(old_path, "OLDPWD=");
    my_strcat(old_path, &old->value[4]);
}

int is_dir(const char *name)
{
    int ret = 0;
    DIR* rep = opendir(name);

    if (rep != NULL) {
        closedir(rep);
        ret = 1;
    }

    return (ret);
}

int cd_dir_err(shell_t *shell)
{
    if (testeur(shell, shell->cmd_arg[1]) == -1)
        return ;
    if (is_dir(shell->cmd_arg[1]) == 0) {
        cd_error_dir2(shell);
        return ;
    }
}

void cd_dir(shell_t *shell)
{
    var_env_t *old = search_list("PWD=", shell->envt);
    char *old_path = malloc(sizeof(char) * \
    (my_strlen(&old->value[4]) + my_strlen("OLDPWD=") + 1));
    char *new_path = malloc(sizeof(char) * \
    (my_strlen(shell->cmd_arg[1]) + my_strlen("PWD=") + 1));
    int idx = 0;

    cd_dir_err(shell);
    cd_dir_old(old_path, old);
    cd_dir_new(new_path, shell);
    chdir(shell->cmd_arg[1]);
    idx = unset_env2(&shell->envt, "OLDPWD=");
    set_env(&shell->envt, old_path, idx);
    idx = unset_env2(&shell->envt, "PWD=");
    set_env(&shell->envt, new_path, idx);
    free (old_path);
    free (new_path);
}