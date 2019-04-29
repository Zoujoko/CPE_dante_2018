/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** gene_struct
*/
#include "gene.h"

void fill_map(char *line, int i, int width, int height)
{
    static int turn = 0;

    if (turn == 0 || i == 0)
        line[i] = '*';
    else if (i == width - 1 && turn == height - 1)
        line[i] = '*';
    else
        line[i] = 'X';
    if (i == width - 1)
        turn++;
}

char **malloc_map(int width, int height)
{
    int j = 0;
    int i = 0;
    char **map = malloc(sizeof(char *) * (height + 1));

    if (!map)
        exit(84);
    for (; j < height; j++) {
        map[j] = malloc(sizeof(char) * (width + 1));
        if (!map[j])
            exit(84);
        i = 0;
        for (; i < width; i++)
            fill_map(map[j], i, width, height);
        map[j][i] = '\0';
    }
    map[j] = NULL;
    return (map);
}

void gene_struct(dante_t *gene, char **argv)
{
    gene->height = atoi(argv[2]);
    gene->width = atoi(argv[1]);
    gene->map = malloc_map(atoi(argv[1]), atoi(argv[2]));
}