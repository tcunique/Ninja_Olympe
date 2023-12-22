#include "../header/data.hpp"
#include "../header/ennemy.hpp"

Ennemy::Ennemy()
{
    // Set position
    x = CONST_ENNEMY_POSITION_X;
    y = CONST_ENNEMY_POSITION_Y;
    speed = CONST_ENNEMY_SPEED;
    onBlock = false;
    gravity = 0;
    hp = CONST_ENNEMY_HP;
}

Ennemy::~Ennemy()
{
}

void Ennemy::move(float movex, float movey)
{
    spriteIdle.move(movex, movey);
    spriteWalk.move(movex, movey);
    hitbox.move(movex, movey);
    setX(getX() + movex);
    setY(getY() + movey);
}

sf::Sprite Ennemy::getSpriteIdle()
{
    return spriteIdle;
}

sf::Texture Ennemy::getTextureIdle()
{
    return textureIdle;
}

void Ennemy::setSpriteIdle(sf::Sprite spriteIdle)
{
    this->spriteIdle = spriteIdle;
}

void Ennemy::setTextureIdle(sf::Texture textureIdle)
{
    this->textureIdle = textureIdle;
}

