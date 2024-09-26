/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** map
*/

#pragma once

#include <stdlib.h>
#include "gll.h"

#define FOOD_DENSITY 0.5
#define LINEMATE_DENSITY 0.3
#define DERAUMERE_DENSITY 0.15
#define SIBUR_DENSITY 0.1
#define MENDIANE_DENSITY 0.1
#define PHIRAS_DENSITY 0.08
#define THYSTAME_DENSITY 0.05

typedef struct player player_t;

typedef struct tile {
    int x;
    int y;
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
    gll_t *players;
} tile_t;

typedef struct map {
    int width;
    int height;
    tile_t **tiles;
} map_t;

map_t *create_map(int width, int height);
void print_map(map_t *map);
void distribute_resource(tile_t **tiles,
    int *size, int total, void (*increment_resource)(tile_t *));
void increment_food(tile_t *tile);
void increment_linemate(tile_t *tile);
void increment_deraumere(tile_t *tile);
void increment_sibur(tile_t *tile);
void increment_mendiane(tile_t *tile);
void increment_phiras(tile_t *tile);
void increment_thystame(tile_t *tile);
void distribute(map_t *map, int width, int height, int total_tiles);
