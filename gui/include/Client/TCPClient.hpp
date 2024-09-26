/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** TCPClient
*/

#pragma once

#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "Utils/Logger.hpp"

using std::string;

#define MAX_BUFFER_SIZE 4096

class TCPClient {
    public:
        TCPClient(const string &serverAddress = "", int serverPort = 8080);
        ~TCPClient();

        int getSocket() const;

        bool isConnected() const;
        bool connect();
        void disconnect();

        bool send(const string &message);
        string receive();

    private:
        string _serverAddress;
        int _serverPort;
        int _sockfd;
        struct sockaddr_in _serverAddr;

        void _closeSocket();
};
