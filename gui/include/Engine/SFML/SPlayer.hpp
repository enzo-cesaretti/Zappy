/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** SPlayer
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Data/DataPlayer.hpp"
#include "Engine/AssetsManager.hpp"

#define UNUSED __attribute__((unused))

using std::string;
using std::vector;

class SPlayer {
    public:
        SPlayer(DataPlayer &player, AssetsManager *assetsManager);
        ~SPlayer();

        void handleEvent(sf::Event event, sf::RenderWindow &window);

        sf::Vector2f getPosition();
        sf::Vector2f getScale();
        sf::Vector2f getOrigin();
        float getRotation();
        sf::Texture getTexture();
        sf::IntRect getRect();

        void setOrientation(Orientation orientation);

        void setRect(sf::IntRect rect);
        void setPosition(sf::Vector2f pos);
        void setScale(sf::Vector2f scale);
        void setOrigin(sf::Vector2f origin);
        void setRotation(float angle);
        void setTexture(sf::Texture &texture);

        void update(DataPlayer &player);

        void draw(sf::RenderWindow &window, sf::View &view);

    private:
        AssetsManager *_assetsManager;
        sf::Sprite _player;
        sf::IntRect _rect;
        Orientation _orientation;
        PlayerState _state;

        int _x;
        int _y;

        void _animate();

        void _updateTexture(DataPlayer &player);

        void _updateIdleTexture(DataPlayer &player);
        void _updateIncantationTexture(DataPlayer &player);
};
