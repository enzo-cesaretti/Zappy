/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** graphic_log
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

void process_graphic_players(network_init_t *nw,
    char **parsed_cmd, map_t *map, zp_t *z)
{
    get_all_t_res(nw->clientfds[nw->i], parsed_cmd, map, z);
    for (int player_index = 0; player_index < MAX_CLIENTS; player_index++) {
        if (nw->players[player_index] != NULL &&
            nw->players[player_index]->pos_change == 1) {
            player_pos(player_index, parsed_cmd, map, z);
            nw->players[player_index]->pos_change = 0;
        }
    }
}

void connect_graphic_player(zp_t *z, char **parsed_cmd, map_t *map)
{
    z->network->players[z->network->i]->is_connected = true;
    if (z->gui_nb_cmd == 0) {
        z->graph_fd = z->network->clientfds[z->network->i];
        get_map_size(z->network->clientfds[z->network->i], parsed_cmd, map, z);
        tu_request(z->network->clientfds[z->network->i], parsed_cmd, map, z);
        list_all_team(z->graph_fd, parsed_cmd, map, z);
        z->gui_nb_cmd++;
    }
}
