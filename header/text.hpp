#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class UIText
{
    public :
        UIText();
        ~UIText();

        void TextLoad();
        void TextDisplay(sf::RenderWindow &window, std::string str);

        void move(float x, float y) { text.move(x, y); }

    private:
        sf::Font font;
        sf::Text text;
};