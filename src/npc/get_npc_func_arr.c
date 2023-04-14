/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** get_npc_func_arr
*/

#include "rpg.h"

dialog_func_t *get_npc_func_arr(void)
{
    dialog_func_t dialog_func[] = {
        { "npc_give_food", npc_give_food },
        { "jack_start_quest", jack_start_quest },
        { "annia_give_heal", annia_give_heal },
        { NULL, NULL }
    };
    dialog_func_t *arr = malloc(sizeof(dialog_func_t) *
        (sizeof(dialog_func) / sizeof(dialog_func_t)));
    for (long unsigned int x = 0; x < sizeof(dialog_func) /
        sizeof(dialog_func_t); x++) {
        arr[x].name = dialog_func[x].name;
        arr[x].func = dialog_func[x].func;
    }
    return arr;
}
