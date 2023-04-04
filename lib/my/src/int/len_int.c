/*
** EPITECH PROJECT, 2022
** len_int.c
** File description:
** len of int
*/

int len_int(int nb)
{
    int count = 0;

    while (nb != 0) {
        nb /= 10;
        count++;
    }
    return count;
}