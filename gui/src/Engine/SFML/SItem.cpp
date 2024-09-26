/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** SItem
*/

#include "Engine/SFML/SItem.hpp"

SItem::SItem(sf::Sprite &sprite, string type) : _type(type)
{
    _item = sprite;
    create();
}

SItem::~SItem()
{
}

void SItem::handleEvent(sf::Event event UNUSED, sf::RenderWindow &window UNUSED)
{
}

void SItem::create()
{
    _item.setScale(sf::Vector2f(2, 2));
    _rect = sf::IntRect(0, 0, 16, 16);
    setRect(_rect);
}

sf::Vector2f SItem::getPosition()
{
    return _item.getPosition();
}

sf::Vector2f SItem::getScale()
{
    return _item.getScale();
}

sf::Vector2f SItem::getOrigin()
{
    return _item.getOrigin();
}

float SItem::getRotation()
{
    return _item.getRotation();
}

sf::Texture SItem::getTexture()
{
    return *_item.getTexture();
}

sf::IntRect SItem::getRect()
{
    return _rect;
}

void SItem::setRect(sf::IntRect rect)
{
    _item.setTextureRect(rect);
}

void SItem::setPosition(sf::Vector2f pos)
{
    _item.setPosition(pos);
}

void SItem::setScale(sf::Vector2f scale)
{
    _item.setScale(scale);
}

void SItem::setOrigin(sf::Vector2f origin)
{
    _item.setOrigin(origin);
}

void SItem::setRotation(float angle)
{
    _item.setRotation(angle);
}

void SItem::setTexture(sf::Texture &texture)
{
    _item.setTexture(texture);
}

void SItem::update(DataMap &map UNUSED)
{
    if (_type == "food")
        return;
    _rect.left += 16;
    if (_rect.left >= 16 * 4)
        _rect.left = 0;
    setRect(_rect);
}

void SItem::draw(sf::RenderWindow &window, sf::View &view UNUSED)
{
    window.draw(_item);
}
