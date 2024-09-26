/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** teams
*/

#pragma once
#include "args.h"
#include "network_init.h"
#include "tools.h"

int is_team_in_args(char *team, server_args_t *args);
int check_team(network_init_t *network, server_args_t *args);
team_t *find_player_team(network_init_t *network,
    server_args_t *args, int player_index);
