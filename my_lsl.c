/*
** EPITECH PROJECT, 2022
** my_lsl.c
** File description:
** my_lsl.c
*/

#include "include/my.h"

char *recup_name(char *name_all)
{
    int compteur = 0; int y = 0;
    char *name_last = malloc(sizeof(char) * 300);
    int z = 0;
    for (int i = 0; name_all[i] != '\0'; i++) {
        if (name_all[i] == '/')
            compteur++;
    }
    while (compteur != 0) {
        if (name_all[y] == '/')
            compteur--;
        y++;
    }
    for (z = 0; name_all[z] != '\0'; z++) {
        name_last[z] = name_all[y];
        y++;
    }
    name_last[z] = '\0';
    return name_last;
}

void affiche_time(struct stat sb)
{
    char *temps = ctime(&sb.st_mtime);
    char *affiche = malloc(sizeof(char) * 13);
    for (int i = 4, y = 0; i < 16; i++, y++)
        affiche[y] = temps[i];
    affiche[12] = '\0';
    my_printf("%s ", affiche);
    free(affiche);
}

int lsl_bis(char *name_file, struct stat sb)
{
    my_printf("%d ", sb.st_nlink);
    my_printf("%s ", getpwuid(sb.st_uid)->pw_name);
    my_printf("%s ", getgrgid(sb.st_gid)->gr_name);
    my_printf("%d ", sb.st_size);
    affiche_time(sb);
    my_printf("%s\n", name_file);
    return 0;
}

void affiche_type(struct stat sb)
{
    if (S_ISDIR(sb.st_mode))
        my_putchar('d');
    if (S_ISCHR(sb.st_mode))
        my_putchar('c');
    if (S_ISLNK(sb.st_mode))
        my_putchar('l');
    if (S_ISREG(sb.st_mode))
        my_putchar('-');
    (sb.st_mode & S_IRUSR) ? my_putchar('r') : my_putchar('-');
    (sb.st_mode & S_IWUSR) ? my_putchar('w') : my_putchar('-');
    (sb.st_mode & S_IXUSR) ? my_putchar('x') : my_putchar('-');
    (sb.st_mode & S_IRGRP) ? my_putchar('r') : my_putchar('-');
    (sb.st_mode & S_IWGRP) ? my_putchar('w') : my_putchar('-');
    (sb.st_mode & S_IXGRP) ? my_putchar('x') : my_putchar('-');
    (sb.st_mode & S_IROTH) ? my_putchar('r') : my_putchar('-');
    (sb.st_mode & S_IWOTH) ? my_putchar('w') : my_putchar('-');
    (sb.st_mode & S_IXOTH) ? my_putstr("x ") : my_putstr("- ");
}

int lsl(char *name_file, int *flags)
{
    char *name_recup = recup_name(name_file);
    if (name_recup[0] != '.' || flags[0] == 1) {
        struct stat sb;
        stat(name_file, &sb);
        affiche_type(sb);
        lsl_bis(name_recup, sb);
    }
    free(name_recup);
}
