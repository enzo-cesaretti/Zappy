/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** broadcast
*/

#include "rfc_handling.h"
#include "network_init.h"
#include "zappy.h"
#include "tools.h"

void broadcast_message_to_clients(zp_t *z, char *message)
{
    for (int id = 4; MAX_CLIENTS > id; id++) {
        if (id == z->graph_fd) {
            send_message(id, "pbc ");
            send_message(id,
                int_to_char(z->network->players[z->network->i]->id));
            send_message(id, " ");
        }
        send_message(id, message);
    }
}

void broadcast_cmd(int fd, char **arg, map_t *map, zp_t *z)
{
    char *message = calloc(1, 1);

    (void)map;
    (void)fd;
    for (int i = 1; arg[i] != NULL; i++) {
        message = realloc(message, (message ? strlen(message) : 0)
            + strlen(arg[i]) + 3);
        if (message == NULL)
            return;
        strcat(message, arg[i]);
        strcat(message, " ");
    }
    if (message) {
        message[strlen(message) - 1] = '\0';
        strcat(message, "\n");
    }
    broadcast_message_to_clients(z, message);
    free(message);
}
