/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
