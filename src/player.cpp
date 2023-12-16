#include "../header/player.hpp"
#include "../header/data.hpp"

Player::Player()
{
    hp = CONST_HP;
    billet = CONST_START_PIECE;
    jump_length = 0;
    numBlock = 0;
}

Player::~Player()
{
}

void Player::move(float movex, float movey)
{
    spriteIdle.move(movex, movey);
    spriteWalk.move(movex, movey);
    spriteJump.move(movex, movey);
    spriteRun.move(movex, movey);
    spriteAttack_1.move(movex, movey);
    hitbox.move(movex, movey);
    setX(getX() + movex);
    setY(getY() + movey);
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

int Player::getJumpLength()
{
    return jump_length;
}

int Player::getNumBlock()
{
    return numBlock;
}

void Player::setJumpLength(int jump_length)
{
    this->jump_length = jump_length;
}

void Player::setNumBlock(int numBlock)
{
    this->numBlock += numBlock;
}