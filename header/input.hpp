#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ninja.hpp"
#include "samurai.hpp"
#include "data.hpp"
#include "menu.hpp"

using namespace sf;

class Input
{
    struct Button
    {
        bool q;
        bool d;
        bool espace;
        bool j;
        bool k;
    };

    public:
        Input();
        ~Input();
        void InputHandler(Event event, RenderWindow &interface);
        Input::Button getButton();

        void MouseInputHandler(Menu &menu);

        // Vérification des inputs
        void checkInput(Ninja &p1, samurai &samurai1);
        void checkInputQ(int speed, Ninja &p1);
        void checkInputD(int speed, Ninja &p1);
        void checkInputSpace(Ninja &p1);
        void checkInputJ(Ninja::Dir dir, Ninja &p1);
        void checkInputK(unsigned int dir, Ninja &p1);

        void attack_1(Ninja &p1, samurai &samurai1);
        
    private:
        Button button;
        sf::Event event;
};