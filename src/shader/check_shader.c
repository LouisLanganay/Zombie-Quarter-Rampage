/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-louis.langanay
** File description:
** check_shader
*/

#include "rpg.h"

static void check_rain(rpg_t *rpg, sfRectangleShape *rect)
{
    if (rpg->shader->rain_bool == 1) {
        sfShader_setFloatUniform(rpg->shader->shader_rain,
        "time",sfTime_asSeconds(sfClock_getElapsedTime
        (rpg->shader->shader_clock)));
        sfRenderWindow_drawRectangleShape(rpg->glib->window->window,
        rect, &rpg->shader->states_rain);
    }
}

static void check_blood(rpg_t *rpg, sfRectangleShape *rect)
{
    if (rpg->shader->blood_bool == 1) {
        sfShader_setFloatUniform(rpg->shader->shader_blood, "time",
        sfTime_asSeconds(sfClock_getElapsedTime(rpg->shader->shader_clock)));
        sfShader_setVec2Uniform(rpg->shader->shader_fade, "resolution",
        (sfVector2f) { 1920, 1080 });
        sfRenderWindow_drawRectangleShape(rpg->glib->window->window, rect,
        &rpg->shader->states_blood);
    }
}

static void check_fade(rpg_t *rpg, sfRectangleShape *rect)
{
    if (rpg->shader->fade_bool == 1) {
        sfShader_setFloatUniform(rpg->shader->shader_fade, "time",
        sfTime_asSeconds(sfClock_getElapsedTime(rpg->shader->fade_clock)));
        sfShader_setFloatUniform(rpg->shader->shader_fade, "smooth",
        rpg->shader->fade_val);
        sfShader_setVec2Uniform(rpg->shader->shader_fade, "resolution",
        (sfVector2f) { 1920, 1080 });
        sfRenderWindow_drawRectangleShape(rpg->glib->window->window, rect,
        &rpg->shader->states_fade);
    }
}

static sfRectangleShape *rect_shader(rpg_t *rpg)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    if (rpg->game_state == GAME || rpg->game_state == GAME_LOST) {
        sfRectangleShape_setSize(rect, sfView_getSize(rpg->player->view->view));
        sfRectangleShape_setTexture(rect,
        sfTexture_createFromFile("resources/shader/void.png", NULL), sfTrue);
        sfRectangleShape_setPosition(rect, (sfVector2f) {sfView_getCenter
        (rpg->player->view->view).x - sfView_getSize(rpg->player->view->view).x
        / 2, sfView_getCenter(rpg->player->view->view).y -
        sfView_getSize(rpg->player->view->view).y / 2});
    } else {
        sfRectangleShape_setSize(rect, (sfVector2f){1920, 1080});
        sfRectangleShape_setTexture(rect,
        sfTexture_createFromFile("resources/shader/void.png", NULL), sfTrue);
        sfRectangleShape_setPosition(rect, (sfVector2f){0, 0});
    }
    sfRectangleShape_setFillColor(rect, sfTransparent);
    return (rect);
}

void check_shader(rpg_t *rpg)
{
    sfRectangleShape *rect = rect_shader(rpg);
    check_rain(rpg, rect);
    check_blood(rpg, rect);
    check_fade(rpg, rect);
    if (rpg->shader->torch_bool == 1) {
        check_torch(rpg);
        draw_shader_torch;
    }
    if (rpg->shader->fade_bool == 0)
        sfClock_restart(rpg->shader->fade_clock);
    sfRectangleShape_destroy(rect);
}
