/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** npc_give_nothing
*/

#include "rpg.h"

void npc_give_nothing(void *main)
{
    (void)(main);
    rpg_t *rpg = (rpg_t *)main;
    stop_quest(rpg, "go_to_annia");
}
