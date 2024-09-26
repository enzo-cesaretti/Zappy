/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Zappy
*/

#include "Zappy.hpp"
#include <iostream>
#include <thread>
#include "Data/DataPlayer.hpp"

namespace Zappy
{

    Zappy::Zappy() : _engine(), _dataMap(), _client(), _commandHandler()
    {
        _clock = sf::Clock();
        _init();

        Logger &log = Logger::getInstance();
        log.disable();
    }

    Zappy::~Zappy()
    {
    }

    void Zappy::enableVerbose()
    {
        Logger &log = Logger::getInstance();
        log.enable();
    }

    void Zappy::_init()
    {
        sf::Vector2i windowSize = {1920, 1080};
        _engine.createWindow(windowSize, "Zappy");
    }

    bool Zappy::update()
    {
        EventType event = NoEvent;

        while ((event = _engine.pollEvent()) != NoEvent) {
            if (event == EventType::Closed) {
                _engine.closeWindow();
                return false;
            }
        }
        return true;
    }

    void Zappy::draw()
    {
        _engine.clearWindow();
        _engine.drawMap();
        _engine.displayWindow();
    }

    void Zappy::connect(const std::string &ip, int port)
    {
        _client = TCPClient(ip, port);
        _client.connect();

        string recv = _client.receive();
        recv.pop_back();
        if (recv != "WELCOME") {
            _client.disconnect();
            throw std::runtime_error("Connection to server failed");
        }
        _client.send("GRAPHIC");
    }

    void Zappy::handleSelect()
    {
        int max_fd = _client.getSocket();
        FD_SET(max_fd, &_readfds);
        FD_SET(max_fd, &_writefds);

        int ret = select(max_fd + 1, &_readfds, &_writefds, NULL, NULL);
        if (ret < 0) {
            _client.disconnect();
            throw std::runtime_error("Select failed");
        }
        if (FD_ISSET(max_fd, &_readfds)) {
            string recv = _client.receive();
            if (recv.empty())
                return;
            _commandHandler.setBuffer(recv);
            _commandHandler.handleCommand(_engine);
        }
    }

    void Zappy::run()
    {
        FD_ZERO(&_readfds);
        FD_ZERO(&_writefds);

        while (1) {
            if (_clock.getElapsedTime() >= sf::seconds(0.1)) {
                if (!update())
                    break;
                draw();
                _client.send("\n");
                handleSelect();
                _clock.restart();
            }
        }
    }
} // namespace Zappy
