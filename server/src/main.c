/*
** EPITECH PROJECT, 2024
** TemplateReseau
** File description:
** main
*/

#include "zappy.h"

void init_player_tab(network_init_t *network)
{
    for (int i = 0; i < MAX_CLIENTS; i++)
        network->players[i] = NULL;
}

void free_everything(server_args_t *args,
    network_init_t *network, serv_info_t *serv_info)
{
    for (int i = 0; i < args->team_count; i++)
    free(args->teams[i].name);
    free(args->teams);
    free(args);
    free(network);
    free(serv_info);
}

void zappy(zp_t *zp)
{
    while (zp->serv_info->is_running == 1) {
        timer(zp->serv_info, zp->start_time);
        setup_fd(zp->network);
        accept_network(zp->network);
        loop_server(zp->network, zp->args, zp->map, zp);
    }
}

int main(int ac, char **av)
{
    zp_t *zp = malloc(sizeof(zp_t));

    zp->network = malloc(sizeof(network_init_t));
    zp->serv_info = malloc(sizeof(serv_info_t));
    zp->args = parse_args(ac, av);
    zp->map = NULL;
    init_player_tab(zp->network);
    srand(time(NULL));
    zp->map = create_map(zp->args->width, zp->args->height);
    init_socket(zp->network, zp->args);
    bind_socket(zp->network);
    zp->start_time = init_timer();
    zp->serv_info->is_running = 1;
    zappy(zp);
    free_everything(zp->args, zp->network, zp->serv_info);
    free(zp);
    return 0;
}
