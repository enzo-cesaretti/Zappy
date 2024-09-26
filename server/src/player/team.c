/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** team
*/

#include "z_team.h"

int is_team_in_args(char *team, server_args_t *args)
{
    for (int i = 0; i < args->team_count; i++)
        if (strcmp(team, args->teams[i].name) == 0 ||
        strcmp("GRAPHIC", team) == 0)
            return (i);
    return (-1);
}

int check_team(network_init_t *network, server_args_t *args)
{
    char **parsed_cmd = parser(network->buffer, " \n\t");
    int team_index = is_team_in_args(parsed_cmd[0], args);

    if (team_index >= 0) {
        if (args->teams[team_index].player_count >= args->clients_nb) {
            send_message(network->clientfds[network->i], "ko\n");
            return -1;
        } else {
            args->teams[team_index].player_count++;
            return team_index;
        }
    } else {
        send_message(network->clientfds[network->i], "ko\n");
        return -1;
    }
}

team_t *find_player_team(network_init_t *network,
    server_args_t *args, int player_index)
{
    char *team_name = network->players[player_index]->team;

    for (int i = 0; i < args->team_count; i++) {
        if (strcmp(args->teams[i].name, team_name) == 0) {
            return &args->teams[i];
        }
    }
    return NULL;
}
