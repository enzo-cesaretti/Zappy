/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** arguments
*/

#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct team {
    char *name;
    int player_count;
} team_t;

typedef struct server_args {
    int port;
    int width;
    int height;
    team_t *teams;
    int team_count;
    int clients_nb;
    int freq;
} server_args_t;

void handle_p_arg(server_args_t *args, char **av, int *i);
void handle_x_arg(server_args_t *args, char **av, int *i);
void handle_n_arg(server_args_t *args, char **av, int ac, int *i);
void handle_y_arg(server_args_t *args, char **av, int *i);
void handle_c_arg(server_args_t *args, char **av, int *i);
void handle_arg(char **av, int *i, server_args_t *args, int ac);
void display_help(void);
server_args_t *parse_args(int ac, char **av);
