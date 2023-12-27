#include "../header/input.hpp"
#include <SFML/Graphics.hpp>

Input::Input()
{
    button.q = false;
    button.d = false;
    button.espace = false;
    button.j = false;
    button.k = false;
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
                    break;
                case sf::Keyboard::J:
                    button.j = true;
                    break;
                case sf::Keyboard::K:
                    button.k = true;
                    break;
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
                    break;
                case sf::Keyboard::J:
                    button.j = false;
                    break;
                case sf::Keyboard::K:
                    button.k = false;
                    break;
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

void Input::checkInputQ(int speed, Ninja &p1)
{
    p1.setDirection(Ninja::Dir::Left);
    p1.move(-1 * CONST_PLAYER_SPEED * speed, 0);
    p1.setIdle(false);
}

void Input::checkInputD(int speed, Ninja &p1)
{
    p1.setDirection(Ninja::Dir::Right);
    p1.move(1 * CONST_PLAYER_SPEED * speed, 0);
    p1.setIdle(false);
}

void Input::checkInputJ(Ninja::Dir dir, Ninja &p1)
{
    if (dir == Ninja::Dir::Right)
    {
        checkInputD(CONST_PLAYER_RUN, p1);
    } else 
    {
        checkInputQ(CONST_PLAYER_RUN, p1);
    }
}

void Input::checkInputK(unsigned int dir, Ninja &p1)
{
    p1.setAttack_1(true);
    sf::Vector2f size = p1.getArmHitBoxSize();
    if (dir == Ninja::Dir::Right)
    {
        p1.setArmHitboxLength(sf::Vector2f(size.x + 53, size.y));
    } else 
    {
        p1.setArmHitboxLength(sf::Vector2f(size.x + 40, size.y));
        p1.setArmHitboxPosX(p1.getArmHitBoxPosX() - 40);
    }
}

void Input::checkInputSpace(Ninja &p1)
{
    if (p1.getJumpLength() > 0)
    {
        p1.move(0, -CONST_PLAYER_JUMP);
        p1.setJumpLength(p1.getJumpLength() - 1);
        p1.setJump(true);
    } else 
    {
        p1.setJump(false);
    }
}

void Input::checkInput(Ninja &p1)
{
    if (!p1.getonBlock() && p1.getJump() == false)
    {
        p1.move(0, CONST_GRAVITY * p1.getGravity());
        p1.setGravity(p1.getGravity() + 0.1);
    } else 
    {
        if (button.espace && p1.getonBlock())
        {
            p1.setJumpLength(30);
            p1.setGravity(1.5);
        }
    }
    checkInputSpace(p1);
    if (button.k && !p1.getAttack_1())
    {
        checkInputK(p1.getWalkCount().y, p1);
    }
    if (button.q)
    {
        if (button.j)
        {
            checkInputJ(Ninja::Dir::Left, p1);
            p1.setRun(true);
            return;
        }
        p1.setRun(false);
        checkInputQ(1, p1);
        return;
    }
    if (button.d)
    {
        if (button.j)
        {
            checkInputJ(Ninja::Dir::Right, p1);
            p1.setRun(true);
            return;
        }
        p1.setRun(false);
        checkInputD(1, p1);
        return;
    }


    p1.setRun(false);
    p1.setIdle(true);
}