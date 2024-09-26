/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Button
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <string>

using std::string;

class Button : public sf::Drawable {
    public:
        Button(const string text, sf::Font &font, sf::Vector2f pos = {0, 0},
            sf::Vector2f size = {0, 0});
        ~Button() = default;

        void handleEvent(sf::Vector2f mousePos, sf::Event &event);

        void setOnClick(std::function<void()> onClick);

        sf::Texture getTexture() const;
        sf::Texture getPressedTexture() const;
        sf::Texture getHoverTexture() const;

        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;
        string getText() const;
        unsigned int getCharacterSize() const;
        sf::Color getTextColor() const;
        sf::Font getFont() const;

        void setTexture(sf::Texture &texture);
        void setPressedTexture(sf::Texture &texture);
        void setHoverTexture(sf::Texture &texture);

        void setPosition(sf::Vector2f pos);
        void setSize(sf::Vector2f size);
        void setText(const string text);
        void setFont(sf::Font &font);
        void setCharacterSize(unsigned int size);
        void setTextColor(sf::Color color);

    private:
        virtual void draw(
            sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;

        bool _isHover(sf::Vector2f mousePos);
        bool _isPress(sf::Vector2f mousePos, sf::Event &event);

        void _centerText();

        sf::RectangleShape _button;
        sf::Texture _buttonTexture;
        sf::Texture _buttonPressed;
        sf::Texture _buttonHover;
        sf::Text _text;

        std::function<void()> _onClick;
};
