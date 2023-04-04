/*
** EPITECH PROJECT, 2022
** my_radar.c
** File description:
** my_radar
*/

#include <my.h>
#include <structure.h>

void timer(setting_t *setting);
tower_t *set_tower(tower_t *tower, setting_t setting);
plane_t *set_plane(plane_t *plane, setting_t setting);
void set_window(setting_t *setting);
void display_tower(tower_t *tower, setting_t setting);
void display_plane(plane_t *plane, setting_t setting);
plane_t *moove_plane(setting_t *setting, plane_t *plane);
void end_radar(plane_t *plane, setting_t *setting);
void display_usage(setting_t *setting);
plane_t *if_collision(plane_t *plane, setting_t *setting);
plane_t *destroy(plane_t *plane, setting_t *setting);
tower_t *destroy_tower(tower_t *tower, setting_t *setting);

void s_presse(setting_t *setting)
{
    if (setting->S == 0) {
        setting->S += 1;
    } else {
        setting->S = 0;
    }
}

void l_presse(setting_t *setting)
{
    if (setting->L == 0) {
        setting->L += 1;
    } else {
        setting->L = 0;
    }
}

void close_window_game(setting_t *setting)
{
    if (setting->event.type == sfEvtClosed)
        sfRenderWindow_close(setting->window);
    if (setting->event.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyL))
            l_presse(setting);
        if (sfKeyboard_isKeyPressed(sfKeyS))
            s_presse(setting);
    }
}

void my_radar(tower_t *tower, plane_t *plane, setting_t setting)
{
    set_window(&setting);
    tower = set_tower(tower, setting);
    plane = set_plane(plane, setting);
    while (sfRenderWindow_isOpen(setting.window)) {
        while (sfRenderWindow_pollEvent(setting.window, &setting.event)) {
            close_window_game(&setting);
        }
        sfRenderWindow_clear(setting.window, sfWhite);
        end_radar(plane, &setting);
        sfRenderWindow_drawSprite(setting.window, setting.map_sp, NULL);
        plane = moove_plane(&setting, plane);
        if_collision(plane, &setting);
        display_tower(tower, setting);
        display_plane(plane, setting);
        display_usage(&setting);
        timer(&setting);
        sfRenderWindow_display(setting.window);
    }
    destroy(plane, &setting);
    destroy_tower(tower, &setting);
}