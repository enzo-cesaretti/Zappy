/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** DataPlayer
*/

#pragma once

#include <string>
#include "Inventory.hpp"

using std::string;

enum Orientation {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST,
};

enum PlayerState {
    IDLE,
    RUN,
    DEAD,
    INCANTATION,
};

class DataPlayer {
    public:
        DataPlayer(int id, Orientation orientation, string team, int level = 0);
        ~DataPlayer() = default;

        int getId();

        Orientation getOrientation();
        void setOrientation(Orientation orientation);

        int getLevel();
        void setLevel(int level);

        void setNextLevel(int level);
        int getNextLevel();

        string getTeam();
        void setTeam(string team);

        Inventory &getInventory();

        PlayerState getState();
        void setState(PlayerState state);

        int x;
        int y;

    private:
        int _id;
        Orientation _orientation;
        int _level;
        int _nextLevel;
        string _team;
        Inventory _inventory;
        PlayerState _state;
};
