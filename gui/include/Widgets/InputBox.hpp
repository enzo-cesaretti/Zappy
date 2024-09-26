/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** InputBox
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using std::string;

class InputBox : public sf::Drawable {
    public:
        InputBox(const sf::Font &font, const sf::Vector2f position = {0, 0},
            const sf::Vector2f size = {50, 50});
        ~InputBox() = default;

        string getInput() const;

        void handleEvent(sf::Vector2f mousePos, const sf::Event &event);

        sf::Texture getTexture() const;
        sf::Texture getTextureFocused() const;

        string getPlaceholder() const;

        void setTexture(const sf::Texture &texture);
        void setTextureFocused(const sf::Texture &texture);

        sf::Vector2f getPosition() const;
        sf::Vector2f getSize() const;
        sf::Font getFont() const;
        unsigned int getCharacterSize() const;

        void setPosition(const sf::Vector2f position);
        void setSize(const sf::Vector2f size);
        void setFont(const sf::Font &font);
        void setCharacterSize(const unsigned int size);

        void setPlaceholder(const string placeholder);

    private:
        virtual void draw(
            sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;

        bool _isHover(sf::Vector2f mousePos);
        bool _isPress(sf::Vector2f mousePos, const sf::Event &event);

        sf::RectangleShape _box;
        sf::Texture _boxTexture;
        sf::Texture _boxTextureFocused;
        sf::Text _text;
        string _input;
        string _placeholder;
        bool _isFocused;

        void _processInput(sf::Uint32 unicode);
};
