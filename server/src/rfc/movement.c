/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** movement
*/

#include "rfc_handling.h"
#include "network_init.h"
#include "zappy.h"


void move_player(int direction, int *pos[2], map_t *map, zp_t *z)
{
    if (direction == 0)
        update_x_pos(pos, (*pos[0] - 1 + map->height)
            % map->height, z->network, map);
    if (direction == 1)
        update_y_pos(pos, (*pos[1] + 1 + map->width)
            % map->width, z->network, map);
    if (direction == 2)
        update_x_pos(pos, (*pos[0] + 1 + map->height)
            % map->height, z->network, map);
    if (direction == 3)
        update_y_pos(pos, (*pos[1] - 1 + map->width)
            % map->width, z->network, map);
}

void forward_command(int fd, char **arg, map_t *map, zp_t *z)
{
    int direction = *(z->network->players[z->network->i]->direction);
    int *pos[2];

    (void)arg;
    (void)map;
    pos[0] = &(z->network->players[z->network->i]->pos.x);
    pos[1] = &(z->network->players[z->network->i]->pos.y);
    move_player(direction, pos, map, z);
    z->p_fd = z->network->i;
    z->p_id = z->network->players[z->network->i]->id;
    send_message(fd, "ok\n");
    z->network->players[z->p_fd]->pos_change = 1;
}

void right_command(int fd, char **arg, map_t *map, zp_t *z)
{
    (void)arg;
    (void)map;
    *(z->network->players[z->network->i]->direction) =
        (*(z->network->players[z->network->i]->direction) + 1) % 4;
    send_message(fd, "ok\n");
}

void left_command(int fd, char **arg, map_t *map, zp_t *z)
{
    (void)arg;
    (void)map;
    *(z->network->players[z->network->i]->direction) =
        (*(z->network->players[z->network->i]->direction) + 3) % 4;
    send_message(fd, "ok\n");
}
