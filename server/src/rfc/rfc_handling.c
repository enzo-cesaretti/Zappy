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

const command_entry_t commands[] = {
    {"Right", right_command},
    {"Forward", forward_command},
    {"Left", left_command},
    {"Look", vision_cmd},
    {"Inventory", player_inv},
    {"Take", player_take},
    {"Connect_nbr", player_connect_nbr},
    {"Broadcast", broadcast_cmd},
    {NULL, NULL}
};

void player_connect_nbr(int fd, char **arg, map_t *map, zp_t *z)
{
    int player_in_team;
    int empty_slot;
    char message[1024];

    (void)arg;
    (void)map;
    for (int i = 0; i < z->args->team_count; i++)
        if (strcmp(z->network->players[z->network->i]->team,
            z->args->teams[i].name) == 0) {
            player_in_team = z->args->teams[i].player_count;
            empty_slot = z->args->clients_nb - player_in_team;
        }
    snprintf(message, sizeof(message), "%s\n", int_to_char(empty_slot));
    send_message(fd, message);
}

void player_pos(int player_index, char **arg, map_t *map, zp_t *z)
{
    char *message = malloc(1024 * sizeof(char));

    (void)arg;
    (void)map;
    sprintf(message, "ppo %d %d %d %d\n",
        z->network->players[player_index]->id,
        z->network->players[player_index]->pos.x,
        z->network->players[player_index]->pos.y,
        (*(z->network->players[player_index]->direction) + 1)
    );
    send_message(z->graph_fd, message);
}

void list_all_team(int fd, char **arg, map_t *map, zp_t *z)
{
    char *message = calloc(1024, sizeof(char));

    (void)arg;
    (void)map;
    for (int i = 0; i < z->args->team_count; i++) {
        strcat(message, "tna ");
        strcat(message, z->args->teams[i].name);
        strcat(message, "\n");
    }
    send_message(fd, message);
    free(message);
}

void get_map_size(int fd, char **arg, map_t *map, zp_t *z)
{
    int mapWidth = z->map->width;
    int mapHeight = z->map->height;
    char *buffer = malloc(sizeof(mapWidth) + sizeof(mapHeight) + 3);

    (void)arg;
    (void)map;
    sprintf(buffer, "msz %d %d\n", mapWidth, mapHeight);
    send_message(fd, buffer);
    free(buffer);
}

void rfc_handling(char **buffer, int fd, map_t *map, zp_t *zp)
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
    for (size_t i = 0; commands[i].name != NULL; ++i) {
        if (strcmp(copy, commands[i].name) == 0) {
            commands[i].handler(fd, buffer, map, zp);
            found = 1;
            break;
        }
    }
    if (found == 0)
        send_message(fd, "ko\n");
    free(copy);
}
