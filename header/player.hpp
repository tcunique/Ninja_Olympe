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

    protected:
        // Hitbox
        sf::RectangleShape hitbox;

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

        // Vie, argent
        float hp;
        int billet;
};