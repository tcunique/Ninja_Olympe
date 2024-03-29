#include "../header/person.hpp"
#include "../header/data.hpp"

Person::Person()
{
    x = CONST_POSITION_X;
    y = CONST_POSITION_Y;
    speed = CONST_PLAYER_SPEED;
    onBlock = false;
    gravity = 0;

    // Animation speed
    fpsCount = 0;
    switchFps = 4;
    fpsSpeed = 100;
}

sf::Vector2f Person::getPos()
{
    return sf::Vector2f(x, y);
}

float Person::getGravity()
{
    return gravity;
}

Person::~Person()
{
}

void Person::setX(float x)
{
    this->x = x;
}

void Person::setY(float y)
{
    this->y = y;
}

void Person::setSpeed(float speed)
{
    this->speed = speed;
}

void Person::setGravity(float gravity)
{
    this->gravity = gravity;
}

void Person::setonBlock(bool on)
{
    onBlock = on;
}

float Person::getX()
{
    return x;
}

float Person::getY()
{
    return y;
}

float Person::getSpeed()
{
    return speed;
}

bool Person::getonBlock()
{
    return onBlock;
}


