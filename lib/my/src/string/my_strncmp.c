/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** compare two string
*/

int my_strlen(const char *str);

int my_strncmp(const char *s1, const char *s2, int n)
{
    int len_s1 = my_strlen(s1);
    int	len_s2 = my_strlen(s2);
    int i;

    if ((len_s1 > n && len_s2 > n) || (len_s1 == n && len_s2 == n))
        return (0);
    if (len_s1 > n && len_s2 < n) {
        i = len_s2;
        return (s1[i] * 1);
    }
    if (len_s1 < n && len_s2 > n) {
        i = len_s1;
        return (s2[i] * -1);
    }
    return 0;
}
