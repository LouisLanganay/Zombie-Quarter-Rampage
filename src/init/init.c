/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init
*/

#include "rpg.h"

void init(rpg_t *rpg)
{
    rpg->maps = NULL;
    init_glib(rpg);
    init_game_sounds(rpg);
    init_language(rpg);
    init_settings(rpg);
    init_player(rpg);
    init_inventory(rpg);
    init_popup_interaction(rpg);
    init_popup_dialogue(rpg);
    init_popup_lore(rpg);
    init_save(rpg);
    init_splash_screen(rpg);
    init_main_menu(rpg);
    init_quests(rpg);
    init_quest_assets(rpg);
    init_hud(rpg);
}
