/*
** EPITECH PROJECT, 2018
** norm graph
** File description:
** norm
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

int create_struct(graphic_t *graphic)
{
    graphic->speed = 2;
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2f vec_go = {graphic->speed *1.1, 0};
    sfVector2f vec_back = {-4, 7};
    graphic->score = 0;
    graphic->life = 5;
    graphic->window = sfRenderWindow_create(mode, "DBZ Hunter"
                                            , sfResize | sfClose, NULL);
    if (!graphic->window)
        return (-1);
    graphic->texture = sfTexture_createFromFile("./files/duck.png", NULL);
    if (!graphic->texture)
        return (-1);
    graphic->sprite = sfSprite_create();
    sfSprite_setTexture(graphic->sprite, graphic->texture, sfTrue);
    graphic->text = sfText_create();
    graphic->vec_go = vec_go;
    graphic->vec_back = vec_back;
}

void start_program(graphic_t *graphic, sfEvent event)
{
    clock_sprites(graphic);
    display_sprites(graphic);
    manage_event(graphic, event);
}

int description(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putchar('\n');
        my_putstr("========Welcome to DBZHunter========\n");
        my_putchar('\n');
        my_putstr("==Objectives==\n");
        my_putchar('\n');
        my_putstr("-You have to destroy the duck to earn points\n");
        my_putstr("    killing the target gives you 1 point\n");
        my_putstr("-To complete your task, use your mouse to aim\n");
        my_putstr(" and click to kill\n");
        my_putstr("/!\\ Watch out ! Don't miss too much or you'll die\n");
        my_putchar('\n');
        my_putstr("Have fun !\n");
        my_putchar('\n');
        my_putstr("====================================\n");
    }
    return (0);
}

void launch_program(char **av)
{
    graphic_t *graphic = malloc(sizeof(graphic_t));
    graphic->rect = malloc(sizeof(sfIntRect));
    sfEvent event;
    graphic->clock = sfClock_create();
    graphic->texture = sfTexture_createFromFile("./files/duck.png", NULL);
    graphic->sprite = sfSprite_create();
    graphic->texture2 = sfTexture_createFromFile("./files/namek2.png", NULL);
    graphic->sprite2 = sfSprite_create();
    graphic->rect->top = 0;
    graphic->rect->left = 0;
    graphic->rect->width = 110;
    graphic->rect->height = 110;
    display_music(graphic);

    create_struct(graphic);
    while (sfRenderWindow_isOpen(graphic->window)) {
        start_program(graphic, event);
    }
    destroy_all(graphic);
}

int main(int ac, char **av)
{
    int i = 0;
    if (ac > 1 && ac < 3)
        description(av);
    else if (ac < 2)
        launch_program(av);
    return (0);
}
