/*
** EPITECH PROJECT, 2018
** graph.h
** File description:
** .h
*/

#pragma once
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct struct_s {
    sfRenderWindow *window;
    sfEventType type;
    sfText *text;
    sfMouseButton button;
    sfClock *clock;
    sfIntRect *rect;
    sfTexture *texture;
    sfTexture *texture2;
    sfSprite *sprite;
    sfSprite *sprite2;
    sfVector2f *spr;
    sfMouseButtonEvent event2;
    sfMusic *music;
    sfMusic *music_score;
    sfMusic *sounds;
    sfMusic *vegeta;
    sfTime time;
    sfVector2f vec_go;
    sfVector2f vec_back;
    int score;
    int life;
    float seconds;
    float speed;
}       graphic_t;

typedef struct str_s {
    sfTexture *sprdb;
    sfSprite *spritedb;
    sfTexture *sprdb2;
    sfSprite *spritedb2;
    sfTexture *sprdb3;
    sfSprite *spritedb3;
}              sprite_t;
