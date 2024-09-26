/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** update_movement
*/

#include "rfc_handling.h"
#include "network_init.h"
#include "zappy.h"

void update_x_pos(int *pos[2], int new_x, network_init_t *nw, struct map* map)
{
    gll_remove(map->tiles[*pos[0]][*pos[1]].players, 0);
    *pos[0] = new_x;
    nw->players[nw->i]->pos.x = *pos[0];
    gll_push_back(map->tiles[nw->players[nw->i]->pos.x]
        [nw->players[nw->i]->pos.y].players, nw->players[nw->i]);
}

void update_y_pos(int *pos[2], int new_y, network_init_t *nw, map_t *map)
{
    gll_remove(map->tiles[*pos[0]][*pos[1]].players, 0);
    *pos[1] = new_y;
    nw->players[nw->i]->pos.y = *pos[1];
    gll_push_back(map->tiles[nw->players[nw->i]->pos.x]
        [nw->players[nw->i]->pos.y].players, nw->players[nw->i]);
}
