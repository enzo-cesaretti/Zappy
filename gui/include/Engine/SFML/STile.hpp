/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** STile
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <vector>
#include "Data/DataMap.hpp"
#include "Engine/AssetsManager.hpp"
#include "Engine/SFML/SPlayer.hpp"
#include "SItem.hpp"

using std::map;
using std::string;
using std::vector;

#define TILE_SIZE 32

class STile {
    public:
        STile(sf::Vector2i mapPosition, string type, AssetsManager *assetsManager);
        ~STile();

        void handleEvent(sf::Event event, sf::RenderWindow &window);

        void create();

        sf::Vector2f getPosition();
        sf::Vector2f getScale();
        sf::Vector2f getOrigin();
        float getRotation();
        sf::Texture getTexture();
        sf::IntRect getRect();
        vector<SItem> getItems();

        void setRect(sf::IntRect rect);
        void setPosition(sf::Vector2f position);
        void setScale(sf::Vector2f scale);
        void setOrigin(sf::Vector2f origin);
        void setRotation(float angle);
        void setTexture(sf::Texture &texture);

        void addItem(string itemType, int quantity = 1);
        void addPlayer(DataPlayer &player);

        void update(DataMap &map);

        void draw(sf::RenderWindow &window, sf::View &view);

    private:
        AssetsManager *_assetsManager;
        sf::IntRect _rect;
        sf::Sprite _oceanTile;
        sf::Sprite _tile;
        string _type;
        int _x;
        int _y;
        bool _isClicked;
        vector<SItem> _items;
        vector<SPlayer> _players;
};
