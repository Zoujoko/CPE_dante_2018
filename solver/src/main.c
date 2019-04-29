/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** main
*/

#include "solv.h"

void good_end(solv_t *find)
{
    char temp;

    for (size_t j = 0; find->tab[j]; j++) {
        for (size_t i = 0; find->tab[j][i] != '\0'; i++) {
            temp = find->tab[j][i];
            find->tab[j][i] = (temp == '#') ? '*' : temp;
        }
    }
    find->tab[0][0] = 'o';
    find->tab[find->row - 1][find->col - 1] = 'o';
    for (size_t i = 0; i < find->row; i++) {
        write(1, find->tab[i], strlen(find->tab[i]));
        if (i < find->row - 1)
            write(1, &"\n", 1);
    }
    exit(0);
}

void open_it(char *filepath, solv_t *find)
{
    struct stat *buff;
    int fd;
    int size;
    char *buffer;

    buff = malloc(sizeof(struct stat));
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit(84);
    if (stat(filepath, buff) == -1)
        exit(84);
    size = buff->st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    free(buff);
    find->tab = my_str_to_word_array(buffer, '\n', find);
    error(find);
}

int main(int ac, char **av)
{
    solv_t *find = malloc(sizeof(solv_t));

    if (ac != 2)
        return (84);
    if (!find)
        exit(84);
    srand(time(0));
    open_it(av[1], find);
    algorithm(find);
}
