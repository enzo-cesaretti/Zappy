/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** tile
*/

#include "player.h"

void add_word_with_space(char *output, const char *word)
{
    if (output[0] != '\0')
        strcat(output, " ");
    strcat(output, word);
}

void add_resources_to_output(char *output, tile_t tile)
{
    if (tile.mendiane > 0)
        for (int i = 0; i < tile.mendiane; i++)
            add_word_with_space(output, "mendiane");
    if (tile.phiras > 0)
        for (int i = 0; i < tile.phiras; i++)
            add_word_with_space(output, "phiras");
    if (tile.thystame > 0)
        for (int i = 0; i < tile.thystame; i++)
            add_word_with_space(output, "thystame");
}

char *print_t_cont(tile_t tile)
{
    char *output = calloc(1024, sizeof(char));

    for (gll_node_t *nd = tile.players->first; nd != NULL; nd = nd->next)
        add_word_with_space(output, "player");
    if (tile.food > 0)
        for (int i = 0; i < tile.food; i++)
            add_word_with_space(output, "food");
    if (tile.linemate > 0)
        for (int i = 0; i < tile.linemate; i++)
            add_word_with_space(output, "linemate");
    if (tile.deraumere > 0)
        for (int i = 0; i < tile.deraumere; i++)
            add_word_with_space(output, "deraumere");
    if (tile.sibur > 0)
        for (int i = 0; i < tile.sibur; i++)
            add_word_with_space(output, "sibur");
    add_resources_to_output(output, tile);
    return output;
}

tile_t get_t_cont(map_t *map, int x, int y)
{
    if (x < 0)
        x = map->width + x;
    if (y < 0)
        y = map->height + y;
    if (x >= map->width)
        x = x - map->width;
    if (y >= map->height)
        y = y - map->height;
    return map->tiles[x][y];
}
