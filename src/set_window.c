/*
** EPITECH PROJECT, 2022
** set_window.c
** File description:
** set window for my_radar
*/

#include <structure.h>
#include <my.h>

void set_usage(setting_t *setting)
{
    setting->usage_L = sfText_create();
    setting->usage_S = sfText_create();
    sfText_setFont(setting->usage_L, setting->police);
    sfText_setScale(setting->usage_L, (sfVector2f){0.5, 0.5});
    sfText_setPosition(setting->usage_L, (sfVector2f){1350, 1000});
    sfText_setFont(setting->usage_S, setting->police);
    sfText_setScale(setting->usage_S, (sfVector2f){0.5, 0.5});
    sfText_setPosition(setting->usage_S, (sfVector2f){1350, 970});
}

void set_text(setting_t *setting)
{
    setting->police = sfFont_createFromFile("textures/Icecold.ttf");
    setting->seconde_txt = sfText_create();
    sfText_setPosition(setting->seconde_txt, (sfVector2f){1850, 15});
    sfText_setScale(setting->seconde_txt, (sfVector2f){1.5, 1.8});
    setting->minute_txt = sfText_create();
    sfText_setPosition(setting->minute_txt, (sfVector2f){1790, 15});
    sfText_setScale(setting->minute_txt, (sfVector2f){1.5, 1.8});
    setting->point_txt = sfText_create();
    sfText_setPosition(setting->point_txt, (sfVector2f){1825, 15});
    sfText_setScale(setting->point_txt, (sfVector2f){1.5, 1.8});
    sfText_setFont(setting->seconde_txt, setting->police);
    sfText_setFont(setting->minute_txt, setting->police);
    sfText_setFont(setting->point_txt, setting->police);
    set_usage(setting);
}

void set_window(setting_t *setting)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfTexture *map_tex = sfTexture_createFromFile("textures/map.png", NULL);

    setting->window = sfRenderWindow_create(mode, "MY_RADAR",
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(setting->window, 60);
    setting->map_sp = sfSprite_create();
    sfSprite_setTexture(setting->map_sp, map_tex, sfTrue);
    setting->clock = sfClock_create();
    setting->clock_moove = sfClock_create();
    setting->L = 0;
    setting->S = 0;
    setting->minute = 0;
    set_text(setting);
}