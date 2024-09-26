/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** SMap
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Engine/SFML/STile.hpp"

using std::vector;

class SMap {
    public:
        SMap(AssetsManager *assetsManager);
        SMap(int width, int height, AssetsManager *assetsManager);
        ~SMap();

        void update(DataMap &map);
        void draw(sf::RenderWindow &window, sf::View &view);

    private:
        void _initMap(int width, int height);

        AssetsManager *_assetsManager;
        vector<vector<STile>> _map;
        sf::Clock _mapClock;
        sf::Sprite _background;
};
