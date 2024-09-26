/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** send
*/

#include "network_init.h"

void send_message(int sockfd, char *message)
{
    if (send(sockfd, message, strlen(message), 0) < 0)
        return;
}
