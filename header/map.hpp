#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "block.hpp"


using namespace sf;

class Map
{
    private :
        std::vector<block *> monde; 
        std::vector<block *> ground;

        int numBlock;

        // Pour la hitbox du sol
        sf::RectangleShape hitbox;
        int hitboxWidth;
        int hitboxHeight;
        float hitboxPosX;
        float hitboxPosY;

    public :
        Map();
        ~Map();

        void createMap();

        std::vector<block *> getMonde();
        std::vector<block *> getGround();
        sf::RectangleShape getHitbox();
        float getHitboxPosX();
        float getHitboxPosY();
        int getHitboxWidth();
        int getHitboxHeight();

        void presenceOnGround(Ninja &ninja);
};