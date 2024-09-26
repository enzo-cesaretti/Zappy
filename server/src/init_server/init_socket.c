/*
** EPITECH PROJECT, 2024
** TemplateReseau
** File description:
** init_socket
*/

#include "network_init.h"
#include "args.h"

void init_socket(network_init_t *network, server_args_t *args)
{
    network->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (network->sockfd < 0)
        send_error_message("ERROR opening socket");
    memset((char *) &network->serv_addr, 0, sizeof(network->serv_addr));
    network->portno = args->port;
}

void bind_socket(network_init_t *network)
{
    network->serv_addr.sin_family = AF_INET;
    network->serv_addr.sin_addr.s_addr = INADDR_ANY;
    network->serv_addr.sin_port = htons(network->portno);
    if (bind(network->sockfd, (struct sockaddr *) &network->serv_addr,
    sizeof(network->serv_addr)) < 0)
        send_error_message("ERROR on binding");
    listen(network->sockfd, 5);
}

void setup_fd(network_init_t *network)
{
    FD_ZERO(&network->readfds);
    FD_ZERO(&network->writefds);
    FD_SET(network->sockfd, &network->readfds);
    FD_SET(network->sockfd, &network->writefds);
    network->max_sd = network->sockfd;
    for (network->i = 0; network->i < MAX_CLIENTS; network->i++)
        update_fd(network);
}

void accept_network(network_init_t *network)
{
    network->activity = select(network->max_sd + 1,
        &network->readfds, &network->writefds, NULL, NULL);
    if ((network->activity < 0))
        send_error_message("select error");
    if (FD_ISSET(network->sockfd, &network->readfds)) {
        network->cli_len = sizeof(network->cli_addr);
        network->newsockfd = accept(network->sockfd,
            (struct sockaddr *) &network->cli_addr, &network->cli_len);
        if (network->newsockfd < 0)
            send_error_message("ERROR on accept");
        else
            send_message(network->newsockfd, "WELCOME\n");
        new_client(network);
    }
}

void update_fd(network_init_t *network)
{
    if (network->clientfds[network->i] > 0) {
        FD_SET(network->clientfds[network->i], &network->readfds);
        if (network->clientfds[network->i] > network->max_sd)
            network->max_sd = network->clientfds[network->i];
    }
}
