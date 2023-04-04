/*
** EPITECH PROJECT, 2022
** structure.h
** File description:
** structure for bsq
*/

#ifndef __STRUCTURE_H_
    #define __STRUCTURE_H_

    #include <time.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdio.h>

typedef struct plane {
    int x;
    int y;
    int x1;
    int y1;
    int x2;
    int y2;
    int speed;
    int start;
    int visible;
    double z;
    double nb;
    int arrive;
    sfSprite *plane_sp;
    sfRectangleShape *rectagle;
}plane_t;

typedef struct tower {
    int x;
    int y;
    int range;
    sfSprite *tower_sp;
    sfCircleShape *circle;
}tower_t;

typedef struct setting {
    int nb_plane;
    int nb_tower;
    int L;
    int S;
    int seconde;
    int minute;
    sfRenderWindow* window;
    sfEvent event;
    sfSprite *map_sp;
    sfClock *clock;
    sfClock *clock_moove;
    sfText *seconde_txt;
    sfText *minute_txt;
    sfText *point_txt;
    sfFont *police;
    sfText *usage_L;
    sfText *usage_S;
}setting_t;

#endif
