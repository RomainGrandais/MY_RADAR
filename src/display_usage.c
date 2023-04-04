/*
** EPITECH PROJECT, 2022
** display_usage.c
** File description:
** display usage of user
*/

#include <my.h>
#include <structure.h>
#include <stdlib.h>


void display_usage(setting_t *setting)
{
    char usage_L[63] = "Switch visibility of hitboxes by pressing the key L.";
    char usage_S[61] = "Switch visibility of sprites by pressing the key S.";

    sfText_setString(setting->usage_L, usage_L);
    sfText_setString(setting->usage_S, usage_S);
    sfRenderWindow_drawText(setting->window, setting->usage_L, NULL);
    sfRenderWindow_drawText(setting->window, setting->usage_S, NULL);
}
