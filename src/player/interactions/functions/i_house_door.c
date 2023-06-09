/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** i_house_door
*/

#include "rpg.h"

static void change_map(rpg_t *rpg)
{
    char *player_house = "resources/maps/player_house.json";
    char *main_map = "resources/maps/main_map.json";

    if (my_strcmp(rpg->actual_map, player_house) == 0) {
        if (quest_is_in_progress(rpg, "go_to_annia") != 1 &&
            quest_is_completed(rpg, "go_to_annia") != 1) {
            rpg->narative->str = get_language(rpg, "house_cant_leave", RSG);
            start_narative_popup(rpg);
            return;
        }
        rpg->actual_map = main_map;
        rpg->player->pos.x = SPAWN_OUT_HOUSE_X;
        rpg->player->pos.y = SPAWN_OUT_HOUSE_Y;
    } else if (my_strcmp(rpg->actual_map, main_map) == 0) {
        rpg->actual_map = player_house;
        rpg->player->pos.x = SPAWN_INTO_HOUSE_X;
        rpg->player->pos.y = SPAWN_INTO_HOUSE_Y;
    }
}

void i_house_door(rpg_t *rpg, sfVector2f pos)
{
    char *str = NULL;
    if (my_strcmp(rpg->actual_map, "resources/maps/player_house.json") == 0) {
        str = get_language(rpg, "house_door_interact_leave", RSG);
        draw_interaction_popup(rpg, (sfVector2f){pos.x - 160, pos.y - 20},
            RPK->interact.key, str);
    } else if (my_strcmp(rpg->actual_map,"resources/maps/main_map.json") == 0) {
        str = get_language(rpg, "house_door_interact_enter", RSG);
        draw_interaction_popup(rpg, (pos), RPK->interact.key, str);
    }
    if (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue)
        change_map(rpg);
    while (sfKeyboard_isKeyPressed(RPK->interact.key) == sfTrue);
}
