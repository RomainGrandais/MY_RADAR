/*
** EPITECH PROJECT, 2022
** my_strstr.c
** File description:
** find the first occurence of second string in the first string
*/
#include<stdio.h>

int pass(char *str, char const *to_find, int i, int j)
{
    while (to_find[j] == str[i + j]) {
        if (to_find[j + 1] == '\0')
            return (1);
        j++;
    }
    i++;
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j;

    while (str[i] != '\0') {
        j = 0;
        if (pass(str, to_find, i, j) != 0)
            return (str + i);
        i++;
    }
    return (NULL);
}
