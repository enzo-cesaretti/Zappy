/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** player
*/

#pragma once

#include <string.h>
#include <stdbool.h>
#include "map.h"
#include "zappy.h"

typedef struct network_init network_init_t;

typedef struct player_pos {
    int x;
    int y;
} p_pos_t;

typedef struct item {
    char *name;
    int count;
} item_t;

typedef struct inv {

    item_t items[7];
} inventory_t;

typedef struct player {
    int id;
    bool is_connected;
    p_pos_t pos;
    int level;
    char *team;
    // int food;
    inventory_t inv;
    // 0: up, 1: right, 2: down, 3: left
    int direction[4];
    bool doing_ritual;
    int pos_change;
} player_t;

player_t *create_player(char *team, int x, int y);
void place_player_on_map(player_t *player, map_t *map);
player_t *manage_player(player_t *player, map_t *map);
char *print_t_cont(tile_t tile);
tile_t get_t_cont(map_t *map, int x, int y);
