/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** DataMap
*/

#include "Data/DataMap.hpp"
#include <iostream>
#include <stdexcept>

DataMap::DataMap(int width, int height)
{
    this->width = width;
    this->height = height;
    _map.resize(this->height);
    for (int i = 0; i < this->height; i++)
        _map[i].resize(this->width);
    for (int y = 0; y < this->height; y++)
        for (int x = 0; x < this->width; x++)
            _map.at(y).at(x).setPosition(x, y);
    _frequency = 1;
}

void DataMap::setTile(int x, int y, DataTile tile)
{
    _map.at(y).at(x) = tile;
}

DataTile &DataMap::getTile(int x, int y)
{
    return _map.at(y).at(x);
}

int DataMap::getFrequency() const
{
    return _frequency;
}

void DataMap::setFrequency(int frequency)
{
    _frequency = frequency;
}

void DataMap::addTeam(string name)
{
    if (_teams.find(name) == _teams.end())
        _teams[name] = vector<int>();
}

DataPlayer &DataMap::getPlayer(int id)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            map<int, DataPlayer> players = _map.at(y).at(x).getPlayers();
            if (players.find(id) != players.end())
                return _map.at(y).at(x).getPlayer(id);
        }
    }
    throw std::runtime_error("Player not found");
}

void DataMap::addPlayer(DataPlayer player, int x, int y)
{
    _teams[player.getTeam()].push_back(player.getId());
    _map.at(y).at(x).addPlayer(player);
}

void DataMap::movePlayer(int id, int x, int y)
{
    DataPlayer &player = getPlayer(id);
    removePlayer(id);
    player.x = x;
    player.y = y;
    addPlayer(player, x, y);
}

void DataMap::removePlayer(int id)
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            map<int, DataPlayer> players = _map.at(y).at(x).getPlayers();
            if (players.find(id) != players.end())
                return _map.at(y).at(x).removePlayer(id);
        }
    }
    throw std::runtime_error("Player not found");
}
