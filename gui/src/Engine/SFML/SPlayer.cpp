/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** SPlayer
*/

#include "Engine/SFML/SPlayer.hpp"
#include <iostream>

SPlayer::SPlayer(DataPlayer &player, AssetsManager *assetsManager)
{
    _assetsManager = assetsManager;
    _x = player.x;
    _y = player.y;
    setScale(sf::Vector2f(3.5, 3.5));
    setPosition(sf::Vector2f((-30) + (96 * (_x)), (-75) + ((96) * (_y))));
    setOrientation(player.getOrientation());
    _state = player.getState();
    _rect = sf::IntRect(0, 0, 48, 48);
}

SPlayer::~SPlayer()
{
}

void SPlayer::handleEvent(sf::Event event UNUSED, sf::RenderWindow &window UNUSED)
{
}

sf::Vector2f SPlayer::getPosition()
{
    return _player.getPosition();
}

sf::Vector2f SPlayer::getScale()
{
    return _player.getScale();
}

sf::Vector2f SPlayer::getOrigin()
{
    return _player.getOrigin();
}

float SPlayer::getRotation()
{
    return _player.getRotation();
}

sf::Texture SPlayer::getTexture()
{
    return *_player.getTexture();
}

sf::IntRect SPlayer::getRect()
{
    return _rect;
}

void SPlayer::setOrientation(Orientation orientation)
{
    _orientation = orientation;
}

void SPlayer::setRect(sf::IntRect rect)
{
    _player.setTextureRect(rect);
}

void SPlayer::setPosition(sf::Vector2f pos)
{
    _player.setPosition(pos);
}

void SPlayer::setScale(sf::Vector2f scale)
{
    _player.setScale(scale);
}

void SPlayer::setOrigin(sf::Vector2f origin)
{
    _player.setOrigin(origin);
}

void SPlayer::setRotation(float angle)
{
    _player.setRotation(angle);
}

void SPlayer::setTexture(sf::Texture &texture)
{
    _player.setTexture(texture);
}

void SPlayer::update(DataPlayer &player)
{
    _state = player.getState();
    _animate();
    _updateTexture(player);
    setRect(_rect);
}

void SPlayer::draw(sf::RenderWindow &window, sf::View &view UNUSED)
{
    window.draw(_player);
}

void SPlayer::_animate()
{
    switch (_state) {
        case IDLE:
            if (_rect.left >= 204)
                _rect.left = 0;
            else
                _rect.left += 48;
            break;
        case INCANTATION:
            if (_rect.left >= 480)
                _rect.left = 48;
            else
                _rect.left += 48;
            break;
        default:
            break;
    }
}

void SPlayer::_updateTexture(DataPlayer &player)
{
    switch (_state) {
        case IDLE:
            _updateIdleTexture(player);
            break;
        case INCANTATION:
            _updateIncantationTexture(player);
            break;
        default:
            break;
    }
}

void SPlayer::_updateIdleTexture(DataPlayer &player)
{
    int level = player.getLevel();
    switch (_orientation) {
        case NORTH:
            _player.setTexture(
                _assetsManager->getTexture("player_down_idle" + std::to_string(level)));
            break;
        case SOUTH:
            _player.setTexture(
                _assetsManager->getTexture("player_up_idle" + std::to_string(level)));
            break;
        case WEST:
            _player.setTexture(
                _assetsManager->getTexture("player_left_idle" + std::to_string(level)));
            break;
        case EAST:
            _player.setTexture(
                _assetsManager->getTexture("player_right_idle" + std::to_string(level)));
            break;
        default:
            break;
    }
}

void SPlayer::_updateIncantationTexture(DataPlayer &player)
{
    int level = player.getLevel();
    switch (_orientation) {
        case NORTH:
            _player.setTexture(
                _assetsManager->getTexture("player_down_incantation" + std::to_string(level)));
            break;
        case SOUTH:
            _player.setTexture(
                _assetsManager->getTexture("player_up_incantation" + std::to_string(level)));
            break;
        case WEST:
            _player.setTexture(
                _assetsManager->getTexture("player_left_incantation" + std::to_string(level)));
            break;
        case EAST:
            _player.setTexture(
                _assetsManager->getTexture("player_right_incantation" + std::to_string(level)));
            break;
        default:
            break;
    }
}
