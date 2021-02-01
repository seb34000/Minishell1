/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_cd_parent
*/

#include "../include/shell.h"

char *get_old(char *oldpwd, var_env_t *old)
{
    my_strcat(oldpwd, "OLDPWD=");
    my_strcat(oldpwd, &old->value[4]);
    return (oldpwd);
}

char *get_new(char *pwd, char *newpwd)
{
    my_strcat(pwd, "PWD=");
    my_strcat(pwd, newpwd);
    return (pwd);
}

void free_path(char *oldpwd, char *pwd, char *newpwd)
{
    free(oldpwd);
    free(pwd);
    free(newpwd);
}

void cd_parent(shell_t *shell)
{
    var_env_t *old = search_list("PWD=", shell->envt);
    char *oldpwd = my_str_malloc(oldpwd, 7 + my_strlen(&old->value[4]));
    char *pwd = my_str_malloc(pwd, my_strlen(old->value));
    char *newpwd = my_str_malloc(pwd, my_strlen(old->value) + 5);
    int idx = 0;

    if (my_strlen(&old->value[4]) > 1) {
        chdir("../");
        getcwd(newpwd, my_strlen(old->value));
        oldpwd = get_old(oldpwd, old);
        pwd = get_new(pwd, newpwd);
        idx = get_unset_index("PWD=", shell->envt);
        idx = unset_env(&shell->envt, idx);
        set_env(&shell->envt, pwd, idx);
        idx = get_unset_index("OLDPWD=", shell->envt);
        idx = unset_env(&shell->envt, idx);
        set_env(&shell->envt, pwd, idx);
    }
    free_path(oldpwd, pwd, newpwd);
}