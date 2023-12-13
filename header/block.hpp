#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/thomas.hpp"

class block
{
    public :
        block();
        ~block();

        void setXpos(float x);
        void setYpos(float y);
        void setWidth(float w);
        void setHeight(float h);

        float getXpos();
        float getYpos();
        float getWidth();
        float getHeight();

        sf::RectangleShape getShape();

        void presence(Thomas &thomas);
    private :
        float pos_x;
        float pos_y;

        float width;
        float height;

        sf::RectangleShape blockShape;
};