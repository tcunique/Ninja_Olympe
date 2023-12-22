#pragma once
#include "person.hpp"
#include "data.hpp"

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

        // set
        void setSpriteIdle(sf::Sprite spriteIdle);
        void setTextureIdle(sf::Texture textureIdle);

    protected:
        // Le perso en idle
        sf::Sprite spriteIdle;
        sf::Texture textureIdle;

        // Le perso en mouvement
        sf::Sprite spriteWalk;
        sf::Texture textureWalk;
        
        // hp 
        int hp;

        // hitbox 
        sf::RectangleShape hitbox;
        sf::RectangleShape hitboxBody;
};