/*
** EPITECH PROJECT, 2018
** score life
** File description:
** graph
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

int score(graphic_t *graphic)
{
    graphic->score += 1;

    if (graphic->score == 9 || graphic->score == 18) {
        my_printf("IT'S OVER 9000\n");
        sfMusic_play(graphic->music_score);
    }
    if (graphic->score == 50) {
        my_printf("SUPA SAYAJIN\n");
        sfMusic_play(graphic->vegeta);
    }
}

void life_done(graphic_t *graphic)
{
    if (graphic->life == 0) {
        my_printf("You lost... The Duck has destroyed Namek !\n");
        my_printf("Your final score = %d\n", graphic->score);
        my_printf("You can do better !\n");
        sfRenderWindow_close(graphic->window);
    }
}