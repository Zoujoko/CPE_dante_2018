/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "gene.h"

void print_map(dante_t *gene)
{
    for (size_t l = 0; gene->map[l] != NULL; l++) {
        printf("%s", gene->map[l]);
        if (l < gene->height - 1)
            putchar('\n');
    }
}

int main(int argc, char **argv)
{
    dante_t *gene = malloc(sizeof(dante_t));

    if (!gene)
        return 84;
    srand(time(0));
    check_error(argc, argv);
    gene_struct(gene, argv);
    perfect_maze(gene);
    if (argc == 3)
        imperfect(gene);
    print_map(gene);
}
