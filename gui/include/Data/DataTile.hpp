/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** DataTile
*/

#pragma once

#include <map>
#include <string>
#include "DataPlayer.hpp"
#include "Inventory.hpp"

using std::map;
using std::string;

class DataTile {
    public:
        DataTile();
        ~DataTile() = default;

        void setPosition(int x, int y);

        int getItemsCount();

        map<int, DataPlayer> &getPlayers();

        Inventory &getInventory();
        map<string, int> getInventoryMap();

        DataPlayer &getPlayer(int id);
        void addPlayer(DataPlayer player);
        void movePlayer(int id, int x, int y);
        void removePlayer(int id);

    private:
        map<int, DataPlayer> _players;
        Inventory _inventory;
        int _x;
        int _y;
};
