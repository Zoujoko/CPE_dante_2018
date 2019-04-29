/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** gene
*/

#ifndef SOLV_H_
#define SOLV_H_

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <time.h>

typedef struct solv_s{
    char **tab;
    size_t col;
    size_t j;
    size_t i;
    int ni;
    int nj;
    size_t row;
} solv_t;

char **my_str_to_word_array(char *str, char delim, solv_t *find);
void error(solv_t *find);
int path_char(solv_t *find, int i, int j);
int path_int(solv_t *find, int i, int j);
void transform_int(solv_t *find);
int compt(solv_t *find);
void algorithm(solv_t *solv);
void good_end(solv_t *find);
#endif /* !SOLV_H_ */
