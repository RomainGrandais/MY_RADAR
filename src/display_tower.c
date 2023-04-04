/*
** EPITECH PROJECT, 2022
** display_tower.c
** File description:
** display tower
*/

#include <structure.h>
#include <my.h>

tower_t *set_circle(tower_t *tower, setting_t setting, int i)
{
    float radius;

    tower[i].circle = sfCircleShape_create();
    radius = (tower[i].range * 1920) / 100;
    sfCircleShape_setFillColor(tower[i].circle, sfTransparent);
    sfCircleShape_setOutlineThickness(tower[i].circle, 2.0);
    sfCircleShape_setOutlineColor(tower[i].circle, sfRed);
    sfCircleShape_setRadius(tower[i].circle, radius);
    sfCircleShape_setOrigin(tower[i].circle,
        (sfVector2f){radius - 10, radius - 20});
    sfCircleShape_setPosition(tower[i].circle,
        (sfVector2f){tower[i].x, tower[i].y});
    return tower;
}

tower_t *set_tower(tower_t *tower, setting_t setting)
{
    sfTexture *tower_tex = sfTexture_createFromFile("textures/tower.png", NULL);
    sfVector2f posi_tower;
    float radius;

    for (int i = 0; i < setting.nb_tower; i++) {
        tower[i].tower_sp = sfSprite_create();
        sfSprite_setTexture(tower[i].tower_sp, tower_tex, sfTrue);
        posi_tower = (sfVector2f){tower[i].x, tower[i].y};
        sfSprite_setPosition(tower[i].tower_sp, posi_tower);
        sfSprite_setScale(tower[i].tower_sp, (sfVector2f){0.08, 0.08});
        tower = set_circle(tower, setting, i);
    }
    return tower;
}

void display_tower(tower_t *tower, setting_t setting)
{
    for (int i = 0; i < setting.nb_tower; i++) {
        if (setting.S == 0)
            sfRenderWindow_drawSprite(setting.window, tower[i].tower_sp, NULL);
        if (setting.L == 0)
            sfRenderWindow_drawCircleShape(setting.window, tower[i].circle,
            NULL);
    }
}