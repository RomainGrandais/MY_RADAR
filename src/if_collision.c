/*
** EPITECH PROJECT, 2022
** if_collision.c
** File description:
** collision with two planes
*/

#include <my.h>
#include <structure.h>

plane_t *check_collision(sfVector2f posi_rec, sfVector2f posi_col,
plane_t *plane, int *index)
{
    sfVector2f scale = {0, 0};

    if (posi_rec.x == posi_col.x && posi_rec.y == posi_col.y)
        return plane;
    if (posi_rec.x + 20 >= posi_col.x && posi_rec.x - 20 <= posi_col.x) {
        if (posi_rec.y + 20 >= posi_col.y && posi_rec.y - 20 <= posi_col.y) {
            sfSprite_setScale(plane[index[0]].plane_sp, scale);
            sfRectangleShape_setScale(plane[index[0]].rectagle, scale);
            sfSprite_setScale(plane[index[1]].plane_sp, scale);
            sfRectangleShape_setScale(plane[index[1]].rectagle, scale);
            plane[index[0]].arrive = 1;
            plane[index[1]].arrive = 1;
        }
    }
    return plane;
}

plane_t *cut_collision(sfVector2f posi_rec, plane_t *plane,
    setting_t *setting, int i)
{
    sfVector2f posi_col = {0, 0};
    int *index;

    index = malloc(sizeof(int) * 2);
    index[0] = i;
    for (int j = 0; j < setting->nb_plane; j++) {
        if (plane[j].arrive == 0 && plane[j].arrive == 0) {
            posi_col = sfRectangleShape_getPosition(plane[j].rectagle);
            index[1] = j;
            plane = check_collision(posi_rec, posi_col, plane, index);
        }
    }
    return plane;
}

plane_t *if_collision(plane_t *plane, setting_t *setting)
{
    sfVector2f posi_rec = {0 , 0};
    sfVector2f posi_col = {0, 0};

    for (int i = 0; i < setting->nb_plane; i++) {
        if (plane[i].arrive == 0) {
            posi_rec = sfRectangleShape_getPosition(plane[i].rectagle);
            plane = cut_collision(posi_rec, plane, setting, i);
        }
    }
    return plane;
}