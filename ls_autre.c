/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-myls-axel.petitjean
** File description:
** ls_autre
*/

#include "include/my.h"

char *recreate_chemin(char *chemin, char *name_file)
{
    int i = 0; int y = 0;
    char *name_all = malloc(sizeof(char) * 30000);
    for (i = 0; name_file[i] != '\0'; i++)
        name_all[i] = name_file[i];
    if (name_all[i - 1] != '/') {
        name_all[i] = '/';
        i++;
    }
    for (y = 0; chemin[y] != '\0'; y++) {
        name_all[i] = chemin[y];
        i++;
    }
    name_all[i] = '\0';
    return name_all;
}

void open_directory(char *name_file, int *flags)
{
    DIR *folder;
    struct dirent *entry;
    folder = opendir(name_file);
    char *name_all;
    while (entry = readdir(folder)) {
        if ((entry->d_name[0] != '.' || flags[0] == 1) && flags[5] != 1) {
            my_putstr(entry->d_name);
            my_putchar('\n');
        }
        if (flags[5] == 1) {
            name_all = recreate_chemin(entry->d_name, name_file);
            lsl(name_all, flags);
            free(name_all);
        }
    }
    closedir(folder);
}

void affiche_file(char *name_file, int *flags)
{
    if (flags[5] == 1) {
        flags[0] = 1;
        lsl(name_file, flags);
    }
    if (flags[5] == 0)
        my_printf("%s\n", name_file);
}

int ls_other(int *flags, char **name_file)
{
    struct stat info;
    if (name_file[1] == NULL) {
        if (stat(name_file[0], &info) != 0)
            return 84;
        if (S_ISREG(info.st_mode) != 0)
            affiche_file(name_file[0], flags);
        else
            open_directory(name_file[0], flags);
    }
    return 0;
}
