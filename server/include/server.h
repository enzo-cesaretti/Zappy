/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** server
*/

#pragma once

#include <time.h>

typedef struct serv_info {
    int is_running;
    int seconds;
} serv_info_t;

void timer(serv_info_t *serv_info, time_t start_time);
time_t init_timer(void);
