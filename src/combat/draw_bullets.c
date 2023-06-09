/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** draw_bullets
*/

#include "rpg.h"

void draw_bullets(bullets_t *bullets, rpg_t *rpg)
{
    bullets_t *tmp = bullets;
    if (tmp == NULL)
        return;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(windoww, tmp->sprite, NULL);
        tmp = tmp->next;
    }
}
