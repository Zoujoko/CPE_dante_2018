/*
** EPITECH PROJECT, 2019
** generator
** File description:
** imperfect
*/

#include "gene.h"

void new_star(dante_t *gene, size_t j, size_t i)
{
    int succeed = 0;

    if (gene->map[j - 1][i] == '*' && gene->map[j + 1][i] == '*')
        succeed++;
    if (gene->map[j][i - 1] == '#' && gene->map[j][i + 1] == '#')
        succeed++;
    if (succeed == 2)
        gene->map[j][i] = '*';
}

void imperfect(dante_t *gene)
{
    for (size_t j = 1; j < gene->height - 1; j++) {
        for (size_t i = 1; i < gene->width - 1; i++) {
            new_star(gene, j, i);
        }
    }
}