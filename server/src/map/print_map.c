/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** print_map
*/

#include "map.h"
#include "player.h"
#include <stdio.h>

void print_resource(int count, char resource)
{
    for (int i = 0; i < count; i++)
        printf("%c", resource);
}

void print_tile(tile_t tile)
{
    print_resource(tile.food, 'F');
    print_resource(tile.linemate, 'L');
    print_resource(tile.deraumere, 'D');
    print_resource(tile.sibur, 'S');
    print_resource(tile.mendiane, 'M');
    print_resource(tile.phiras, 'P');
    print_resource(tile.thystame, 'T');
}

void print_player_tile(map_t *map, int i, int j)
{
    if (!(gll_empty(map->tiles[i][j].players)))
        printf("X");
    else
        print_tile(map->tiles[i][j]);
    printf("\t|\t");
}

void print_map(map_t *map)
{
    printf("\n");
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            print_player_tile(map, i, j);
        }
        printf("\n");
    }
}
