/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** timer
*/

#include <stdio.h>
#include <time.h>
#include "network_init.h"
#include "server.h"

time_t init_timer(void)
{
    time_t start_time;

    time(&start_time);
    return (start_time);
}

void timer(serv_info_t *serv_info, time_t start_time)
{
    time_t current_time;

    time(&current_time);
    serv_info->seconds = difftime(current_time, start_time);
}
