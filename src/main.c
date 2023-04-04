/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main for my_radar
*/

#include <my.h>
#include <stdlib.h>
#include <structure.h>
#include <unistd.h>
#include <math.h>

int count_t(char *buff);
int count_a(char *buff);
void set_window(setting_t *setting);
void my_radar(tower_t *tower, plane_t *plane, setting_t setting);
void message(void);

int gest_error(int ac, char *buff)
{
    if (ac != 2) {
        write(2, "Error: Only two arguments must be entered\n", 43);
        return 84;
    }
    if (buff == NULL) {
        write(2, "Error: Wrong filepath\n",22);
        return 84;
    }
    for (int i = 0; buff[i] != '\0'; i++) {
        if (is_digit(buff[i]) != 1 && buff[i] != ' ' &&
        buff[i] != 'A' && buff[i] != 'T' && buff[i] != '\n' && buff[i] != '-') {
            write(2, "Error: script incorrect\n",24);
            return 84;
        }
    }
    return 0;
}

int next_number(char *buff, int i)
{
    while (is_digit(buff[i]) == 1 || buff[i] == 'T' || buff[i] == 'A')
        i++;
    while (buff[i] == ' ')
        i++;
    return i;
}

tower_t *fill_tower(char *buff, tower_t *tower, setting_t setting)
{
    int n = 0;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == 'T') {
            i = next_number(buff, i);
            tower[n].x = my_getnbr(&buff[i]);
            i = next_number(buff, i);
            tower[n].y = my_getnbr(&buff[i]);
            i = next_number(buff, i);
            tower[n].range = my_getnbr(&buff[i]);
            n++;
        }
    }
    return tower;
}

plane_t *fill_plane(char *buff, plane_t *plane, setting_t setting)
{
    int n = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == 'A') {
            i = next_number(buff, i);
            plane[n].x = my_getnbr(&buff[i]);
            i = next_number(buff, i);
            plane[n].y = my_getnbr(&buff[i]);
            i = next_number(buff, i);
            plane[n].x1 = my_getnbr(&buff[i]);
            i = next_number(buff, i);
            plane[n].y1 = my_getnbr(&buff[i]);
            i = next_number(buff, i);
            plane[n].speed = my_getnbr(&buff[i]);
            i = next_number(buff, i);
            plane[n].start = my_getnbr(&buff[i]);
            n++;
        }
    }
    return plane;
}

int main(int ac, char **av)
{
    plane_t *plane = {0};
    tower_t *tower = {0};
    setting_t setting;
    char *buff = make_buffer_ws(av[1]);

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        message();
        return 0;
    }
    if (gest_error(ac, buff) == 84)
        return 84;
    setting.nb_plane = count_a(buff);
    setting.nb_tower = count_t(buff);
    plane = malloc(sizeof(plane_t) * (setting.nb_plane));
    tower = malloc(sizeof(tower_t) * (setting.nb_tower));
    tower = fill_tower(buff, tower, setting);
    plane = fill_plane(buff, plane, setting);
    my_radar(tower, plane, setting);
    return 0;
}