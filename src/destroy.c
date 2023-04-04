/*
** EPITECH PROJECT, 2022
** destroy.c
** File description:
** destroy all
*/

#include <structure.h>
#include <my.h>

void destroy_setting(setting_t *setting)
{
    sfRenderWindow_destroy(setting->window);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(
    (sfSprite *)setting->map_sp));
    sfSprite_destroy(setting->map_sp);
    sfClock_destroy(setting->clock);
    sfClock_destroy(setting->clock_moove);
    sfFont_destroy(setting->police);
    sfText_destroy(setting->seconde_txt);
    sfText_destroy(setting->minute_txt);
    sfText_destroy(setting->point_txt);
    sfText_destroy(setting->usage_L);
    sfText_destroy(setting->usage_S);
}

plane_t *destroy(plane_t *plane, setting_t *setting)
{
    destroy_setting(setting);
    if (setting->nb_plane > 0)
        sfTexture_destroy((sfTexture *)sfSprite_getTexture(
        (sfSprite *)plane[0].plane_sp));
    for (int i = 0; i < setting->nb_plane; i++) {
        sfSprite_destroy(plane[i].plane_sp);
        sfRectangleShape_destroy(plane[i].rectagle);
    }
    return plane;
}

tower_t *destroy_tower(tower_t *tower, setting_t *setting)
{
    if (setting->nb_plane > 0)
        sfTexture_destroy((sfTexture *)sfSprite_getTexture(
        (sfSprite *)tower[0].tower_sp));
    for (int i = 0; i < setting->nb_tower; i++) {
        sfSprite_destroy(tower[i].tower_sp);
        sfCircleShape_destroy(tower[i].circle);
    }
    return tower;
}