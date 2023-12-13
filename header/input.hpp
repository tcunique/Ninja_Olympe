#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

class Input
{
    struct Button
    {
        bool q;
        bool d;
        bool espace;
    };

    public:
        Input();
        ~Input();
        void InputHandler(Event event, RenderWindow &interface);
        Input::Button getButton();
        
    private:
        Button button;
        sf::Event event;
};