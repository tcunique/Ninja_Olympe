#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "block.hpp"
#include "person.hpp"
#include "samurai.hpp"
#include "ninja.hpp"


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

        // Hitbox maison
        sf::RectangleShape hitboxHouse;

    public :
        Map();
        ~Map();

        void createMap();


        std::vector<block *> getMonde();
        std::vector<block *> getGround();
        sf::RectangleShape getHitbox();
        sf::RectangleShape getHitboxHouse();
        float getHitboxPosX();
        float getHitboxPosY();
        int getHitboxWidth();
        int getHitboxHeight();

        void presenceOnGround(Ninja &ninja);
        void presenceOnGroundBot(samurai &samurai);
        
        // collisiona vec la maison
        bool collisionHouse(Ninja &ninja, sf::RenderWindow &window, sf::Event event);
        bool Input(sf::Event event, Ninja &ninja);
};