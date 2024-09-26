/*
 ** EPITECH PROJECT, 2024
 ** zappy
 ** File description:
 ** Zappy
 */

#pragma once

#include "Client/CommandHandler.hpp"
#include "Client/TCPClient.hpp"
#include "Engine/Engine.hpp"

namespace Zappy
{
    class Zappy {
        public:
            Zappy();
            ~Zappy();

            void enableVerbose();

            bool update();
            void draw();
            void connect(const std::string &ip, int port);
            void run();

            void handleSelect();

        private:
            Engine _engine;
            DataMap _dataMap;
            TCPClient _client;
            CommandHandler _commandHandler;

            sf::Clock _clock;

            fd_set _readfds;
            fd_set _writefds;

            void _init();
    };
} // namespace Zappy
