/*
** EPITECH PROJECT, 2019
** delivery
** File description:
** open
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my.h"

int fs_open_file(char const *filepath)
{
    int filedesc = open(filepath, O_RDONLY);
}
