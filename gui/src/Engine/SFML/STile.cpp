/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** STile
*/

#include "Engine/SFML/STile.hpp"
#include <iostream>

STile::STile(sf::Vector2i mapPosition, string type, AssetsManager *assetsManager)
    : _assetsManager(assetsManager), _type(type), _x(mapPosition.x), _y(mapPosition.y)
{
    create();
    _rect = sf::IntRect(0, 0, 32, 32);
    setRect(_rect);
}

STile::~STile()
{
    _items.clear();
}

void STile::create()
{
    _tile = _assetsManager->getSprite(_type);
    _tile.setPosition(sf::Vector2f(_x * 96, _y * 96));
    _tile.setScale(sf::Vector2f(3, 3));
    _tile.setColor(sf::Color(255, 255, 255, 255));
}

void STile::handleEvent(sf::Event event, sf::RenderWindow &window UNUSED)
{
    if (event.type == sf::Event::MouseMoved) {
        sf::Vector2i worldPosition(event.mouseMove.x, event.mouseMove.y);
        if (_tile.getGlobalBounds().contains(sf::Vector2f(worldPosition.x, worldPosition.y)))
            _tile.setColor(sf::Color(255, 255, 255, 128));
        else
            _tile.setColor(sf::Color(255, 255, 255, 255));
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i worldPosition(event.mouseMove.x, event.mouseMove.y);
        if (_tile.getGlobalBounds().contains(sf::Vector2f(worldPosition.x, worldPosition.y)))
            _isClicked = true;
        else
            _isClicked = false;
    }
}

sf::Vector2f STile::getPosition()
{
    return _tile.getPosition();
}

sf::Vector2f STile::getScale()
{
    return _tile.getScale();
}

sf::Vector2f STile::getOrigin()
{
    return _tile.getOrigin();
}

float STile::getRotation()
{
    return _tile.getRotation();
}

sf::Texture STile::getTexture()
{
    return *_tile.getTexture();
}

sf::IntRect STile::getRect()
{
    return _tile.getTextureRect();
}

vector<SItem> STile::getItems()
{
    return _items;
}

void STile::setRect(sf::IntRect rect)
{
    _tile.setTextureRect(rect);
}

void STile::setPosition(sf::Vector2f position)
{
    _tile.setPosition(position);
}

void STile::setScale(sf::Vector2f scale)
{
    _tile.setScale(scale);
}

void STile::setOrigin(sf::Vector2f origin)
{
    _tile.setOrigin(origin);
}

void STile::setRotation(float angle)
{
    _tile.setRotation(angle);
}

void STile::setTexture(sf::Texture &texture)
{
    _tile.setTexture(texture);
}

void STile::addItem(string itemType, int quantity)
{
    for (int i = 0; i < quantity; i++) {
        sf::Vector2f position(_tile.getGlobalBounds().left + 10 + (rand() % 55),
            _tile.getGlobalBounds().top + 10 + (rand() % 53));

        SItem item = SItem(_assetsManager->getSprite(itemType), itemType);
        item.setPosition(position);
        _items.push_back(item);
    }
}

void STile::addPlayer(DataPlayer &player)
{
    SPlayer splayer(player, _assetsManager);
    _players.push_back(splayer);
}

void STile::update(DataMap &Map)
{
    DataTile tile = Map.getTile(_x, _y);
    int totalItems = tile.getItemsCount();
    map<string, int> inv = tile.getInventoryMap();
    map<int, DataPlayer> players = tile.getPlayers();

    if (_items.size() != static_cast<size_t>(totalItems)) {
        _items.clear();
        for (auto &[itemType, quantity] : inv)
            addItem(itemType, quantity);
    }
    if (_players.size() != players.size()) {
        _players.clear();
        for (auto &[id, player] : players)
            addPlayer(player);
    }

    for (auto &item : _items)
        item.update(Map);
    for (auto &splayer : _players)
        for (auto &[id, player] : players)
            splayer.update(player);
}

void STile::draw(sf::RenderWindow &window, sf::View &view)
{
    window.draw(_tile);
    for (auto &item : _items)
        item.draw(window, view);
    for (auto &player : _players)
        player.draw(window, view);
}
