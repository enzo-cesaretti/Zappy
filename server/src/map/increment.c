/*
** EPITECH PROJECT, 2024
** src
** File description:
** increment
*/

#include "map.h"

void distribute_resource(tile_t **tiles, int *size,
    int total, void (*increment_resource)(tile_t *))
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < total; i++) {
        x = rand() % size[0];
        y = rand() % size[1];
        increment_resource(&tiles[y][x]);
    }
}

void increment_mendiane(tile_t *tile)
{
    tile->mendiane++;
}

void increment_phiras(tile_t *tile)
{
    tile->phiras++;
}

void increment_thystame(tile_t *tile)
{
    tile->thystame++;
}
