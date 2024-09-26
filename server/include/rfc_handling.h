/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** map
*/

#pragma once

#include "network_init.h"

typedef void (*command_handler_t) (int fd, char **, map_t *map, zp_t *z);
typedef void (*g_command_t) (int fd, char **, map_t *map, zp_t *z);

typedef struct {
    char *name;
    command_handler_t handler;
} command_entry_t;

typedef struct {
    char *name;
    g_command_t handler;
} g_command_e_t;

extern const command_entry_t commands[];
void get_map_size(int fd, char **arg, map_t *map, zp_t *z);
void left_command(int fd, char **arg, map_t *map, zp_t *z);
void get_t_resources(int fd, char **arg, map_t *map, zp_t *z);
void rfc_handling(char **buffer, int fd, map_t *map, zp_t *z);
void forward_command(int fd, char **arg, map_t *map, zp_t *z);
void g_handling(char **buffer, int fd, map_t *map, zp_t *z);
void right_command(int fd, char **arg, map_t *map, zp_t *z);
void broadcast_cmd(int fd, char **arg, map_t *map, zp_t *z);
void list_all_team(int fd, char **arg, map_t *map, zp_t *z);
void player_pos(int fd, char **arg, map_t *map, zp_t *z);
void player_level(int fd, char **arg, map_t *map, zp_t *z);
void player_inv(int fd, char **arg, map_t *map, zp_t *z);
void player_take(int fd, char **arg, map_t *map, zp_t *z);
void player_connect_nbr(int fd, char **arg, map_t *map, zp_t *z);
void broadcast_cmd(int fd, char **arg, map_t *map, zp_t *z);
void tu_request(int fd, char **arg, map_t *map, zp_t *z);
void player_connection(int player_index, char **arg, map_t *map, zp_t *z);
void player_dead(zp_t *z, char *message, player_t *player);
void update_x_pos(int *pos[2], int new_x, network_init_t *nw, struct map* map);
void update_y_pos(int *pos[2], int new_y, network_init_t *nw, map_t *map);
