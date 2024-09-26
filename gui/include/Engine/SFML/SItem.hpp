/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** SItem
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Data/DataMap.hpp"

#define UNUSED __attribute__((unused))

using std::string;
using std::vector;

enum ItemType {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    PLAYER,
};

class SItem {
    public:
        SItem();
        SItem(sf::Sprite &sprite, string type);
        ~SItem();

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
        void setPosition(sf::Vector2f pos);
        void setScale(sf::Vector2f scale);
        void setOrigin(sf::Vector2f origin);
        void setRotation(float angle);
        void setTexture(sf::Texture &texture);

        void update(DataMap &map);

        void draw(sf::RenderWindow &window, sf::View &view);

    private:
        sf::Sprite _item;
        sf::IntRect _rect;
        string _type;
};
