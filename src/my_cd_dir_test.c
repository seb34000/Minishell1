/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_cd_dir_test
*/

#include "../include/shell.h"

char *cd_dir_path(shell_t *shell, char *path, var_env_t *old)
{
    path = NULL;
    path = malloc(sizeof(char) * (my_strlen(shell->cmd_arg[1]) + 2 + \
    my_strlen(&old->value[4])));
    my_memset(path, 0, sizeof(char) * (my_strlen(shell->cmd_arg[1]) + 2 + \
    my_strlen(&old->value[4])));
    my_strcat(path, &old->value[4]);
    my_strcat(path, "/");
    my_strcat(path, shell->cmd_arg[1]);
}

char *cd_dir_oldpath(shell_t *shell, char *oldpath, var_env_t *old)
{
    oldpath = malloc(sizeof(char) * (my_strlen(&old->value[4]) + \
    my_strlen("OLDPWD=") + 1));
    my_memset(oldpath, 0, sizeof(char) * (my_strlen(&old->value[4]) + \
    my_strlen("OLDPWD=") + 1));
    my_strcat(oldpath, "OLDPWD=");
    my_strcat(oldpath, &old->value[4]);
}

char *cd_dir_newpath(shell_t *shell, char *new_path, var_env_t *old)
{
    new_path = malloc(sizeof(char) * (my_strlen(&old->value[4]) + \
    my_strlen("PWD=") + 3 + my_strlen(shell->cmd_arg[1])));
    my_memset(new_path, 0, sizeof(char) * (my_strlen(&old->value[4]) + \
    my_strlen("PWD=") + 3 + my_strlen(shell->cmd_arg[1])));
    my_strcat(new_path, "PWD=");
    my_strcat(new_path, &old->value[4]);
    my_strcat(new_path, "/");
    my_strcat(new_path, shell->cmd_arg[1]);
    my_strcat(new_path, "/");
}

void cd_dir_test2 (shell_t *shell, struct dirent *rd, var_env_t *old)
{
    char *oldpath = NULL;
    char *new_path = NULL;
    int idx = 0;

    chdir(rd->d_name);
    oldpath = cd_dir_oldpath(shell, oldpath, old);
    idx = unset_env2(&shell->envt, "OLDPWD=");
    set_env(&shell->envt, oldpath, idx);
    new_path = cd_dir_newpath(shell, new_path, old);
    idx = unset_env2(&shell->envt, "PWD=");
    set_env(&shell->envt, new_path, idx);
}

void cd_dir_test(shell_t *shell)
{
    var_env_t *old = search_list("PWD=", shell->envt);
    char *path = cd_dir_path(shell, path, old);
    DIR *dirp = opendir("./");
    struct stat sts = {0};
    mode_t type;
    struct dirent *rd;
    bool test = false;

    if (testeur(shell, path) == -1)
        return ;
    while (rd = readdir(dirp)) {
        if (my_strncmp(rd->d_name, shell->cmd_arg[1], \
        my_strlen(shell->cmd_arg[1])) == 0) {
            (rd->d_type == DT_DIR) ? \
            cd_dir_test2(shell, rd, old) : cd_error_dir(shell, path);
        }
    }
    closedir(dirp);
}