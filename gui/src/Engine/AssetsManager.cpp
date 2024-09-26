/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** AssetsManager
*/

#include "Engine/AssetsManager.hpp"
#include <filesystem>
#include <iostream>

#define ITEMS_MAX_SIZE 7
#define TILES_MAX_SIZE 18

AssetsManager::AssetsManager()
{
    loadItems();
    loadTiles();
    loadPlayers();
}

AssetsManager::~AssetsManager()
{
}

sf::Texture &AssetsManager::getTexture(string textureName)
{
    return _textures[textureName];
}

sf::Sprite &AssetsManager::getSprite(string spriteName)
{
    return _sprites[spriteName];
}

void AssetsManager::loadFromFile(string path)
{
    if (!std::filesystem::exists(path))
        return;
    string filename = path.substr(path.find_last_of("/") + 1);
    filename = filename.substr(0, filename.find_last_of("."));
    if (_textures.find(filename) != _textures.end())
        return;
    _textures[filename] = sf::Texture();
    if (!_textures[filename].loadFromFile(path))
        return;
    if (_sprites.find(filename) == _sprites.end())
        _sprites[filename] = sf::Sprite(_textures[filename]);
}

void AssetsManager::loadFromDir(string path)
{
    if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path))
        return;
    for (const auto &entry : std::filesystem::directory_iterator(path))
        loadFromFile(entry.path().string());
}

void AssetsManager::loadItems()
{
    // Items
    loadFromDir("../gui/assets/items/gems/");
    loadFromFile("../gui/assets/items/food.png");
}

void AssetsManager::loadTiles()
{
    this->loadFromDir("../gui/assets/map");
}

void AssetsManager::loadPlayers()
{
    // Idle
    loadFromDir(PLAYER_TEXTURE_PATH + string("idle/"));
    // Run
    loadFromDir(PLAYER_TEXTURE_PATH + string("run/"));
    // Death
    loadFromDir(PLAYER_TEXTURE_PATH + string("death/"));
    // Incantation
    loadFromDir(PLAYER_TEXTURE_PATH + string("incantation/"));
}
