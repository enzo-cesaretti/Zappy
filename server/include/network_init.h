/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** network_init
*/

#ifndef NETWORK_INIT_H_
    #define NETWORK_INIT_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include "zappy.h"

    #include "args.h"
    #include "player.h"

    #define MAX_CLIENTS 1024
    #define BUFFER_SIZE 1024

typedef struct network_init {
    int sockfd;
    int newsockfd;
    int portno;
    int clientfds[MAX_CLIENTS];
    int is_logged_in[MAX_CLIENTS];
    socklen_t cli_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    int max_sd;
    int activity;
    int i;
    int valread;
    fd_set readfds;
    fd_set writefds;
    player_t *players[MAX_CLIENTS];
} network_init_t;

void send_error_message(const char *msg);
void init_socket(network_init_t *network, server_args_t *args);
void bind_socket(network_init_t *network);
void setup_fd(network_init_t *network);
void accept_network(network_init_t *network);
void update_fd(network_init_t *network);
void new_client(network_init_t *network);
void send_message(int sockfd, char *message);
#endif /* !NETWORK_INIT_H_ */
