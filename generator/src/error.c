/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** error
*/
#include "gene.h"
#include <stdbool.h>
#include <ctype.h>

void my_isnumber(char *str, int i)
{
    if (i == 3)
        return;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            exit(84);
    }
}

void check_error(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
        exit(84);
    for (int i = 1; argv[i] != NULL; i++)
        my_isnumber(argv[i], i);
    for (int i = 1; argv[i] != NULL; i++)
        if (i != 3 && atoi(argv[i]) <= 0)
            exit(84);
}