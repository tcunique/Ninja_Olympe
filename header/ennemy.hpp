#pragma once
#include "person.hpp"
#include "data.hpp"
#include "healthbar.hpp"
#include "ninja.hpp"

class Ennemy : public Person
{
    public:
        Ennemy();
        ~Ennemy();

        void move(float movex, float movey);

        // get
        sf::Sprite getSpriteIdle();
        sf::Texture getTextureIdle();
        sf::RectangleShape getHitBox();
        sf::RectangleShape getHitBoxBody();
        sf::RectangleShape getHitBoxArm();
        unsigned int getWalkY();

        // set
        void setSpriteIdle(sf::Sprite spriteIdle);
        void setTextureIdle(sf::Texture textureIdle);
        void setWalkY(Dir walkY);
        void setArmHitboxLength(sf::Vector2f size);
        void setArmHitboxPosX(float x);
        void setArmHitboxPosY(float y);

        // Animation
        sf::Sprite animation();
        sf::Sprite animationIdle();
        sf::Sprite animationWalk();
        sf::Sprite animationRun();
        sf::Sprite animationAttack1();

        // Move
        void walkFunction();
        void runFunction();
        void gravityFunction();

        // Move bot
        void botMove();
        void followPlayer(Ninja &ninja, healthBar &healthbar);
        void mainMove(Ninja &ninja, healthBar &healthbar);

        // Elapsed time for attack
        bool elpasedTime();
        void attackPlayer(Ninja &ninja, healthBar &healthbar);

    protected:
        // Le perso en idle
        sf::Sprite spriteIdle;
        sf::Texture textureIdle;

        // Le perso en mouvement
        sf::Sprite spriteWalk;
        sf::Texture textureWalk;

        // Le perso en course
        sf::Sprite spriteRun;
        sf::Texture textureRun;

        // Ennemy in attack mode
        sf::Sprite spriteAttack_1;
        sf::Texture textureAttack_1;

        // Animation count 
        unsigned int idleCount;
        sf::Vector2 <unsigned int> walkCount;
        unsigned int runCount;
        unsigned int attackCount1;

        // hitbox 
        sf::RectangleShape hitbox;
        sf::RectangleShape hitboxBody;
        sf::RectangleShape hitboxArm;

        // Elapsed time for attack
        sf::Clock clockAttack;

        // state of the ennemy
        bool idle;
        bool walk;
        bool run;
        bool attack1;
        bool attack;

        bool alreadyAttack;
};