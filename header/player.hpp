#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include "person.hpp"
#include "healthbar.hpp"

class Player : public Person
{
    public:
        // Crée le perso
        Player();
        ~Player();

        // Permet de déplacer le perso
        void move(float movex, float movey);

        // Permet de récupmérer les attributs du perso
        sf::Sprite getSpriteWalk();
        sf::Texture getTextureWalk();
        sf::Sprite getSpriteIdle();
        sf::Texture getTextureIdle();
        int getJumpLength();
        sf::View getView();
        sf::RectangleShape getHitbox();
        sf::RectangleShape getArmHitBox();
        sf::RectangleShape getHitBoxBody();
        sf::Vector2f getArmHitBoxSize();
        float getArmHitBoxPosX();
        float getArmHitBoxPosY();
        bool getAlive();

        // Permet de modifier les attributs du perso
        void setJumpLength(int jump_length);
        void setArmHitboxLength(sf::Vector2f size);
        void setArmHitboxPosX(float x);
        void setArmHitboxPosY(float y);
        void setDirection(Dir direction);
        void setAlive(bool resp);

        // Getter
        bool getIdle();
        unsigned int getJumpCount();
        bool getJump();
        bool getRun();
        bool getAttack_1();
        sf::Vector2<unsigned int> getWalkCount();
        float getLife();
        healthBar& getHealthBar();

        //Setter
        void setIdle(bool resp);
        void setJump(bool resp);
        void setJumpCount(unsigned int count);
        void setRun(bool resp);
        void setAttack_1(bool resp);
        void setLife(float life);
        void setHurt(bool resp);

        // Animation
        sf::Sprite animation();
        sf::Sprite animationWalk();
        sf::Sprite animationJump();
        sf::Sprite animationIdle();
        sf::Sprite animationRun();
        sf::Sprite animationAttack_1();
        sf::Sprite animationHurt();
        sf::Sprite animationDeath();

        // View of the player
        sf::View view;

        // Healthbar
        void displayHealthBar(sf::RenderWindow &window);

        //attack 
        

        bool checkAlive();

    protected:
        // Healthbar
        healthBar healthbar {true};

        // Hitbox
        sf::RectangleShape hitbox;
        sf::RectangleShape arm;
        sf::RectangleShape hitboxBody;

        // Le perso en mouvement
        sf::Sprite spriteWalk;
        sf::Texture textureWalk;

        // Le perso en idle
        sf::Sprite spriteIdle;
        sf::Texture textureIdle;

        // Le perso en sautant;
        sf::Sprite spriteJump;
        sf::Texture textureJump;

        // Le perso en run
        sf::Sprite spriteRun;
        sf::Texture textureRun;

        // Le perso en attaque 1
        sf::Sprite spriteAttack_1;
        sf::Texture textureAttack_1;

        // Le perso en hurt
        sf::Sprite spriteHurt;
        sf::Texture textureHurt;

        // Le perso en death
        sf::Sprite spriteDeath;
        sf::Texture textureDeath;

        int jump_length;

        // Animation frame
        unsigned int idle_count;
        unsigned int jump_count;
        unsigned int run_count;
        unsigned int attack_1_count;
        sf::Vector2<unsigned int> walk_count;
        unsigned int hurt_count;
        unsigned int death_count;

        // state
        bool idle;
        bool jump;
        bool walk_state;
        bool run_state;
        bool attack_1_state;
        bool isAlive;
        bool isHurt;

        // Hp of the player
        float hp;
};