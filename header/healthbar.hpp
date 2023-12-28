#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class healthBar
{
    public:
        healthBar();
        ~healthBar();

        sf::Sprite getSpriteHealthBar();
        sf::Texture getTextureHealthBar();
        sf::ConvexShape getHealthBarShape();

        // Set
        void setSpriteHealthBar(sf::Sprite spriteHealthBar);
        void setTextureHealthBar(sf::Texture textureHealthBar);
        void setHealthBarPos(sf::Vector2f pos);
        void setHealth(float health);

        void SpriteHealthBarL();
        void convexHealthBarL();
        void updateColor();

    private:
        sf::Sprite SpritehealthBar;
        sf::Texture textureHealthBar;

        sf::ConvexShape healthBarShape;
        float health;
};