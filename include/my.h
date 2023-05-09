/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef __MY_H__
    #define __MY_H__

    #include <stdarg.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/sysmacros.h>
    #include <stdbool.h>
    #include <pwd.h>
    #include <grp.h>

    int my_ls(int *flags);
    void my_putchar(char c);
    int my_put_nbr(int n);
    int my_putstr(char const *str);
    int my_lsa(char **argv);
    int main(int argc, char **argv);
    int my_printf(const char *format, ...);
    int lsd(int argc, char **argv);
    int my_strlen(const char str[]);
    void open_directory(char *name_file, int *flags);
    int ls_other(int *flags, char **name_file);
    int lsl(char *name_file, int *flags);
    void affiche_type(struct stat sb);

#endif /* !__MY_H__ */
