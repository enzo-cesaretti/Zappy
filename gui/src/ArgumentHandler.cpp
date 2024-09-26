/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ArgumentHandler
*/

#include "ArgumentHandler.hpp"

void ArgumentHandler::handleArguments(int ac, char **av)
{
    if (ac < 5 || ac > 6) {
        std::cerr << "Usage: ./zappy_gui -p [port] -h [ip] --verbose" << std::endl;
        exit(84);
    }

    _port = std::stoi(av[2]);
    _ip = string(av[4]) == "localhost" ? "127.0.0.1" : string(av[4]);

    if (ac == 6 && string(av[5]) == "--verbose") {
        _verbose = true;
    } else {
        _verbose = false;
    }
}

bool ArgumentHandler::getVerboseFlag()
{
    return _verbose;
}

string ArgumentHandler::getIp()
{
    return _ip;
}

int ArgumentHandler::getPort()
{
    return _port;
}
