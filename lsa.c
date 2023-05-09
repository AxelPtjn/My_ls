/*
** EPITECH PROJECT, 2022
** B-PSU-100-LYN-1-1-myls-axel.petitjean
** File description:
** lsa
*/

#include "include/my.h"

int my_lsa(char **argv)
{
    DIR *folder;
    struct dirent *entry;
    folder = opendir(".");

    while (entry = readdir(folder)) {
        my_putstr(entry->d_name);
        my_putchar('\n');
    }
    closedir(folder);

    return 0;
}
