/*
** EPITECH PROJECT, 2022
** lib in h
** File description:
** lib
*/

#ifndef MY_H_
    #define MY_H_

    #include <time.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdio.h>
    #include "structure.h"

void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *);
int is_digit(char);
int calculate(int i, char const *str);
int is_neg(char const *str);
int my_showstr(char const *str);
char **pass(char **tab, char const *str, int i, int j);
int mini_printf(const char *s, ...);
int size_file(char *path);
char *make_buffer_ws(char *file);
char *make_buffer(char *file, int size);
int len_int(int nb);
char *int_to_string(int nb);

#endif /* MY_H_*/
