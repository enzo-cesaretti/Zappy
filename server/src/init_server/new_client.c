/*
** EPITECH PROJECT, 2024
** Server-Network-Managing-in-C
** File description:
** new_client
*/

#include "network_init.h"

void new_client(network_init_t *network)
{
    for (network->i = 0; network->i < MAX_CLIENTS; network->i++) {
        if (network->clientfds[network->i] == 0) {
            network->clientfds[network->i] = network->newsockfd;
            printf("[Login-%d] Client\n", network->newsockfd);
            break;
        }
    }
}
