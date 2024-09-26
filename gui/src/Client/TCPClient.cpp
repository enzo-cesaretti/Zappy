/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** TCPClient
*/

#include "Client/TCPClient.hpp"

TCPClient::TCPClient(const string &serverAddress, int serverPort)
    : _serverAddress(serverAddress), _serverPort(serverPort), _sockfd(-1)
{
    _serverAddr.sin_family = AF_INET;
    _serverAddr.sin_port = htons(_serverPort);
    _serverAddr.sin_addr.s_addr = inet_addr(_serverAddress.c_str());
}

TCPClient::~TCPClient()
{
    _closeSocket();
}

int TCPClient::getSocket() const
{
    return _sockfd;
}

bool TCPClient::isConnected() const
{
    return _sockfd >= 0;
}

bool TCPClient::connect()
{
    if (isConnected())
        return true;
    _sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (_sockfd < 0) {
        LOG_ERROR("Failed to create socket");
        return false;
    }
    if (::connect(_sockfd, (struct sockaddr *) &_serverAddr, sizeof(_serverAddr)) < 0) {
        LOG_ERROR("Failed to connect to server");
        _closeSocket();
        return false;
    }
    return true;
}

void TCPClient::disconnect()
{
    if (isConnected()) {
        _closeSocket();
        LOG_INFO("Client disconnected");
    }
}

bool TCPClient::send(const string &message)
{
    if (!isConnected()) {
        LOG_ERROR("Not connected to server");
        return false;
    }

    string msg = (message.back() == '\n') ? message : message + "\n";

    if (::send(_sockfd, msg.c_str(), msg.size(), 0) < 0) {
        LOG_ERROR("Failed to send message");
        return false;
    }
    return true;
}

string TCPClient::receive()
{
    if (!isConnected()) {
        LOG_ERROR("Not connected to server");
        return "";
    }

    string receivedMessage;
    char buffer[MAX_BUFFER_SIZE] = {0};

    int valread = ::recv(_sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (valread < 0) {
        LOG_ERROR("Failed to read message");
        return "";
    } else if (valread == 0) {
        disconnect();
        return "";
    } else {
        receivedMessage += string(buffer, valread);
        if (receivedMessage.back() == '\n')
            return receivedMessage;
        else
            return receivedMessage + receive();
    }
}

void TCPClient::_closeSocket()
{
    if (_sockfd >= 0) {
        close(_sockfd);
        _sockfd = -1;
    }
}
