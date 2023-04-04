/*
** EPITECH PROJECT, 2022
** display_tower.c
** File description:
** display tower
*/

#include <structure.h>
#include <math.h>

plane_t *set_plane_moove(plane_t *plane, setting_t setting, int i)
{
    plane[i].z = sqrt(pow(plane[i].x1 - plane[i].x,
        2) + pow(plane[i].y1 - plane[i].y, 2)) / plane[i].speed;
    plane[i].x2 = plane[i].x1 - plane[i].x;
    plane[i].y2 = plane[i].y1 - plane[i].y;
    plane[i].nb = 0;
    plane[i].arrive = 0;
    return plane;
}

plane_t *set_plane(plane_t *plane, setting_t setting)
{
    sfTexture *plane_tex = sfTexture_createFromFile("textures/plane.png", NULL);

    for (int i = 0; i < setting.nb_plane; i++) {
        plane[i].plane_sp = sfSprite_create();
        sfSprite_setTexture(plane[i].plane_sp, plane_tex, sfTrue);
        sfSprite_setPosition(plane[i].plane_sp,
            (sfVector2f){plane[i].x, plane[i].y});
        plane = set_plane_moove(plane, setting, i);
        plane[i].visible = 0;
        sfSprite_setScale(plane[i].plane_sp, (sfVector2f){0.08, 0.08});
        plane[i].rectagle = sfRectangleShape_create();
        sfRectangleShape_setFillColor(plane[i].rectagle, sfTransparent);
        sfRectangleShape_setOutlineThickness(plane[i].rectagle, 2.0);
        sfRectangleShape_setSize(plane[i].rectagle, (sfVector2f){20, 20});
        sfRectangleShape_setPosition(plane[i].rectagle,
            (sfVector2f){(plane[i].x), (plane[i].y)});
    }
    return plane;
}

void disable_display_plane(plane_t *plane, setting_t setting, int i)
{
    if (setting.L == 0)
        sfRenderWindow_drawRectangleShape(setting.window,
            plane[i].rectagle, NULL);
    if (setting.S == 0)
        sfRenderWindow_drawSprite(setting.window, plane[i].plane_sp, NULL);
}

void display_plane(plane_t *plane, setting_t setting)
{
    sfTime time;

    for (int i = 0; i < setting.nb_plane; i++) {
        time = sfClock_getElapsedTime(setting.clock);
        if (sfTime_asSeconds(time) >= plane[i].start) {
            plane[i].visible = 1;
            disable_display_plane(plane, setting, i);
        }
    }
}