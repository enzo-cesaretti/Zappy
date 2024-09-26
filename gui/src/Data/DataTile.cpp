/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** DataTile
*/

#include "Data/DataTile.hpp"
#include <iostream>

DataTile::DataTile() : _inventory()
{
}

void DataTile::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

int DataTile::getItemsCount()
{
    return _inventory.food + _inventory.linemate + _inventory.deraumere + _inventory.sibur
        + _inventory.mendiane + _inventory.phiras + _inventory.thystame;
}

std::map<int, DataPlayer> &DataTile::getPlayers()
{
    return _players;
}

Inventory &DataTile::getInventory()
{
    return _inventory;
}

std::map<std::string, int> DataTile::getInventoryMap()
{
    std::map<std::string, int> inventoryMap;

    inventoryMap["food"] = _inventory.food;
    inventoryMap["linemate"] = _inventory.linemate;
    inventoryMap["deraumere"] = _inventory.deraumere;
    inventoryMap["sibur"] = _inventory.sibur;
    inventoryMap["mendiane"] = _inventory.mendiane;
    inventoryMap["phiras"] = _inventory.phiras;
    inventoryMap["thystame"] = _inventory.thystame;
    return inventoryMap;
}

DataPlayer &DataTile::getPlayer(int id)
{
    return _players.at(id);
}

void DataTile::addPlayer(DataPlayer player)
{
    int id = player.getId();
    if (_players.find(id) == _players.end()) {
        player.x = _x;
        player.y = _y;
        std::pair<int, DataPlayer> playerPair(id, player);
        _players.insert(playerPair);
    }
}

void DataTile::removePlayer(int id)
{
    if (_players.find(id) != _players.end())
        _players.erase(id);
}
