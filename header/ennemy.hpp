#pragma once
#include "person.hpp"
#include "data.hpp"
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
        void followPlayer(Ninja &ninja);
        void mainMove(Ninja &ninja);

        // Elapsed time for attack
        bool elpasedTime();

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
};