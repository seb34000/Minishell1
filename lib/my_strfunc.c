/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_string
*/

#include "../include/shell.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int t = 0;

    while (dest[i] != '\0') {
        i++;
    }
    for (;src[t] != '\0'; ++t) {
        dest[i] = src[t];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    int i = 0;
    char *str = NULL;

    str = my_str_malloc(str, my_strlen(src) + 1);
    for (; src[i]; i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return (str);
}

char *my_strdup_debug(char const *src, char *str)
{
    int i = 0;

    str = my_str_malloc(str, my_strlen(src) + 1);
    for (; src[i]; i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return (str);
}

unsigned int my_strlen(char const *str)
{
    unsigned int i = 0;

    for (;str[i]; i++);
    return (i);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (n == 0)
        return (0);
    if (!s1[0] && !s2[0])
        return (0);
    if (s1[0] == s2[0])
        return (my_strncmp(s1 + 1, s2 + 1, n - 1));
    return (s1[0] - s2[0]);
}