/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** annia_give_heal
*/

#include "rpg.h"

void annia_give_heal(void *main)
{
    rpg_t *rpg = (rpg_t *)main;
    stop_quest(rpg, "go_to_annia");
    add_item_to_inventory(82, rpg);
}
