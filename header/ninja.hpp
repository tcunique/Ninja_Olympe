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

    private :
        std::string name;

        // Vie, argent
        int billet;
};