#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Person
{
    public:

        // Crée le perso
        Person();
        ~Person();

        // Permet de changer les attributs du perso si besoin
        void setX(float x);
        void setY(float y);
        void setSpeed(float speed);
        void setonBlock(bool on);
        void setGravity(float gravity);

        // Permet de récupérer les attributs du perso
        float getX();
        float getY();
        float getSpeed();
        float getGravity();
        bool getonBlock();
        sf::Vector2f getPos();

        // Permet de déplacer le perso
        virtual void move(float movex, float movey) = 0;

    protected:
        float x;
        float y;
        float speed;
        bool onBlock;

        // gravity speed
        float gravity;

        // Speed of animation
        sf::Clock clock;
        float fpsCount;
        float switchFps;
        float fpsSpeed;
};