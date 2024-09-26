/*
** EPITECH PROJECT, 2024
** TemplateReseau
** File description:
** error_handling
*/

#include "network_init.h"

void send_error_message(const char *msg)
{
    perror(msg);
    exit(1);
}
