#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ninja.hpp"
#include "text.hpp"

class Item
{
    public:
        Item();
        ~Item();

        void SpriteLoad();

        // Get
        sf::Sprite getSprite() { return itemSprite; }
        sf::RectangleShape getShape() { return itemShape; }
        bool getIsPickedUp() { return isPickedUp; }
        void move(float x, float y) 
        { 
            itemSprite.move(x, y); 
            itemShape.move(x, y);
        }

        void Input(sf::Event event, Ninja &Player);

        // collision for the item to be picked up
        void collision(Ninja &Player, sf::RenderWindow &window, sf::Event event);
    
    private:
        // Hitbox de l'item
        sf::RectangleShape itemShape;

        // Texture et sprite de l'item
        sf::Texture itemTexture;
        sf::Sprite itemSprite;

        // State
        bool isPickedUp = false;
};
