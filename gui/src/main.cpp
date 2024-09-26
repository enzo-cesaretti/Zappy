/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** main
*/

#include <iostream>
#include <thread>
#include "ArgumentHandler.hpp"
#include "Zappy.hpp"

int main(int ac UNUSED, char **av)
{
    try {
        ArgumentHandler argHandler;
        argHandler.handleArguments(ac, av);

        Zappy::Zappy zappy;

        bool verbose = argHandler.getVerboseFlag();
        string ip = argHandler.getIp();
        int port = argHandler.getPort();

        zappy.connect(ip, port);
        if (verbose)
            zappy.enableVerbose();

        zappy.run();

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
