#pragma once
#include "player.hpp"

// Sprite 

class Ninja : public Player
{
    public:
        Ninja();
        ~Ninja();

        //Getter
        std::string getName();

        // Set les hitbox pour le perso
        void setHitbox();
        void setHitboxBody();
        void setHitBoxArm();

        // Init sprite
        void spriteLaunch();
        void spriteWalkL();
        void spriteIdleL();
        void spriteJumpL();
        void spriteRunL();
        void spriteAttack_1L();
        void spriteHurtL();
        void spriteDeathL();

        // Surcharge de la méthode affichage
        friend std::ostream& operator<<(std::ostream& os, const Ninja &Ninja)
        {
            os << "Ninja : " << std::endl;
            os << "Hp : " << Ninja.hp << std::endl;
            os << "x : " << Ninja.x << std::endl;
            os << "y : " << Ninja.y << std::endl;
            os << "speed : " << Ninja.speed << std::endl;
            os << "isAlive : " << Ninja.isAlive << std::endl;

            return os;
        }

    private :
        std::string name;

        // Vie, argent
        int billet;
};