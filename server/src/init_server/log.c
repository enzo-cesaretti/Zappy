/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** log
*/

#include "network_init.h"
#include "rfc_handling.h"
#include "tools.h"
#include "args.h"
#include "tools.h"
#include "player.h"
#include "z_team.h"
#include "debug.h"
#include "zappy.h"
#include "gll.h"

void client_disconnect(zp_t *z,
    server_args_t *args, map_t *map, player_t *player)
{
    team_t *player_team = NULL;
    char *message = malloc(sizeof(char) * 1024);

    if (z->network->players[z->network->i] != NULL) {
        player_team = find_player_team(z->network, args, z->network->i);
        if (player_team != NULL)
            player_team->player_count--;
        gll_remove(map->tiles[player->pos.x][player->pos.y].players, 0);
    }
    player_dead(z, message, player);
    printf("[Logout-%d]\n", z->network->clientfds[z->network->i]);
    close(z->network->clientfds[z->network->i]);
    z->network->clientfds[z->network->i] = 0;
    if (z->network->players[z->network->i]) {
        free(z->network->players[z->network->i]->team);
        free(z->network->players[z->network->i]);
        z->network->players[z->network->i] = NULL;
    }
}

void check_if_player_already_exist(char **parsed_cmd,
    network_init_t *network, map_t *map)
{
    player_t *player = create_player(parsed_cmd[0], 0, 0);

    printf("Player id: %d\n", player->id);
    player = manage_player(player, map);
    network->players[network->i] = player;
    place_player_on_map(player, map);
    print_map(map);
}

void handle_player_connection(zp_t *z, int team_index, server_args_t *args,
    char **parsed_cmd)
{
    const int message_size = 1024;
    char team_count[message_size];
    char p_pos[message_size];

    player_connection(z->network->clientfds[z->network->i],
        parsed_cmd, z->map, z);
    snprintf(team_count, message_size, "%d\n", args->clients_nb
        - args->teams[team_index].player_count);
    snprintf(p_pos, message_size, "%d %d\n", z->network->players
        [z->network->i]->pos.x, z->network->players[z->network->i]->pos.y);
    send_message(z->network->clientfds[z->network->i], team_count);
    send_message(z->network->clientfds[z->network->i], p_pos);
    z->network->players[z->network->i]->is_connected = true;
}

void check_and_connect_player(zp_t *z, char **parsed_cmd,
    server_args_t *args, map_t *map)
{
    int team_index = check_team(z->network, args);

    if (z->network->players[z->network->i] == NULL && team_index >= 0) {
        check_if_player_already_exist(parsed_cmd, z->network, map);
        if (z->network->players[z->network->i] != NULL &&
            strcmp(z->network->players[z->network->i]->team, "GRAPHIC") == 0) {
            connect_graphic_player(z, parsed_cmd, map);
        } else {
            handle_player_connection(z, team_index, args, parsed_cmd);
        }
    }
}

void handle_log(char **parsed_cmd, server_args_t *args, map_t *map, zp_t *z)
{
    network_init_t *nw = z->network;

    if (nw->players[nw->i] != NULL && nw->players[nw->i]->is_connected &&
    strcmp(nw->players[nw->i]->team, "GRAPHIC") == 0) {
        process_graphic_players(nw, parsed_cmd, map, z);
    } else if (nw->players[nw->i] !=
        NULL && nw->players[nw->i]->is_connected) {
        rfc_handling(parsed_cmd, nw->clientfds[nw->i], map, z);
    } else
        check_and_connect_player(z, parsed_cmd, args, map);
}
