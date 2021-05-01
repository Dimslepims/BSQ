/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** count
*/

int count_lines(char *buffer)
{
    int count_lines = 0;
    int i = 0;

    for (; buffer[i] != '\0'; ++i) {
        if (buffer[i] == '\n')
            ++count_lines;
        }
    return (count_lines - 1);
}

int count_colums(char *buffer)
{
    int count_colums = 0;
    int i = 0;

    for (; buffer[i] != '\n'; ++i);
    ++i;
    for (; buffer[i] != '\n'; ++i) {
        ++count_colums;
        }
    return (count_colums);
}
