/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** compare 2 char *
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int i;

    if (len_s1 > len_s2) {
        i = len_s2;
        return (s1[i] * 1);
    }
    if (len_s1 < len_s2) {
        i = len_s1;
        return (s2[i] * -1);
    }
    if (len_s1 == len_s2)
        return (0);
    return (0);
}
