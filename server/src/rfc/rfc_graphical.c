/*
** EPITECH PROJECT, 2024
** TemplateReseau
** File description:
** main
*/

#include "rfc_handling.h"
#include "network_init.h"
#include "zappy.h"
#include "tools.h"

const g_command_e_t g_cmd[] = {
    {"msz", get_map_size},
    {"bct", get_t_resources},
    {"mct", get_all_t_res},
    {"tna", list_all_team},
    {"ppo", player_pos},
    {"plv", player_level},
    {"sgt", tu_request},
    {"pnw", player_connection},
    {NULL, NULL}
};

void player_dead(zp_t *z, char *message, player_t *player)
{
    if (z->network->players[z->network->i] != NULL) {
        message[0] = '\0';
        snprintf(message, 1024, "pdi %d\n", player->id);
        send_message(z->graph_fd, message);
    }
}

void send_player_connection_message(zp_t *z)
{
    char *message = malloc(1024 * sizeof(char));
    char *player_direction = int_to_char(
        *(z->network->players[z->network->i]->direction));

    snprintf(message, 1024, "pnw %s %s %s %s %s %s\n",
            int_to_char(z->network->players[z->network->i]->id),
            int_to_char(z->network->players[z->network->i]->pos.x),
            int_to_char(z->network->players[z->network->i]->pos.y),
            player_direction,
            int_to_char(z->network->players[z->network->i]->level),
            z->network->players[z->network->i]->team);
    send_message(z->graph_fd, message);
    free(message);
}

void player_connection(int player_index, char **arg, map_t *map, zp_t *z)
{
    (void)player_index;
    (void)arg;
    (void)map;
    send_player_connection_message(z);
}

void tu_request(int fd, char **arg, map_t *map, zp_t *z)
{
    (void)arg;
    (void)map;
    (void)z;
    send_message(fd, "sgt 10\n");
}

void g_handling(char **buffer, int fd, map_t *map, zp_t *zp)
{
    char *copy;
    size_t len;
    int found = 0;

    if (!buffer[0])
        return;
    copy = strdup(buffer[0]);
    len = strlen(copy);
    if (len > 0 && copy[len - 1] == '\n')
        copy[len - 1] = '\0';
    for (size_t i = 0; g_cmd[i].name != NULL; ++i) {
        if (strcmp(copy, g_cmd[i].name) == 0) {
            g_cmd[i].handler(fd, buffer, map, zp);
            found = 1;
            break;
        }
    }
    if (found == 0)
        send_message(fd, "ko\n");
    free(copy);
}
