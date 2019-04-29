/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** perfect
*/
#include <sys/time.h>
#include "gene.h"

void end(dante_t *gene, int random)
{
    if (random == 0) {
        gene->map[gene->height - 2][gene->width - 1] = '*';
    }
    else if (random == 1) {
        gene->map[gene->height - 1][gene->width - 2] = '*';
    }
}

void cut_this_maze(dante_t *gene, size_t j, size_t i)
{
    int move = rand() % 2;

    if (move == 1) {
        gene->map[j][i] = '*';
        --j;
        gene->map[j][i] = '*';
    }
    if (move == 0) {
        gene->map[j][i] = '*';
        --i;
        gene->map[j][i] = '*';
    }
}

void perfect_maze(dante_t *gene)
{
    size_t j = 2;
    size_t i = 2;

    for (; j < gene->height; j += 2) {
        for (i = 2; i < gene->width; i += 2) {
            cut_this_maze(gene, j, i);
        }
    }
    end(gene, rand() % 2);
}