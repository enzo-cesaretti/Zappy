/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** map
*/

#include "map.h"
#include <stdio.h>
#include <time.h>

void distribute(map_t *map, int width, int height, int total_tiles)
{
    int size[2];

    size[0] = width;
    size[1] = height;
    distribute_resource(map->tiles, size,
        total_tiles * FOOD_DENSITY, increment_food);
    distribute_resource(map->tiles, size,
        total_tiles * LINEMATE_DENSITY, increment_linemate);
    distribute_resource(map->tiles, size,
        total_tiles * DERAUMERE_DENSITY, increment_deraumere);
    distribute_resource(map->tiles, size,
        total_tiles * SIBUR_DENSITY, increment_sibur);
    distribute_resource(map->tiles, size,
        total_tiles * MENDIANE_DENSITY, increment_mendiane);
    distribute_resource(map->tiles, size,
        total_tiles * PHIRAS_DENSITY, increment_phiras);
    distribute_resource(map->tiles, size,
        total_tiles * THYSTAME_DENSITY, increment_thystame);
}

map_t *create_map(int width, int height)
{
    map_t *map = malloc(sizeof(map_t));
    int total_tiles = width * height;

    map->width = width;
    map->height = height;
    map->tiles = malloc(sizeof(tile_t *) * height);
    for (int i = 0; i < height; i++) {
        map->tiles[i] = calloc(width, sizeof(tile_t));
        for (int j = 0; j < width; j++) {
            map->tiles[i][j].x = j;
            map->tiles[i][j].y = i;
            map->tiles[i][j].players = gll_init();
        }
    }
    distribute(map, width, height, total_tiles);
    return (map);
}
