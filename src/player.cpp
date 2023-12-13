#include "../header/player.hpp"
#include "../header/data.hpp"

Player::Player()
{
    hp = CONST_HP;
    billet = CONST_START_PIECE;
}

Player::~Player()
{
}

void Player::move(float movex, float movey)
{
    if (onBlock == false)
    {
        spriteIdle.move(movex, movey);
        spriteWalk.move(movex, movey);
        spriteJump.move(movex, movey);
        hitbox.move(movex, movey);
        setX(getX() + movex);
        setY(getY() + movey);
    } else 
    {
        spriteIdle.move(movex, movey);
        spriteWalk.move(movex, movey);
        spriteJump.move(movex, movey);
        hitbox.move(movex, movey);
        setX(getX() + movex);
        setY(getY() + movey);
    }
}

sf::Sprite Player::getSpriteWalk()
{
    return spriteWalk;
}

sf::Texture Player::getTextureWalk()
{
    return textureWalk;
}

sf::Sprite Player::getSpriteIdle()
{
    return spriteIdle;
}

sf::Texture Player::getTextureIdle()
{
    return textureIdle;
}
