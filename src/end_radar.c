/*
** EPITECH PROJECT, 2022
** end_radar.c
** File description:
** end of my_radar
*/

#include <structure.h>
#include <my.h>

void end_radar(plane_t *plane, setting_t *setting)
{
    for (int i = 0; i < setting->nb_plane; i++) {
        if (plane[i].arrive == 0)
            return;
    }
    sfRenderWindow_close(setting->window);
}