/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** check_player_moovment
*/

#include "rpg.h"

static int check_player_moovment_complex(
    player_t *player,
    map_t *map,
    rpg_t *rpg,
    float seconds
)
{
    if (player->keys->down.state == 1 && player->keys->right.state == 1) {
        if (RIGHT_CONDITION) player->pos.x += 1 * PLAYER_SPEED * seconds;
        if (DOWN_CONDITION) player->pos.y += 1 * PLAYER_SPEED * seconds;
        return 1;
    }
    if (player->keys->down.state == 1 && player->keys->left.state == 1) {
        if (LEFT_CONDITION) player->pos.x -= 1 * PLAYER_SPEED * seconds;
        if (DOWN_CONDITION) player->pos.y += 1 * PLAYER_SPEED * seconds;
        return 1;
    }
    return 0;
}

static int check_player_moovment_complex_bis(
    player_t *player,
    map_t *map,
    rpg_t *rpg,
    float seconds
)
{
    if (player->keys->up.state == 1 && player->keys->right.state == 1) {
        if (RIGHT_CONDITION) player->pos.x += 1 * PLAYER_SPEED * seconds;
        if (UP_CONDITION) player->pos.y -= 1 * PLAYER_SPEED * seconds;
        return 1;
    }
    if (player->keys->up.state == 1 && player->keys->left.state == 1) {
        if (LEFT_CONDITION) player->pos.x -= 1 * PLAYER_SPEED * seconds;
        if (UP_CONDITION) player->pos.y -= 1 * PLAYER_SPEED * seconds;
        return 1;
    }
    return 0;
}

void check_player_moovment_simple(
    player_t *player,
    float seconds,
    map_t *map,
    rpg_t *rpg
)
{
    if (player->keys->up.state == 1)
        if (UP_CONDITION) player->pos.y -= 1 * PLAYER_SPEED * seconds;
    if (player->keys->down.state == 1)
        if (DOWN_CONDITION) player->pos.y += 1 * PLAYER_SPEED * seconds;
    if (player->keys->left.state == 1)
        if (LEFT_CONDITION) player->pos.x -= 1 * PLAYER_SPEED * seconds;
    if (player->keys->right.state == 1)
        if (RIGHT_CONDITION) player->pos.x += 1 * PLAYER_SPEED * seconds;
}

void check_player_moovment(player_t *player, map_t *map, rpg_t *rpg)
{
    time_t time = sfClock_getElapsedTime(player->clock).microseconds;
    float seconds = time / 1000000.0;

    check_interactions(player, map, rpg);
    check_sounds_interactions(rpg, map);
    if (seconds < 0.001)
        return;
    if (check_player_moovment_complex(player, map, rpg, seconds) == 1) {
        sfClock_restart(player->clock);
        return;
    }
    if (check_player_moovment_complex_bis(player, map, rpg, seconds) == 1) {
        sfClock_restart(player->clock);
        return;
    }
    check_player_moovment_simple(player, seconds, map, rpg);
    sfClock_restart(player->clock);
}
