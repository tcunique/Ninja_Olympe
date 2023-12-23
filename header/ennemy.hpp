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

        // Move
        void walkFunction();
        void runFunction();
        void gravityFunction();

        // Move bot
        void botMove();
        void followPlayer(Ninja &ninja);
        void mainMove(Ninja &ninja);

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

        // Animation count 
        unsigned int idleCount;
        sf::Vector2 <unsigned int> walkCount;
        unsigned int runCount;

        // hitbox 
        sf::RectangleShape hitbox;
        sf::RectangleShape hitboxBody;

        // state of the ennemy
        bool idle;
        bool walk;
        bool run;
};