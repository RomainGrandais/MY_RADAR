/*
** EPITECH PROJECT, 2022
** mooove_plane.c
** File description:
** moove_plane
*/

#include <structure.h>
#include <my.h>

plane_t *moove_plane(setting_t *setting, plane_t *plane)
{
    double time = sfTime_asSeconds(
        sfClock_getElapsedTime(setting->clock_moove));
    sfVector2f scale = {0, 0};

    for (int i = 0; i < setting->nb_plane; i++) {
        if (plane[i].visible == 1) {
            sfSprite_move(plane[i].plane_sp, (sfVector2f){(plane[i].x2 /
            plane[i].z) * time, (plane[i].y2 / plane[i].z) * time});
            sfRectangleShape_move(plane[i].rectagle, (sfVector2f){(plane[i].x2 /
            plane[i].z) * time, (plane[i].y2 / plane[i].z) * time});
            plane[i].nb += time;
        }
        if (plane[i].nb >= plane[i].z) {
            sfSprite_setScale(plane[i].plane_sp, scale);
            sfRectangleShape_setScale(plane[i].rectagle, scale);
            plane[i].arrive = 1;
        }
        sfClock_restart(setting->clock_moove);
    }
    return plane;
}