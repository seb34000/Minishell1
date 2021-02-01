/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_cd_home
*/

#include "../include/shell.h"

char *get_old_home(char *pwd_old, char *oldpwd)
{
    my_memset(pwd_old, 0, sizeof(char) * \
    (my_strlen(oldpwd) + my_strlen("OLDPWD=") + 1));
    my_strcat(pwd_old, "OLDPWD=");
    my_strcat(pwd_old, oldpwd);
    return (pwd_old);
}

char *get_new_home(char *new_pwd, char *path, var_env_t *home)
{
    my_memset(new_pwd, 0, sizeof(char) * \
    (my_strlen(&home->value[5]) + my_strlen("PWD=") + 1));
    my_strcat(new_pwd, "PWD=");
    my_strcat(new_pwd, path);
    return (new_pwd);
}

void free_home(char *path, char *oldpwd)
{
    free(path);
    free(oldpwd);
}

void free_home2(char *pwd_old, char *new_pwd)
{
    free(pwd_old);
    free(new_pwd);
}

void cd_home(shell_t *shell)
{
    var_env_t *home = search_list("HOME=", shell->envt);
    var_env_t *old = search_list("PWD=", shell->envt);
    char *path = my_strdup(&home->value[5]);
    char *oldpwd = my_strdup(&old->value[4]);
    char *pwd_old = malloc(sizeof(char) * \
    (my_strlen(oldpwd) + my_strlen("OLDPWD=") + 1));
    char *new_pwd = malloc(sizeof(char) * \
    (my_strlen(&home->value[5]) + my_strlen("PWD=") + 1));
    int idx = 0;

    pwd_old = get_old_home(pwd_old, oldpwd);
    chdir(path);
    idx = unset_env2(&shell->envt, "OLDPWD=");
    set_env(&shell->envt, pwd_old, idx);
    new_pwd = get_new_home(new_pwd, path, home);
    idx = unset_env2(&shell->envt, "PWD=");
    set_env(&shell->envt, new_pwd, idx);
    free_home(path, oldpwd);
    free_home2(pwd_old, new_pwd);
}