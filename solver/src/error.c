/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** epitech
*/

#include "solv.h"

void error(solv_t *find)
{
    if (find->tab[0][0] != '*') {
        printf("no solution found");
        exit(84);
    }
    if (find->tab[find->row - 1][find->col - 1] != '*') {
        printf("no solution found");
        exit(84);
    }
}
