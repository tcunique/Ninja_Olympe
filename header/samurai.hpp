#pragma once
#include "ennemy.hpp"
#include "data.hpp"
#include <iostream>

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

        // Surcharge de la méthode affichage
        friend std::ostream& operator<<(std::ostream& os, const samurai &Samurai)
        {
            os << "Samurai : " << std::endl;
            os << "Hp : " << Samurai.hp << std::endl;
            os << "x : " << Samurai.x << std::endl;
            os << "y : " << Samurai.y << std::endl;
            os << "speed : " << Samurai.speed << std::endl;
            os << "isAlive : " << Samurai.isAlive << std::endl;

            return os;
        }
    private :
        // hp 
};