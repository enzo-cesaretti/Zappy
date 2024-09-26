/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** handl_args
*/

#include "args.h"
#include <stdbool.h>

void handle_f_arg(server_args_t *args, char **av, int *i)
{
    (*i)++;
    args->freq = atoi(av[*i]);
}

void handle_default(char **av, int *i)
{
    printf("Unknown argument: %s\n", av[*i]);
    display_help();
    exit(1);
}

bool handle_first_args(char **av, int *i, server_args_t *args)
{
    switch (av[*i][1]) {
        case 'p':
            handle_p_arg(args, av, i);
            return true;
        case 'x':
            handle_x_arg(args, av, i);
            return true;
        case 'y':
            handle_y_arg(args, av, i);
            return true;
        default:
            return false;
    }
}

void handle_second_args(char **av, int *i, server_args_t *args, int ac)
{
    switch (av[*i][1]) {
        case 'n':
            handle_n_arg(args, av, ac, i);
            break;
        case 'c':
            handle_c_arg(args, av, i);
            break;
        case 'f':
            handle_f_arg(args, av, i);
            break;
        default:
            handle_default(av, i);
    }
}

void handle_arg(char **av, int *i, server_args_t *args, int ac)
{
    if (!handle_first_args(av, i, args))
        handle_second_args(av, i, args, ac);
}
