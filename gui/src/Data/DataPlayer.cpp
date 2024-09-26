/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** DataPlayer
*/

#include "Data/DataPlayer.hpp"

DataPlayer::DataPlayer(int id, Orientation orientation, std::string team, int level)
{
    _id = id;
    _orientation = orientation;
    _team = team;
    _level = level;
    _nextLevel = level + 1;
    _inventory = Inventory();
    x = 0;
    y = 0;
}

int DataPlayer::getId()
{
    return _id;
}

Orientation DataPlayer::getOrientation()
{
    return _orientation;
}

void DataPlayer::setOrientation(Orientation orientation)
{
    _orientation = orientation;
}

int DataPlayer::getLevel()
{
    return _level;
}

void DataPlayer::setLevel(int level)
{
    _level = level;
}

void DataPlayer::setNextLevel(int level)
{
    _nextLevel = level;
}

int DataPlayer::getNextLevel()
{
    return _nextLevel;
}

std::string DataPlayer::getTeam()
{
    return _team;
}

void DataPlayer::setTeam(std::string team)
{
    _team = team;
}

Inventory &DataPlayer::getInventory()
{
    return _inventory;
}

PlayerState DataPlayer::getState()
{
    return _state;
}

void DataPlayer::setState(PlayerState state)
{
    _state = state;
}
