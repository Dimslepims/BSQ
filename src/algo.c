/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** algo
*/

#include "../include/my.h"

int check_corners(int **int_tab, int i, int j)
{
    int left = int_tab[i][j - 1];
    int up = int_tab[i - 1][j];
    int diago = int_tab[i - 1][j - 1];
    int min = diago >= left ? left : diago;

    return ((min >= up ? up : min) + 1);
}

int **square(int **int_tab, char *buffer)
{
    int lines = count_lines(buffer);
    int columns = count_colums(buffer);

    for (int i = 1; i < lines; ++i) {
        for (int j = 1; j < columns; ++j) {
            if (int_tab[i][j] == 1) {
                int_tab[i][j] = check_corners(int_tab, i, j);
            } else
                int_tab[i][j] = 0;
        }
    }
    return (int_tab);
}
