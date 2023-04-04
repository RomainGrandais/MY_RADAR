/*
** EPITECH PROJECT, 2022
** count_A_T.c
** File description:
** count A and T in buffer
*/

int count_t(char *buff)
{
    int count = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == 'T') {
            count ++;
        }
    }
    return count;
}

int count_a(char *buff)
{
    int count = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == 'A') {
            count ++;
        }
    }
    return count;
}