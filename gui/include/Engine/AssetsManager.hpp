/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** AssetsManager
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>
#include "Assets.h"

using std::map;
using std::string;
using std::vector;

class AssetsManager {
    public:
        AssetsManager();
        ~AssetsManager();

        sf::Texture &getTexture(string textureName);
        sf::Sprite &getSprite(string spriteName);

        void loadFromFile(string path);
        void loadFromDir(string path);

    private:
        map<string, sf::Texture> _textures;
        map<string, sf::Sprite> _sprites;

        void loadItems();
        void loadTiles();
        void loadPlayers();
};
