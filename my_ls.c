/*
** EPITECH PROJECT, 2022
** my_ls.c
** File description:
** my_ls.c
*/

#include "include/my.h"

int my_ls(int *flags)
{
    DIR *folder;
    struct dirent *entry;
    folder = opendir(".");
    while (entry = readdir(folder)) {
        if ((entry->d_name[0] != '.' || flags[0] == 1) && flags[5] != 1) {
            my_putstr(entry->d_name);
            my_putchar('\n');
        }
        if (flags[5] == 1)
            lsl(entry->d_name, flags);
    }
    closedir(folder);
    return 0;
}
