#pragma once
#include "ennemy.hpp"
#include "data.hpp"

class samurai : public Ennemy
{
    public :
        samurai();
        ~samurai();

        // Set
        void setHitbox();
        void setHitboxBody();

        // Load the sprite
        void SpriteIdleLoad();
        void SpriteWalkLoad();
        void SpriteRunLoad();
    private :
        // hp 
        int hp;
};