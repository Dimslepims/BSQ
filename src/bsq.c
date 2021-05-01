/*
** EPITECH PROJECT, 2019
** project
** File description:
** bsq
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my.h"

int **tab_of_int(char *buffer, int size)
{
    int lines = count_lines(buffer);
    int **int_tab = malloc(sizeof(int *) * (lines + 1));
    int columns = count_colums(buffer);
    int j = 0;
    int i = 0;

    int_tab[lines] = NULL;
    for (; buffer[i] != '\n'; ++i);
    ++i;
    for (; j < lines; ++j) {
        int_tab[j] = malloc(sizeof(int) * columns);
        for (int p = 0; buffer[i] != '\n'; ++p, ++i) {
            if (buffer[i] == '.')
                int_tab[j][p] = 1;
            if (buffer[i] == 'o')
                int_tab[j][p] = 0;
        }
        ++i;
    }
    return (int_tab);
}

void print_tab(char **tab, char *buffer)
{
    int lines = count_lines(buffer);
    int cols = count_colums(buffer);

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < cols; ++j) {
            my_putchar(tab[i][j]);
        }
        my_putchar('\n');
    }
}

int **put_x(char *buffer, int **int_tab)
{
    int line_of_result = parse_int_tab_y(int_tab, buffer);
    int column_of_result = parse_int_tab_x(int_tab, buffer);
    int square_size = find_square_size(int_tab, buffer);
    int lines = count_lines(buffer);
    int columns = count_colums(buffer);
    int j = square_size;
    int i = square_size;
    int k = column_of_result;

    for (; i > 0; --i, --line_of_result) {
        for (; j > 0; --j, --k) {
            int_tab[line_of_result][k] = -1;
        }
        k = column_of_result;
        j = square_size;
    }
    return (int_tab);
}

char **final_tab(int **int_final_tab, char *buffer)
{
    int lines = count_lines(buffer);
    int columns = count_colums(buffer);
    char **final_tab = malloc(sizeof(char *) * (lines + 1));

    for (int i = 0; i < lines; ++i) {
        final_tab[i] = malloc(sizeof(char) * (columns + 1));
        for (int j = 0; j < columns; ++j) {
            if (int_final_tab[i][j] > 0)
                final_tab[i][j] = '.';
            if (int_final_tab[i][j] < 0)
                final_tab[i][j] = 'x';
            if (int_final_tab[i][j] == 0)
                final_tab[i][j] = 'o';
        }
    }
    return (final_tab);
}

int main(int ac, char **av)
{
    struct stat st;
    stat(av[1], &st);
    int size = st.st_size;
    char *buffer = malloc(sizeof(char) * (size + 1));
    int fd = fs_open_file(av[1]);
    read(fd, buffer, size);
    int **int_tab = square(tab_of_int(buffer, size), buffer);
    int **int_final_tab = put_x(buffer, int_tab);
    char **char_final = final_tab(int_final_tab, buffer);
    print_tab(char_final, buffer);
    return (0);
}
