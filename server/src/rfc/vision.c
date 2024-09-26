/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** vision
*/

#include "player.h"
#include "network_init.h"
#include "zappy.h"

void append_vision_output(char *vision_output, int range,
    map_t *map, network_init_t *nw)
{
    char *tile;

    for (int i = 0 - range; i < 1 + (range * 2) - range; i++) {
        if (*(nw->players[nw->i]->direction) == 0)
            tile = print_t_cont(get_t_cont(map, nw->players[nw->i]->pos.x -
                (range), nw->players[nw->i]->pos.y + i));
        if (*(nw->players[nw->i]->direction) == 1)
            tile = print_t_cont(get_t_cont(map, nw->players[nw->i]->pos.x +
                i, nw->players[nw->i]->pos.y + range));
        if (*(nw->players[nw->i]->direction) == 2)
            tile = print_t_cont(get_t_cont(map, nw->players[nw->i]->pos.x +
                (range), nw->players[nw->i]->pos.y + i));
        if (*(nw->players[nw->i]->direction) == 3)
            tile = print_t_cont(get_t_cont(map, nw->players[nw->i]->pos.x
                + i, nw->players[nw->i]->pos.y - range));
        strcat(vision_output, " ");
        strcat(vision_output, tile);
        strcat(vision_output, ",");
        free(tile);
    }
}

void vision_cmd(int fd, char **arg, map_t *map, zp_t *z)
{
    char *player_tile;
    char *vision_output = malloc(1024 * sizeof(char));
    network_init_t *nw = z->network;

    (void)fd;
    (void)arg;
    strcpy(vision_output, "[");
    player_tile = print_t_cont(get_t_cont(map,
        nw->players[nw->i]->pos.x, nw->players[nw->i]->pos.y));
    strcat(vision_output, player_tile);
    strcat(vision_output, ",");
    free(player_tile);
    for (int range = 1; range <= nw->players[nw->i]->level; range++)
        append_vision_output(vision_output, range, z->map, z->network);
    strcat(vision_output, "]\n");
    send_message(fd, vision_output);
}
