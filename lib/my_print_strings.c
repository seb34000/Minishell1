/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_print_strings
*/

#include "../include/shell.h"

void my_putchar(char const c)
{
    write (1, &c, 1);
}

void my_putstr(char const *str)
{
    size_t i = 0;

    for (;str[i]; i++) {
        my_putchar(str[i]);
    }
}

void my_putstr_nl(char const *str)
{
    size_t i = 0;

    for (;str[i]; i++) {
        my_putchar(str[i]);
    }
    my_putchar('\n');
}

void my_put_array(char **array)
{
    size_t i = 0;

    for (;array[i]; i++) {
        my_putstr_nl(array[i]);
    }
}