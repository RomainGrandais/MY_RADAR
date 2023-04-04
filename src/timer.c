/*
** EPITECH PROJECT, 2022
** timer.c
** File description:
** timer for my_radar
*/

#include <my.h>
#include <structure.h>

void set_string(setting_t *setting, char *seconde, char *minute, char *point)
{
    sfText_setString(setting->seconde_txt, seconde);
    sfText_setString(setting->minute_txt, minute);
    sfText_setString(setting->point_txt, point);
    sfRenderWindow_drawText(setting->window, setting->seconde_txt, NULL);
    sfRenderWindow_drawText(setting->window, setting->minute_txt, NULL);
    sfRenderWindow_drawText(setting->window, setting->point_txt, NULL);
}

void timer(setting_t *setting)
{
    char *seconde;
    char *minute;
    char *point;
    sfTime time = sfClock_getElapsedTime(setting->clock);

    setting->seconde = sfTime_asSeconds(time) - (60 * setting->minute);
    if (setting->seconde >= 60) {
        setting->seconde -= 60;
        setting->minute += 1;
    }
    seconde = malloc(sizeof(char) * len_int(setting->seconde) + 1);
    minute = malloc(sizeof(char) * len_int(setting->minute) + 1);
    point = malloc(sizeof(char) * 2);
    seconde = int_to_string(setting->seconde);
    minute = int_to_string(setting->minute);
    seconde[len_int(setting->seconde)] = '\0';
    minute[len_int(setting->minute)] = '\0';
    point = ":\0";
    set_string(setting, seconde, minute, point);
}