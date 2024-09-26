/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** handle_args
*/

#include "args.h"


void handle_p_arg(server_args_t *args, char **av, int *i)
{
    (*i)++;
    args->port = atoi(av[*i]);
}

void handle_x_arg(server_args_t *args, char **av, int *i)
{
    (*i)++;
    args->width = atoi(av[*i]);
}

void handle_n_arg(server_args_t *args, char **av, int ac, int *i)
{
    while (*i + 1 < ac && av[*i + 1][0] != '-') {
        (*i)++;
        args->teams[args->team_count].name = av[*i];
        args->teams[args->team_count].player_count = 0;
        args->team_count++;
    }
}

void handle_y_arg(server_args_t *args, char **av, int *i)
{
    (*i)++;
    args->height = atoi(av[*i]);
}

void handle_c_arg(server_args_t *args, char **av, int *i)
{
    (*i)++;
    args->clients_nb = atoi(av[*i]);
}
