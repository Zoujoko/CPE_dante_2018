/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** gene
*/

#ifndef GENE_H_
#define GENE_H_
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct dante_s{
    char **map;
    size_t width;
    size_t height;
    int dir_j[4];
    int dir_i[4];
}       dante_t;

enum dir{
    N, W, S, E,
};

//generate struct
char **malloc_map(int width, int height);
void gene_struct(dante_t *gene, char **argv);

//error
void check_error(int argc, char **argv);

//make a perfect maze
void perfect_maze(dante_t *gene);
int random_nbr(size_t mod);

//print the whole map with write and not printf
void print_map(dante_t *gene);

//setup seed to a random one
void setup_random_seed(void);

//you asked for an imperfect there you go
void imperfect(dante_t *gene);

#endif /* !GENE_H_ */