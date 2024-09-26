/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** player
*/

#include "player.h"
#include "map.h"
#include "network_init.h"
#include "gll.h"

void initialize_player_attributes(player_t *player,
    char *team, int x, int y)
{
    player->team = team;
    player->pos.x = x;
    player->pos.y = y;
    player->level = 1;
    player->inv.items[0].count = 1260;
}

player_t *create_player(char *team, int x, int y)
{
    static int id = 0;
    player_t *player = malloc(sizeof(player_t));
    char *i_name[7] = {"food", "linemate", "deraumere",
        "sibur", "mendiane", "phiras", "thystame"};

    if (!player)
        return NULL;
    initialize_player_attributes(player, team, x, y);
    player->inv.items[0].name = i_name[0];
    for (int stone = 1; stone < 7; stone++) {
        player->inv.items[stone].name = i_name[stone];
        player->inv.items[stone].count = 0;
    }
    for (int i = 0; i < 4; i++)
        player->direction[i] = (i == 0) ? 1 : 0;
    player->doing_ritual = false;
    player->id = id + 1;
    id++;
    return player;
}

void place_player_on_map(player_t *player, map_t *map)
{
    if (player->pos.x < 0 || player->pos.x >= map->width ||
        player->pos.y < 0 || player->pos.y >= map->height) {
        printf("Error: Player is out of the map\n");
        return;
    }
    gll_push_back(map->tiles[player->pos.x][player->pos.y].players, player);
}

player_t *manage_player(player_t *player, map_t *map)
{
    int x = rand() % map->width;
    int y = rand() % map->height;

    player->pos.x = x;
    player->pos.y = y;
    return player;
}
