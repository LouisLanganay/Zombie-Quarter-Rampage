/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** start_dialogue_default
*/

#include "rpg.h"

void start_dialogue_default(npc_t *npc, rpg_t *rpg)
{
    sfText *main_text = gl_get_text(rpg->glib, PLAYER_DIALOGUE_TEXT);
    sfText *choice_one_text = gl_get_text(rpg->glib, PLAYER_DCHOICE_ONE_TEXT);
    sfText *choice_two_text = gl_get_text(rpg->glib, PLAYER_DCHOICE_TWO_TEXT);
    dialog_t *dialog = npc->dialogs;

    while (dialog) {
        if (my_strcmp(dialog->name, npc->default_dialog) == 0) break;
        dialog = dialog->next;
    }
    sfText_setString(main_text, get_language(rpg, dialog->text, RSG));
    sfText_setString(choice_one_text, NULL);
    sfText_setString(choice_two_text, NULL);
    rpg->player->in_dialogue = 1;
    rpg->actual_dialog = dialog;
    rpg->actual_npc = npc;
}
