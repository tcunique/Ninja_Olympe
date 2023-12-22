#include "../header/player.hpp"
#include "../header/data.hpp"

Player::Player()
{
    hp = CONST_HP;
    billet = CONST_START_PIECE;
    jump_length = 0;
    numBlock = 0;

    view.setSize(CONST_VIEW_WIDTH, CONST_VIEW_HEIGHT);
    view.setCenter(x, y);
    view.zoom(2.0f);
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
    arm.move(movex, movey);
    view.move(movex, movey);
    setX(getX() + movex);
    setY(getY() + movey);
}

sf::Sprite Player::getSpriteWalk()
{
    return spriteWalk;
}

sf::RectangleShape Player::getArmHitBox()
{
    return arm;
}

sf::View Player::getView()
{
    return view;
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

sf::Vector2f Player::getArmHitBoxSize()
{
    return arm.getSize();
}

float Player::getArmHitBoxPosX()
{
    return arm.getPosition().x;
}

float Player::getArmHitBoxPosY()
{
    return arm.getPosition().y;
}

void Player::setJumpLength(int jump_length)
{
    this->jump_length = jump_length;
}

void Player::setNumBlock(int numBlock)
{
    this->numBlock += numBlock;
}

void Player::setArmHitboxLength(sf::Vector2f size)
{
    arm.setSize(size);
}

void Player::setArmHitboxPosX(float x)
{
    arm.setPosition(x, arm.getPosition().y);
}

void Player::setArmHitboxPosY(float y)
{
    arm.setPosition(arm.getPosition().x, y);
}

