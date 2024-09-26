/*
** EPITECH PROJECT, 2024
** B-YEP-400-MLN-4-1-zappy-guillian.tissier
** File description:
** args
*/

#include "args.h"

void display_help(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height");
    printf(" -n name1 name2 ... -c clientsNb -f freq\n");
    printf("option description\n");
    printf("-p port port number\n");
    printf("-x width width of the world\n");
    printf("-y height height of the world\n");
    printf("-n name1 name2 .. . name of the team\n");
    printf("-c clientsNb number of authorized clients per team\n");
    printf("-f freq reciprocal of time unit for execution of actions\n");
}

void process_args(int ac, char **av, int *i, server_args_t *args)
{
    if (av[*i][0] == '-') {
        handle_arg(av, i, args, ac);
    } else if (strcmp(av[*i], "help") == 0) {
        display_help();
        exit(0);
    } else {
        printf("Unknown argument: %s\n", av[*i]);
        display_help();
        exit(1);
    }
}

server_args_t *parse_args(int ac, char **av)
{
    server_args_t *args = malloc(sizeof(server_args_t));

    args->teams = malloc(sizeof(team_t) * ac);
    args->team_count = 0;
    for (int i = 1; i < ac; i++)
        process_args(ac, av, &i, args);
    return (args);
}
