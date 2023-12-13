#include "../header/person.hpp"
#include "../header/data.hpp"

Person::Person()
{
    x = CONST_POSITION_X;
    y = CONST_POSITION_Y;
    speed = CONST_PLAYER_SPEED;
    onBlock = false;
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


