/*
** EPITECH PROJECT, 2019
** solver
** File description:
** new_algo
*/

#include "solv.h"

void have_finished(solv_t *solv)
{
    static int i = 0;

    if (solv->i == solv->col - 1 && solv->j == solv->row - 1) {
        good_end(solv);
    }
    if (solv->i == 0 && solv->j == 0 && i > 2) {
        printf("no solution found");
        exit(84);
    }
    i++;
}

void start_loop(solv_t *solv, int dir)
{
    solv->ni = 0;
    solv->nj = 0;

    if (dir == 0 && solv->i + 1 < solv->col) {
        solv->ni = 1;
    }
    if (dir == 1 && solv->j + 1 < solv->row) {
        solv->nj = 1;
    }
    if (dir == 2 && solv->i != 0) {
        solv->ni = -1;
    }
    if (dir == 3 && solv->j != 0) {
        solv->nj = -1;
    }
}

int check_possible(solv_t *solv, bool move)
{
    int nj = solv->nj;
    int ni = solv->ni;

    if ((move && solv->tab[solv->j + nj][solv->i + ni] == '*') ||
        (!move && solv->tab[solv->j + nj][solv->i + ni] == 'o')) {
        solv->tab[solv->j][solv->i] = (move) ? 'o' : '#';
        solv->j += nj;
        solv->i += ni;
        return (1);
        }
    else
        return (0);
}

void check_end(int *checks, int *move)
{
    if (move[0] == true && checks[0] > 3) {
        move[0] = false;
        checks[0] = 0;
    }
    if (move[0] == false && checks[0] > 4) {
        move[0] = false;
        checks[0] = 0;
    }
}

void algorithm(solv_t *solv)
{
    int dir = 0;
    int checks = 0;
    int move = true;

    solv->j = 0;
    solv->i = 0;
    while (1) {
        start_loop(solv, dir);
        if (check_possible(solv, move) == 1) {
            move = true;
            checks = 0;
            dir = 0;
        }
        else {
            dir = (dir + 1) % 4;
            checks++;
            check_end(&checks, &move);
        }
        have_finished(solv);
    }
}