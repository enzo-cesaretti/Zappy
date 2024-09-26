/*
** EPITECH PROJECT, 2024
** Server-Network-Managing-in-C
** File description:
** loop_server
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

void loop_server(network_init_t *network, server_args_t *args,
    map_t *map, zp_t *z)
{
    for (network->i = 0; network->i < MAX_CLIENTS; network->i++)
        if (FD_ISSET(network->clientfds[network->i], &network->readfds))
            manage_client(network, args, map, z);
}

void manage_client(network_init_t *nw, server_args_t *args,
    map_t *map, zp_t *z)
{
    char **parsed_cmd = NULL;

    nw->valread = read(nw->clientfds[nw->i], nw->buffer, BUFFER_SIZE);
    if (nw->valread != 0) {
        nw->buffer[nw->valread] = '\0';
        printf("Cli inf: [%d]: %s", nw->clientfds[nw->i], nw->buffer);
        parsed_cmd = parser(nw->buffer, " \n\t#");
        handle_log(parsed_cmd, args, map, z);
    } else {
        client_disconnect(z, args, map, nw->players[nw->i]);
        return;
    }
}
