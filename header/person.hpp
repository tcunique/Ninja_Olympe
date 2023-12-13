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

        // Permet de récupérer les attributs du perso
        float getX();
        float getY();
        float getSpeed();
        bool getonBlock();

        // Permet de déplacer le perso
        virtual void move(float movex, float movey) = 0;

    protected:
        float x;
        float y;
        float speed;
        bool onBlock;
};