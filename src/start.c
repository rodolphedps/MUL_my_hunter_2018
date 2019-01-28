/*
** EPITECH PROJECT, 2018
** start prog
** File description:
** hunter
*/

#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Audio/Music.h>
#include "../include/graph.h"
#include "../include/my.h"

void display_sprites(graphic_t *graphic)
{
    sfSprite_setTexture(graphic->sprite, graphic->texture, sfTrue);
    sfSprite_setTexture(graphic->sprite2, graphic->texture2, sfTrue);
    sfSprite_setTextureRect(graphic->sprite, *graphic->rect);
    sfRenderWindow_drawSprite(graphic->window, graphic->sprite2, NULL);
    sfRenderWindow_drawSprite(graphic->window, graphic->sprite, NULL);
    aim_sight(graphic);
    sfRenderWindow_display(graphic->window);
    sfRenderWindow_clear(graphic->window, sfBlack);
}

void clock_sprites(graphic_t *graphic)
{
    int set;
    int max;

    graphic->time = sfClock_getElapsedTime(graphic->clock);
    graphic->seconds = graphic->time.microseconds / 100000.0;
    if (graphic->seconds > 1.0) {
        move_rect(graphic, 0, 330);
        sfClock_restart(graphic->clock);
    }
    move_sprite_x(graphic);
}

void manage_event(graphic_t *graphic, sfEvent event)
{
    while (sfRenderWindow_pollEvent(graphic->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(graphic->window);
        if (event.type == sfEvtMouseButtonPressed) {
            printf("aieeee\n");
            hitbox(graphic, event);
        }
    }
}

void display_music(graphic_t *graphic)
{
    graphic->music = sfMusic_createFromFile("./audio/chala.ogg");
    graphic->music_score = sfMusic_createFromFile("./audio/over.ogg");
    graphic->sounds = sfMusic_createFromFile("./audio/sounds2.ogg");
    graphic->vegeta = sfMusic_createFromFile("./audio/vegetassj.ogg");

    sfMusic_setLoop(graphic->music, 1);
    sfMusic_setVolume(graphic->music, 50);
    sfMusic_setVolume(graphic->music_score, 100);
    sfMusic_setVolume(graphic->sounds, 40);
    sfMusic_setVolume(graphic->vegeta, 50);
    sfMusic_play(graphic->music);
}

void destroy_all(graphic_t *graphic)
{
    sfSprite_destroy(graphic->sprite);
    sfSprite_destroy(graphic->sprite2);
    sfTexture_destroy(graphic->texture);
    sfMusic_destroy(graphic->music);
    sfMusic_destroy(graphic->music_score);
    sfMusic_destroy(graphic->sounds);
    sfMusic_destroy(graphic->vegeta);
    sfRenderWindow_destroy(graphic->window);
}
