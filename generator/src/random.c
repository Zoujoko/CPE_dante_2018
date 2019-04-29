/*
** EPITECH PROJECT, 2019
** generator
** File description:
** random
*/

#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include "gene.h"

void setup_random_seed(void)
{
    unsigned int seed;
    int fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1)
        return srand(42);
    if (read(fd, &seed, sizeof(seed)) != sizeof(seed))
        return close(fd), srand(42);
    printf("%u\n", seed);
    srand(seed);
    close(fd);
}

int random_nbr(size_t mod)
{
    return (rand() % mod);
}
