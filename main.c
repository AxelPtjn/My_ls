/*
** EPITECH PROJECT, 2022
** my_ls_test
** File description:
** main
*/

#include "include/my.h"

int detect_letter(char *argv, int *flags)
{
    for (int detect_ind = 1; argv[detect_ind] != '\0'; detect_ind++) {
        if (argv[detect_ind] == 'a' && flags[0] == 0)
            flags[0] = 1;
        if (argv[detect_ind] == 't' && flags[1] == 0)
            flags[1] = 1;
        if (argv[detect_ind] == 'r' && flags[2] == 0)
            flags[2] = 1;
        if (argv[detect_ind] == 'd' && flags[3] == 0)
            flags[3] = 1;
        if (argv[detect_ind] == 'R' && flags[4] == 0)
            flags[4] = 1;
        if (argv[detect_ind] == 'l' && flags[5] == 0)
            flags[5] = 1;
        if (argv[detect_ind] != 'l' && argv[detect_ind] != 'a' &&
            argv[detect_ind] != 't' && argv[detect_ind] != 'r' &&
            argv[detect_ind] != 'd' && argv[detect_ind] != 'R')
            return 84;
    }
    return 0;
}

int get_name(int argc, char **argv)
{
    int compteur = 0;
    for (int i = 1; i != argc; i++) {
        if (argv[i][0] != '-')
            compteur++;
    }
    return compteur;
}

int main(int argc, char **argv)
{
    int res = 0; int flags[6] = {0};
    char **name_file = malloc(sizeof(char *) * (get_name(argc, argv) + 1));
    int y = 0;
    for (int i = 1; i != argc; i++) {
        if (argv[i][0] != '-') {
            name_file[y] = argv[i]; y++;
        } else
            res = detect_letter(argv[i], flags);
    }
    name_file[y] = NULL;
    if (res != 0) {
        free(name_file); return 84;
    }
    if (name_file[0] == NULL) {
        my_ls(flags); return 0;
    }
    if (ls_other(flags, name_file) == 84)
        return 84;
    free(name_file); return 0;
}
