#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ninja.hpp"
#include "data.hpp"

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

        // Vérification des inputs
        void checkInput(Ninja &p1);
        void checkInputQ(int speed, Ninja &p1);
        void checkInputD(int speed, Ninja &p1);
        void checkInputSpace(Ninja &p1);
        void checkInputJ(Ninja::Dir dir, Ninja &p1);
        void checkInputK(Ninja::Dir dir, Ninja &p1);
        
    private:
        Button button;
        sf::Event event;
};