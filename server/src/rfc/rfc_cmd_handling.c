/*
** EPITECH PROJECT, 2024
** TemplateReseau
** File description:
** main
*/

#include "rfc_handling.h"
#include "network_init.h"
#include "zappy.h"

void get_t_resources(int fd, char **arg, map_t *map, zp_t *z)
{
    char *buffer = malloc(sizeof(char) * 1024);
    int x;
    int y;

    (void) z;
    if (arg[1] && arg[2]) {
        x = atoi(arg[1]);
        y = atoi(arg[2]);
    } else {
        send_message(fd, "ko\n");
        return;
    }
    (void)arg;
    sprintf(buffer, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
        map->tiles[y][x].food, map->tiles[y][x].linemate,
        map->tiles[y][x].deraumere, map->tiles[y][x].sibur,
        map->tiles[y][x].mendiane, map->tiles[y][x].phiras,
        map->tiles[y][x].thystame);
    send_message(fd, buffer);
    free(buffer);
}

void get_all_t_res(int fd, char **arg, map_t *map, zp_t *z)
{
    int width = map->width;
    int height = map->height;
    int x = 0;
    int y = 0;
    char *buffer;

    (void)arg;
    (void)z;
    for (x = 0; x < width; x++) {
        for (y = 0; y < height; y++) {
            buffer = malloc(sizeof(char) * 1024);
            sprintf(buffer, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
            map->tiles[y][x].food, map->tiles[y][x].linemate,
            map->tiles[y][x].deraumere, map->tiles[y][x].sibur,
            map->tiles[y][x].mendiane, map->tiles[y][x].phiras,
            map->tiles[y][x].thystame);
        send_message(fd, buffer);
        free(buffer);
        }
    }
}
