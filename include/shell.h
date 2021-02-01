/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** shell
*/

#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct var_env_s {
    int max;
    int index;
    char *value;
    struct var_env_s *next;
} var_env_t;

typedef struct shell_s {
    char **env;
    char **cmd_arg;
    char **path_bin;
    var_env_t *envt;
} shell_t;

/* LIB */
//concat two string
char *my_strcat(char *dest, char const *src);
//duplicate string
char *my_strdup(char const *src);
//size of string
unsigned int my_strlen(char const *str);
//compare two  string
int my_strncmp(char const *s1, char const *s2, int n);
//putchar
void my_putchar(char const c);
//putstr
void my_putstr(char const *str);
//putstr with \n
void my_putstr_nl(char const *str);
//print 2d array
void my_put_array(char **array);
//cpy str
char *my_strcpy (char *dest, char const *src);
//cpy str frop n
char *my_strncpy(char *dest, char const *src, int n);
//malloc string and init
char *my_str_malloc(char *str, size_t size);
//Mymemset
void *my_memset(void *str, int value, size_t size);
//check if is a letter
bool is_a_letter(char const c);
//debug for my_strdup
char *my_strdup_debug(char const *src, char *str);
//split str
char **split_string(char *str);
//have a letter
bool have_a_letter(char const *str);

/* List for var env*/
//get index for unset
int get_unset_index(char *value, var_env_t *env);
//create new list
var_env_t *create_list(char *value);
//set new element in list
void set_env(var_env_t **list, char *var, int index);
//unset element in list
int unset_env(var_env_t **list, unsigned int unset_index);
int unset_env2(var_env_t **list, char *value);
var_env_t *delete_item(var_env_t *curr, char const *str);
//print list
void print(var_env_t *list);
//create new list
var_env_t *set_list(char **env);
//len of 2d array
size_t my_ptrlen(char **tab);
//serach
var_env_t *search_list(char *find, var_env_t *envt);
//sort env
void sort_env(var_env_t **envt);
/* END LIST */

/* SHELL */
void get_command(shell_t *shell);
void command_tcheck(char *cmd);
void get_path(shell_t *shell);
void get_finaly_path(shell_t *shell);
void init_struct(shell_t *shell, char **env);
void parsing_command(char *cmd, shell_t *shell);
void parsing_path(char *path, shell_t *shell);
void destroy_path_bin(shell_t *shell);
void exec_command(shell_t *shell);
void lauch_exec(shell_t *shell);
void prompt_shell(shell_t *shell);
void prompt_shell_leave(void);
void prompt_shell_error(char *str);
bool find_cmd_built(shell_t *shell);
char *my_strcpy_mod (char *dest, char const *src);
unsigned int word_nbr(char const *cmd);
bool debug(shell_t *shell);
void my_cd(shell_t *shell);
void my_env(shell_t *shell);
void my_setenv(shell_t *shell);
void my_unsetenv(shell_t *shell);
void my_exit(shell_t *shell);
int get_index(shell_t *shell, char const *cmd[]);
bool find_cmd_built(shell_t *shell);

//CD
void cd_home(shell_t *shell);
void cd_parent(shell_t *shell);
void cd_dir(shell_t *shell);
void cd_dir_test(shell_t *shell);
void cd_error(shell_t *shell, char *path);
int get_idx_path(char *path);
void cd_error_dir(shell_t *shell, char *path);
void cd_error_dir2(shell_t *shell);
int testeur(shell_t *shell, char *path);

# define TA_ALLOFF  "\033[00m"
# define TA_BOLD    "\033[01m"
# define TA_UNDERSCORE  "\033[04m"
# define TA_BLINK   "\033[05m"
# define TA_REVVIDEO    "\033[07m"
# define TA_CONCEALED   "\033[08m"

/*
**  FOREGROUND COLORS
*/

# define FG_BLACK   "\033[30m"
# define FG_RED "\033[31m"
# define FG_GREEN   "\033[32m"
# define FG_YELLOW  "\033[33m"
# define FG_BLUE    "\033[34m"
# define FG_MAGENTA "\033[35m"
# define FG_CYAN    "\033[36m"
# define FG_WHITE   "\033[37m"

/*
**  BACKGROUND COLORS
*/

# define BG_BLACK   "\033[40m"
# define BG_RED "\033[41m"
# define BG_GREEN   "\033[42m"
# define BG_YELLOW  "\033[43m"
# define BG_BLUE    "\033[44m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN    "\033[46m"
# define BG_WHITE   "\033[47m"

# define BG_CLEAR   "\033[00m"

#endif /* !SHELL_H_ */
