/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** big
*/

#include "../include/my.h"

int parse_int_tab_y(int **int_tab, char *buffer)
{
    int y = 0;
    int max_val = 0;
    int lines = count_lines(buffer);
    int columns = count_colums(buffer);

    for (int j = 0; j < lines; ++j) {
        for (int i = 0; i < columns; ++i) {
            if (int_tab[j][i] > max_val) {
                y = j;
                max_val = int_tab[j][i];
            }
        }
    }
    return (y);
}

int parse_int_tab_x(int **int_tab, char *buffer)
{
    int x = 0;
    int max_val = 0;
    int lines = count_lines(buffer);
    int columns = count_colums(buffer);

    for (int j = 0; j < lines; ++j) {
        for (int i = 0; i < columns; ++i) {
            if (int_tab[j][i] > max_val) {
                x = i;
                max_val = int_tab[j][i];
            }
        }
    }
    return (x);
}

int find_square_size(int **int_tab, char *buffer)
{
    int x = 0;
    int lines = count_lines(buffer);
    int columns = count_colums(buffer);

    for (int j = 0; j < lines; ++j) {
        for (int i = 0; i < columns; ++i) {
            if (int_tab[j][i] > x)
                x = int_tab[j][i];
        }
    }
    return (x);
}
