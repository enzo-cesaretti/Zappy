/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Engine
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "AssetsManager.hpp"
#include "Event.hpp"
#include "SFML/SMap.hpp"
#include "SFML/STile.hpp"

using std::string;

class Engine {
    public:
        Engine();
        ~Engine();

        // Event

        EventType pollEvent();

        // Window

        void createWindow(sf::Vector2i &resolution, string title);
        void closeWindow();
        bool windowIsOpen();
        void displayWindow();
        void clearWindow();

        // Map

        DataMap &getMapData();
        void createMap(DataMap &mapData);
        void updateMap();
        void drawMap();

    private:
        AssetsManager *_assetsManager;
        SMap _map;
        DataMap _mapData;

        sf::RenderWindow _window;
        sf::Event _event;
        sf::View _mainView;
};
