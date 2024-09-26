/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Engine
*/

#include "Engine/Engine.hpp"
#include <map>
#include "Utils/Logger.hpp"

using std::map;

const map<sf::Event::EventType, EventType> eventMap = {
    {sf::Event::Closed, Closed},
    {sf::Event::Resized, Resized},
    {sf::Event::LostFocus, LostFocus},
    {sf::Event::GainedFocus, GainedFocus},
    {sf::Event::TextEntered, TextEntered},
    {sf::Event::KeyPressed, KeyPressed},
    {sf::Event::KeyReleased, KeyReleased},
    {sf::Event::MouseWheelMoved, MouseWheelMoved},
    {sf::Event::MouseWheelScrolled, MouseWheelScrolled},
    {sf::Event::MouseButtonPressed, MouseButtonPressed},
    {sf::Event::MouseButtonReleased, MouseButtonReleased},
    {sf::Event::MouseMoved, MouseMoved},
    {sf::Event::MouseEntered, MouseEntered},
    {sf::Event::MouseLeft, MouseLeft},
    {sf::Event::JoystickButtonPressed, JoystickButtonPressed},
    {sf::Event::JoystickButtonReleased, JoystickButtonReleased},
    {sf::Event::JoystickMoved, JoystickMoved},
    {sf::Event::JoystickConnected, JoystickConnected},
    {sf::Event::JoystickDisconnected, JoystickDisconnected},
    {sf::Event::TouchBegan, TouchBegan},
    {sf::Event::TouchMoved, TouchMoved},
    {sf::Event::TouchEnded, TouchEnded},
    {sf::Event::SensorChanged, SensorChanged},
    {sf::Event::Count, Count},
};

Engine::Engine() : _assetsManager(new AssetsManager()), _map(SMap(_assetsManager))
{
}

Engine::~Engine()
{
    delete _assetsManager;
}

// Window

void Engine::createWindow(sf::Vector2i &resolution, string title)
{
    _window.create(sf::VideoMode(resolution.x, resolution.y), title,
        sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close);
    _window.setFramerateLimit(60);
    _mainView.setSize(resolution.x, resolution.y);
}

void Engine::closeWindow()
{
    _window.close();
}

bool Engine::windowIsOpen()
{
    return _window.isOpen();
}

EventType Engine::pollEvent()
{
    if (_window.pollEvent(_event)) {
        if (eventMap.find(_event.type) != eventMap.end())
            return eventMap.at(_event.type);
    }
    return NoEvent;
}

void Engine::displayWindow()
{
    _window.display();
    _window.setView(_mainView);
}

void Engine::clearWindow()
{
    _window.clear();
}

// Map

DataMap &Engine::getMapData()
{
    return _mapData;
}

void Engine::createMap(DataMap &mapData)
{
    _mapData = mapData;
    _map = SMap(_mapData.width, _mapData.height, _assetsManager);
}

void Engine::updateMap()
{
    _map.update(_mapData);
}

void Engine::drawMap()
{
    _map.draw(_window, _mainView);
}
