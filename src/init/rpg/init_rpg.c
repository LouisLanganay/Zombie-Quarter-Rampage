/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** init_rpg
*/

#include "rpg.h"

void init_rpg(rpg_t *rpg, int ac, char **av)
{
    rpg->debug = (ac == 2 && av[1][0] == '-' && av[1][1] == 'd') ? 1 : 0;
    rpg->actual_map = "resources/maps/main_map.json";
}