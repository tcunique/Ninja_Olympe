#pragma once
#include "ennemy.hpp"
#include "data.hpp"

class samurai : public Ennemy
{
    public :
        samurai();
        ~samurai();

        // get
        sf::Sprite getSpriteIdle();
        sf::Texture getTextureIdle();
        sf::RectangleShape getHitBox();

        // set
        void setSpriteIdle(sf::Sprite spriteIdle);
        void setTextureIdle(sf::Texture textureIdle);

        // Load the sprite
        void SpriteIdleLoad();

        // Animation
        sf::Sprite animation();
        sf::Sprite animationIdle();
        sf::Sprite animationWalk();

        // Move bot
        void botMove();

        enum Dir {LEFT, RIGHT};
    private :
        // Animation count 
        unsigned int idleCount;
        sf::Vector2 <unsigned int> walkCount;

        // state of the ennemy
        bool idle;
        bool walk;
};