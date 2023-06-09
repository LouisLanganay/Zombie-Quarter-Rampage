/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** game_start
*/

#include "rpg.h"

void game_start(rpg_t *rpg)
{
    if (rpg->maps_loaded == 0) {
        draw_splash_screen(rpg);
    } else {
        start_sound(rpg, MAIN_THEME_ID);
        check_sounds(rpg);
        draw_menu(rpg);
    }
}
