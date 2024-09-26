/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** InputBox
*/

#include "Widgets/InputBox.hpp"
#include <iostream>

InputBox::InputBox(const sf::Font &font, const sf::Vector2f position, const sf::Vector2f size)
    : _isFocused(false)
{
    _box.setPosition(position);
    _box.setSize(size);
    _box.setFillColor(sf::Color::White);
    _box.setOutlineColor(sf::Color::Black);
    _box.setOutlineThickness(2);

    _text.setFont(font);
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(position.x + 5, position.y + 5);

    _input = "";
    _placeholder = "Enter text here...";
}

void InputBox::handleEvent(sf::Vector2f mousePos, const sf::Event &event)
{
    if (_isFocused && event.type == sf::Event::TextEntered) {
        _processInput(event.text.unicode);
        return;
    }
    if (_isHover(mousePos)) {
        _box.setTexture(&_boxTextureFocused);
        if (_isPress(mousePos, event))
            _isFocused = true;
    } else {
        _box.setTexture(&_boxTexture);
        _isFocused = false;
    }
}

string InputBox::getInput() const
{
    return _input;
}

sf::Texture InputBox::getTexture() const
{
    return _boxTexture;
}

sf::Texture InputBox::getTextureFocused() const
{
    return _boxTextureFocused;
}

string InputBox::getPlaceholder() const
{
    return _placeholder;
}

sf::Vector2f InputBox::getPosition() const
{
    return _box.getPosition();
}

sf::Vector2f InputBox::getSize() const
{
    return _box.getSize();
}

sf::Font InputBox::getFont() const
{
    return *_text.getFont();
}

unsigned int InputBox::getCharacterSize() const
{
    return _text.getCharacterSize();
}

void InputBox::setTexture(const sf::Texture &texture)
{
    _boxTexture = texture;
    _box.setTexture(&_boxTexture);

    sf::Vector2u size = texture.getSize();
    _box.setSize(sf::Vector2f(size.x, size.y));
}

void InputBox::setTextureFocused(const sf::Texture &texture)
{
    _boxTextureFocused = texture;
    _box.setTexture(&_boxTextureFocused);

    sf::Vector2u size = texture.getSize();
    _box.setSize(sf::Vector2f(size.x, size.y));
}

void InputBox::setPosition(const sf::Vector2f position)
{
    _box.setPosition(position);
    _text.setPosition(position.x + 5, position.y + 5);
}

void InputBox::setSize(const sf::Vector2f size)
{
    _box.setSize(size);
}

void InputBox::setFont(const sf::Font &font)
{
    _text.setFont(font);
}

void InputBox::setCharacterSize(const unsigned int size)
{
    _text.setCharacterSize(size);
}

void InputBox::setPlaceholder(const string placeholder)
{
    _placeholder = placeholder;
}

void InputBox::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_box, states);
    if (_input.empty()) {
        sf::Text placeholderText(_placeholder, *_text.getFont(), _text.getCharacterSize());
        placeholderText.setFillColor(sf::Color(128, 128, 128));
        placeholderText.setPosition(_text.getPosition());
        target.draw(placeholderText, states);
    } else {
        target.draw(_text, states);
    }
}

bool InputBox::_isHover(sf::Vector2f mousePos)
{
    return _box.getGlobalBounds().contains(mousePos);
}

bool InputBox::_isPress(sf::Vector2f mousePos, const sf::Event &event)
{
    return _isHover(mousePos) && event.type == sf::Event::MouseButtonPressed;
}

void InputBox::_processInput(sf::Uint32 unicode)
{
    if (unicode < 128 && unicode != 8)
        _input += unicode;
    else if (unicode == 8 && !_input.empty())
        _input.pop_back();
    _text.setString(_input);
}
