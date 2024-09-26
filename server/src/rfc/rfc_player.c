/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** rfc_player
*/

#include "rfc_handling.h"
#include "network_init.h"
#include "zappy.h"
#include "tools.h"

void player_level(int fd, char **arg, map_t *map, zp_t *z)
{
    int player_id;
    char *message = malloc(1024 * sizeof(char));

    (void)arg;
    (void)map;
    if (arg[1] == NULL || z->network->players[atoi(arg[1])] == NULL)
        send_message(fd, "ko\n");
    else {
        player_id = atoi(arg[1]);
        sprintf(message, "plv #%d %d\n",
            player_id,
            z->network->players[player_id]->level
        );
        send_message(fd, message);
    }
}

void player_inv(int fd, char **arg, map_t *map, zp_t *z)
{
    int player_id = z->network->i;
    char message[1024] = "[";

    (void)arg;
    (void)map;
    for (int i = 0; i < 7; i++) {
        strcat(message, z->network->players[player_id]->inv.items[i].name);
        strcat(message, " ");
        strcat(message,
            int_to_char(z->network->players[player_id]->inv.items[i].count));
        if (i < 6)
            strcat(message, " ,");
    }
    strcat(message, "]\n");
    send_message(fd, message);
}

bool verif_more_items(char *item, map_t *map, int x, int y)
{
    if (map->tiles[x][y].mendiane > 0 && strcmp(item, "mendiane") == 0) {
        map->tiles[x][y].mendiane--;
            return true;
    }
    if (map->tiles[x][y].phiras > 0 && strcmp(item, "phiras") == 0) {
        map->tiles[x][y].phiras--;
            return true;
    }
    if (map->tiles[x][y].sibur > 0 && strcmp(item, "sibur") == 0) {
        map->tiles[x][y].sibur--;
            return true;
    }
    if (map->tiles[x][y].thystame > 0 && strcmp(item, "thystame") == 0) {
        map->tiles[x][y].thystame--;
        return true;
    }
    return false;
}

bool verif_item(char *item, map_t *map, int x, int y)
{
    if (map->tiles[x][y].food > 0 && strcmp(item, "food") == 0) {
        map->tiles[x][y].food--;
        return true;
    }
    if (map->tiles[x][y].deraumere > 0 && strcmp(item, "deraumere") == 0) {
        map->tiles[x][y].deraumere--;
        return true;
    }
    if (map->tiles[x][y].linemate > 0 && strcmp(item, "linemate") == 0) {
        map->tiles[x][y].linemate--;
        return true;
    }
    return (verif_more_items(item, map, x, y));
}

void player_take(int fd, char **arg, map_t *map, zp_t *z)
{
    int player_id = z->network->i;
    int player_x = z->network->players[player_id]->pos.x;
    int player_y = z->network->players[player_id]->pos.y;
    inventory_t *inv = &z->network->players[player_id]->inv;
    char *stone = NULL;

    if (arg[1] == NULL) {
        send_message(fd, "ko\n");
        return;
    }
    stone = arg[1];
    for (int i = 0; i < 7; i++) {
        if (strcmp(inv->items[i].name, stone) == 0 &&
            verif_item(stone, map, player_x, player_y) == true) {
            inv->items[i].count++;
            send_message(fd, "ok\n");
            return;
        }
    }
}
