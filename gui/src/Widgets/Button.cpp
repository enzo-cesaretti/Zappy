/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Button
*/

#include "Widgets/Button.hpp"

Button::Button(const string text, sf::Font &font, sf::Vector2f position, sf::Vector2f size)
{
    _button = sf::RectangleShape();
    _button.setPosition(position);
    _button.setSize(size);

    _text.setFont(font);
    _text.setString(text);
    _text.setCharacterSize(30);
    _text.setFillColor(sf::Color::White);
    _centerText();

    _onClick = []() {
    };
}

void Button::handleEvent(sf::Vector2f mousePos, sf::Event &event)
{
    if (_isHover(mousePos)) {
        if (_isPress(mousePos, event)) {
            _button.setTexture(&_buttonPressed);
            _onClick();
        } else {
            _button.setTexture(&_buttonHover);
        }
    } else {
        _button.setTexture(&_buttonTexture);
    }
}

void Button::setOnClick(std::function<void()> onClick)
{
    _onClick = onClick;
}

sf::Texture Button::getTexture() const
{
    return _buttonTexture;
}

sf::Texture Button::getPressedTexture() const
{
    return _buttonPressed;
}

sf::Texture Button::getHoverTexture() const
{
    return _buttonHover;
}

sf::Vector2f Button::getPosition() const
{
    return _button.getPosition();
}

sf::Vector2f Button::getSize() const
{
    return _button.getSize();
}

string Button::getText() const
{
    return _text.getString();
}

unsigned int Button::getCharacterSize() const
{
    return _text.getCharacterSize();
}

sf::Color Button::getTextColor() const
{
    return _text.getFillColor();
}

sf::Font Button::getFont() const
{
    return *_text.getFont();
}

void Button::setTexture(sf::Texture &texture)
{
    _buttonTexture = texture;
    _button.setTexture(&_buttonTexture);

    sf::Vector2u size = texture.getSize();
    _button.setSize(sf::Vector2f(size.x, size.y));
    _centerText();
}

void Button::setPressedTexture(sf::Texture &texture)
{
    _buttonPressed = texture;
    _button.setTexture(&_buttonPressed);

    sf::Vector2u size = texture.getSize();
    _button.setSize(sf::Vector2f(size.x, size.y));
    _centerText();
}

void Button::setHoverTexture(sf::Texture &texture)
{
    _buttonHover = texture;
    _button.setTexture(&_buttonHover);

    sf::Vector2u size = texture.getSize();
    _button.setSize(sf::Vector2f(size.x, size.y));
    _centerText();
}

void Button::setPosition(sf::Vector2f position)
{
    _button.setPosition(position);
    _centerText();
}

void Button::setSize(sf::Vector2f size)
{
    _button.setSize(size);
    _centerText();
}

void Button::setText(const string text)
{
    _text.setString(text);
    _centerText();
}

void Button::setFont(sf::Font &font)
{
    _text.setFont(font);
    _centerText();
}

void Button::setCharacterSize(unsigned int size)
{
    _text.setCharacterSize(size);
    _centerText();
}

void Button::setTextColor(sf::Color color)
{
    _text.setFillColor(color);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(_button, states);
    target.draw(_text, states);
}

bool Button::_isHover(sf::Vector2f mousePos)
{
    return _button.getGlobalBounds().contains(mousePos);
}

bool Button::_isPress(sf::Vector2f mousePos, sf::Event &event)
{
    return _isHover(mousePos) && event.type == sf::Event::MouseButtonPressed;
}

void Button::_centerText()
{
    auto textRect = _text.getLocalBounds();
    _text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    _text.setPosition(_button.getPosition().x + _button.getSize().x / 2.0f,
        _button.getPosition().y + _button.getSize().y / 2.0f);
}
