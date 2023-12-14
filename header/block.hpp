#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/thomas.hpp"

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
        Texture getTexture();
        Sprite getSprite();

        sf::RectangleShape getShape();

        void presence(Thomas &thomas);

    private :
        float pos_x;
        float pos_y;

        float width;
        float height;

        // Ajout de la texture et du sprite pour les objets de map
        Texture blockTexture;
        Sprite blockSprite;

        sf::RectangleShape blockShape;
};