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
        void setHitBoxArm();

        // Load the sprite
        void SpriteIdleLoad();
        void SpriteWalkLoad();
        void SpriteRunLoad();
        void SpriteAttack1Load();
        void SpriteHurtLoad();
        void SpriteDeathLoad();
    private :
        // hp 
};