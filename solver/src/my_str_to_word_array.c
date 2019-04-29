/*
** EPITECH PROJECT, 2018
** test
** File description:
** yes
*/
#include "solv.h"

int my_str_lim(char *str, char delim, int i, solv_t *find)
{
    int line = 0;

    while (str[i] != delim && str[i] != '\0') {
            i++;
            line++;
    }
    find->col = line;
    return (line);
}

int get_lines(char *str, char delim, solv_t *find)
{
    int i = 0;
    int line = 0;

    while (str[i] != '\0') {
        if (str[i] == delim) {
            line++;
        }
        i++;
    }
    line++;
    find->row = line;
    return (line);
}

char **my_str_to_word_array(char *str, char delim, solv_t *find)
{
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    char **map = malloc(sizeof(char *) * (get_lines(str, delim, find) + 1));

    while (j < find->row) {
        map[j] = malloc(sizeof(char) * ((my_str_lim(str, delim, i, find)) + 1));
        while (k < find->col) {
            map[j][k] = str[i];
            k++;
            i++;
        }
        i++;
        map[j][k] = '\0';
        k = 0;
        j++;
    }
    map[j] = NULL;
    return (map);
}
