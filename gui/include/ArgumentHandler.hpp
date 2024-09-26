/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ArgumentHandler
*/

#pragma once

#include <iostream>
#include <string>

using std::string;

class ArgumentHandler {
    public:
        ArgumentHandler() = default;
        ~ArgumentHandler() = default;

        void handleArguments(int ac, char **av);
        bool getVerboseFlag();
        string getIp();
        int getPort();

    private:
        bool _verbose = false;
        string _ip;
        int _port;
};
