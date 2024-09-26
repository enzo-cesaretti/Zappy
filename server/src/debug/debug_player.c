/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** debug_player
*/

#include "debug.h"

int count_connected_players(network_init_t *network)
{
    int count = 0;

    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (network->players[i] != NULL) {
            count++;
        }
    }
    return (count);
}
