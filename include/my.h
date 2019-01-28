/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my
*/

#pragma once
#include "graph.h"

void my_putchar(char c);
int my_putstr(char const *str);
void display_sprites(graphic_t *graphic);
void clock_sprites(graphic_t *graphic);
void manage_event(graphic_t *graphic, sfEvent event);
void display_music(graphic_t *graphic);
void destroy_all(graphic_t *graphic);
void sprite_resp(graphic_t *graphic, sfVector2f moves);
void hitbox(graphic_t *graphic, sfEvent event);
void move_sprite_x(graphic_t *graphic);
void move_rect(graphic_t *graphic, int set, int max);
void aim_sight(graphic_t *graphic);
int my_printf(char *s, ...);
void load_textures(graphic_t *graphic);
int score(graphic_t *graphic);
void life_done(graphic_t *graphic);