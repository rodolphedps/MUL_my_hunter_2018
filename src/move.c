/*
** EPITECH PROJECT, 2018
** move rect
** File description:
** prog
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

void hitbox(graphic_t *graphic, sfEvent event)
{
    int rand_y = rand() % 800 + 40;
    sfVector2i vec = sfMouse_getPositionRenderWindow(graphic->window);
    sfVector2f vec2 = sfSprite_getPosition(graphic->sprite);

    if (vec.x >= vec2.x && vec.x <= vec2.x + 110 && vec.y >= vec2.y &&
    vec.y <= vec2.y + 110) {
        vec2.x = -110;
        vec2.y = rand_y;
        sfSprite_setPosition(graphic->sprite, vec2);
        sfMusic_play(graphic->sounds);
        my_printf("YOU HIT HIM ! +1 ! Your score = %d\n", graphic->score);
        score(graphic);
    }
    else {
        graphic->life -= 1;
        my_printf("Missed... Try again ! life = %d\n", graphic->life);
        life_done(graphic);
    }
}

void move_sprite_x(graphic_t *graphic)
{
    static int ret = 0;
    sfVector2f go = {1, 1};
    sfVector2f come_back = {-1, 1};
    sfVector2f sprite = sfSprite_getPosition(graphic->sprite);

    if (ret == 0) {
        sfSprite_setScale(graphic->sprite, go);
        sfSprite_move(graphic->sprite, graphic->vec_go);
    }
    if (sprite.x >= 1920)
        ret = 1;
    if (ret == 1) {
        sfSprite_setScale(graphic->sprite, come_back);
        sfSprite_move(graphic->sprite, graphic->vec_back);
    }
    if (sprite.x < 1)
        ret = 0;
}

void move_rect(graphic_t *graphic, int set, int max)
{
    graphic->rect->left += 110;
    if (graphic->rect->left >= max)
        graphic->rect->left = set;
}

void aim_sight(graphic_t *graphic)
{
    sfSprite *a_sight = sfSprite_create();
    sfTexture *aim_sight = sfTexture_createFromFile("./files/scope4.png", NULL);
    sfVector2i pos_x = sfMouse_getPositionRenderWindow(graphic->window);
    sfVector2f pos_s;

    pos_s.x = pos_x.x - 83;
    pos_s.y = pos_x.y - 85;
    sfRenderWindow_setMouseCursorVisible(graphic->window, 0);
    sfSprite_setTexture(a_sight, aim_sight, sfTrue);
    sfSprite_setPosition(a_sight, pos_s);
    sfRenderWindow_drawSprite(graphic->window, a_sight, NULL);
}
