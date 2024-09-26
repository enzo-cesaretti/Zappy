/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** SMap
*/

#include "Engine/SFML/SMap.hpp"
#include <iostream>

SMap::SMap(AssetsManager *assetsManager) : _assetsManager(assetsManager)
{
    _mapClock = sf::Clock();
    _background = _assetsManager->getSprite("background");
}

SMap::SMap(int width, int height, AssetsManager *assetsManager) : _assetsManager(assetsManager)
{
    _mapClock = sf::Clock();
    _background = _assetsManager->getSprite("background");
    _initMap(width, height);
}

SMap::~SMap()
{
}

void SMap::update(DataMap &Map)
{
    const sf::Time frameTime = sf::milliseconds(Map.getFrequency());

    if (_mapClock.getElapsedTime() > frameTime) {
        _mapClock.restart();
        for (auto &row : _map)
            for (auto &tile : row)
                tile.update(Map);
    }
}

void SMap::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(_background);
    for (size_t y = 0; y < _map.size(); y++)
        for (size_t x = 0; x < _map[y].size(); x++)
            _map[y][x].draw(window, view);
}

void SMap::_initMap(int width, int height)
{
    _background.setPosition(-460, -50);
    for (int y = 0; y < height; y++) {
        std::vector<STile> row;
        for (int x = 0; x < width; x++) {
            sf::Vector2i pos(x, y);
            std::string type;
            if (x == 0 && y == 0)
                type = "grass_left_top";
            else if (x == width - 1 && y == 0)
                type = "grass_right_top";
            else if (x == 0 && y == height - 1)
                type = "grass_left_down";
            else if (x == width - 1 && y == height - 1)
                type = "grass_right_down";
            else if (y == 0)
                type = "grass_middle_top";
            else if (x == 0)
                type = "grass_middle_left";
            else if (x == width - 1)
                type = "grass_middle_right";
            else if (y == height - 1)
                type = "grass_middle_down";
            else
                type = "grass";
            STile tile(pos, type, _assetsManager);
            row.push_back(tile);
        }
        _map.push_back(row);
    }

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            _map[y][x].create();
}
