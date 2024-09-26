/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** zappy
*/

#pragma once
#include "./network_init.h"
#include "./server.h"
#include "./map.h"
#include "./player.h"
#include "./args.h"

typedef struct zp_s {
    serv_info_t *serv_info;
    network_init_t *network;
    time_t start_time;
    server_args_t *args;
    map_t *map;
    int graph_fd;
    int gui_nb_cmd;
    int p_fd;
    int p_id;
} zp_t;

void handle_log(char **parsed_cmd,
    server_args_t *args, map_t *map, zp_t *z);
void loop_server(network_init_t *network, server_args_t *args,
    map_t *map, zp_t *z);
void manage_client(network_init_t *nw, server_args_t *args,
    map_t *map, zp_t *z);
void get_all_t_res(int fd, char **arg, map_t *map, zp_t *z);
void vision_cmd(int fd, char **arg, map_t *map, zp_t *z);
void client_disconnect(zp_t *z, server_args_t *args,
    map_t *map, player_t *player);
void process_graphic_players(network_init_t *nw,
    char **parsed_cmd, map_t *map, zp_t *z);
void connect_graphic_player(zp_t *z, char **parsed_cmd, map_t *map);
