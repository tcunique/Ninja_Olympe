#include "../header/input.hpp"
#include <SFML/Graphics.hpp>

Input::Input()
{
    button.q = false;
    button.d = false;
    button.espace = false;
}

Input::~Input()
{
}

void Input::InputHandler(Event event, RenderWindow &interface)
{
    if (event.type == sf::Event::Closed)
        interface.close();
    
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
            interface.close();
    }
    
    
    switch(event.type)
    {
        case sf::Event::KeyPressed:
            switch(event.key.code)
            {
                case sf::Keyboard::Q:
                    button.q = true;
                    break;
                case sf::Keyboard::D:
                    button.d = true;
                    break;
                case sf::Keyboard::Space:
                    button.espace = true;
                default:
                    break;
            }
            break;
        case sf::Event::KeyReleased:
            switch(event.key.code)
            {
                case sf::Keyboard::Q:
                    button.q = false;
                    break;
                case sf::Keyboard::D:
                    button.d = false;
                    break;
                case sf::Keyboard::Space:
                    button.espace = false;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    
}

Input::Button Input::getButton()
{
    return button;
}
