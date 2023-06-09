/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** e_key_released
*/

#include "rpg.h"

void e_key_released(window_t *window, void *main)
{
    (void)window;
    rpg_t *rpg = (rpg_t *)main;
    if (rpg->glib->window->event.key.code == rpg->player->keys->up.key)
        rpg->player->keys->up.state = 0;
    if (rpg->glib->window->event.key.code == rpg->player->keys->down.key)
        rpg->player->keys->down.state = 0;
    if (rpg->glib->window->event.key.code == rpg->player->keys->left.key)
        rpg->player->keys->left.state = 0;
    if (rpg->glib->window->event.key.code == rpg->player->keys->right.key)
        rpg->player->keys->right.state = 0;
}
