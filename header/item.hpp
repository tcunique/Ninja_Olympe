#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Item
{
    public:
        Item();
        ~Item();

        void SpriteLoad();

        // Get
        sf::Sprite getSprite() { return itemSprite; }
        void move(float x, float y) { itemSprite.move(x, y); }
    
    private:
        // Hitbox de l'item
        sf::RectangleShape itemShape;

        // Texture et sprite de l'item
        sf::Texture itemTexture;
        sf::Sprite itemSprite;
};
