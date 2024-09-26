/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** DataMap
*/

#pragma once

#include <vector>
#include "Data/DataTile.hpp"

using std::vector;

class DataMap {
    public:
        DataMap(int width, int height);
        DataMap() = default;
        ~DataMap() = default;

        void setTile(int x, int y, DataTile tile);
        DataTile &getTile(int x, int y);

        int getFrequency() const;
        void setFrequency(int frequency);

        void addTeam(string name);

        DataPlayer &getPlayer(int id);
        void addPlayer(DataPlayer player, int x, int y);
        void movePlayer(int id, int x, int y);
        void removePlayer(int id);

        int width;
        int height;

    private:
        map<string, vector<int>> _teams;
        vector<vector<DataTile>> _map;
        int _frequency;
};
