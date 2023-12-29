#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ninja.hpp"

using namespace sf;

class block
{
    public :
        block();
        block(float x, float y, float width, float height, std::string path);
        ~block();

        void setXpos(float x);
        void setYpos(float y);
        void setWidth(float w);
        void setHeight(float h);

        float getXpos();
        float getYpos();
        float getWidth();
        float getHeight();

        sf::Texture getTexture();
        sf::Sprite getSprite();

        sf::RectangleShape getShape();

        void presence(Ninja &ninja);
    private :
        float pos_x;
        float pos_y;

        float width;
        float height;

        sf::RectangleShape blockShape;

        // Ajout de la texture et du sprite pour les objets de map
        Texture blockTexture;
        Sprite blockSprite;
};