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
        healthBar &getHealthBar();
        float getLife();

        // set
        void setSpriteIdle(sf::Sprite spriteIdle);
        void setTextureIdle(sf::Texture textureIdle);
        void setWalkY(Dir walkY);
        void setArmHitboxLength(sf::Vector2f size);
        void setArmHitboxPosX(float x);
        void setArmHitboxPosY(float y);
        void setLife(float life);
        void setHurt(bool resp);

        // Animation
        sf::Sprite animation();
        sf::Sprite animationIdle();
        sf::Sprite animationWalk();
        sf::Sprite animationRun();
        sf::Sprite animationAttack1();
        sf::Sprite animationHurt();
        sf::Sprite animationDeath();

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

        // Healthbar
        void displayHealthBar(Ninja p1, sf::RenderWindow &window);

        bool checkAlive();

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

        // Ennemy in hurt mode
        sf::Sprite spriteHurt;
        sf::Texture textureHurt;

        // Ennemy in death mode
        sf::Sprite spriteDeath;
        sf::Texture textureDeath;

        // Animation count 
        unsigned int idleCount;
        sf::Vector2 <unsigned int> walkCount;
        unsigned int runCount;
        unsigned int attackCount1;
        unsigned int hurtCount;
        unsigned int deathCount;

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
        bool isHurt;
        bool isAlive;

        bool alreadyAttack;

        // Healthbar
        healthBar healthbar {false};
        float hp;
};