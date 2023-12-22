#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include "person.hpp"

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
        int getNumBlock();
        sf::View getView();
        sf::RectangleShape getArmHitBox();
        sf::Vector2f getArmHitBoxSize();
        float getArmHitBoxPosX();
        float getArmHitBoxPosY();

        // Permet de modifier les attributs du perso
        void setJumpLength(int jump_length);
        void setArmHitboxLength(sf::Vector2f size);
        void setArmHitboxPosX(float x);
        void setArmHitboxPosY(float y);

        // Permet de modifier si le perso est au sol
        void setNumBlock(int numBlock);

        // void animeHealthBar();

        // View of the player
        sf::View view;

    protected:
        // Hitbox
        sf::RectangleShape hitbox;
        sf::RectangleShape arm;

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

        // Vie, argent
        float hp;
        int billet;
        int jump_length;

        // Variable de présence
        int numBlock;
};