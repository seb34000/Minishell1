/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** char
*/

#include "../include/shell.h"

bool is_a_letter(char const c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return (true);
    }
    return (false);
}

bool have_a_letter(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') \
        || (str[i] >= 'A' && str[i] <= 'Z')) {
            return (true);
        }
    }
    return (false);
}