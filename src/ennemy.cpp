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
    
    // Animation count
    idleCount = 1;
    walkCount.x = 1;
    walkCount.y = Dir::Left;

    // State of the ennemy
    idle = true;
    walk = false;
    run = false;
}

Ennemy::~Ennemy()
{
}

void Ennemy::move(float movex, float movey)
{
    spriteIdle.move(movex, movey);
    spriteWalk.move(movex, movey);
    spriteRun.move(movex, movey);
    hitbox.move(movex, movey);
    hitboxBody.move(movex, movey);
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

unsigned int Ennemy::getWalkY()
{
    return walkCount.y;
}

sf::RectangleShape Ennemy::getHitBox()
{
    return hitbox;
}

sf::RectangleShape Ennemy::getHitBoxBody()
{
    return hitboxBody;
}

void Ennemy::setSpriteIdle(sf::Sprite spriteIdle)
{
    this->spriteIdle = spriteIdle;
}

void Ennemy::setTextureIdle(sf::Texture textureIdle)
{
    this->textureIdle = textureIdle;
}

void Ennemy::setWalkY(Dir walkY)
{
    walkCount.y = walkY;
}

sf::Sprite Ennemy::animationIdle()
{
    if (idleCount * 128 >= textureIdle.getSize().x)
    {
        idleCount = 1;
    }
    if (walkCount.y == Dir::Right)
    {
        spriteIdle.setTextureRect(sf::IntRect(idleCount * 128, 0, 128, 128));
    } else 
    {
        spriteIdle.setTextureRect(sf::IntRect(idleCount * 128, 0, -128, 128));
    }
    fpsCount = 0;
    idleCount++;
    return spriteIdle;
}

sf::Sprite Ennemy::animationWalk()
{
    if (walkCount.x * 128 >= textureWalk.getSize().x)
    {
        walkCount.x = 1;
    }
    if (walkCount.y == Dir::Right)
    {
        // std::cout << "Right" << std::endl;
        spriteWalk.setTextureRect(sf::IntRect(walkCount.x * 128, 0, 128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idleCount * 128, 0, 128, 128)); // Permet d'éviter d'avoir des conflits de sens
    } else 
    {
        // std::cout << "Left" << std::endl;
        spriteWalk.setTextureRect(sf::IntRect(walkCount.x * 128, 0, -128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idleCount * 128, 0, -128, 128)); // Pareil, empêche les conflits de sens
    }

    fpsCount = 0;
    walkCount.x++;
    return spriteWalk;
}

sf::Sprite Ennemy::animationRun()
{
    if (runCount * 128 >= textureRun.getSize().x)
    {
        runCount = 1;
    }
    if (walkCount.y == Dir::Right)
    {
        spriteRun.setTextureRect(sf::IntRect(runCount * 128, 0, 128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idleCount * 128, 0, 128, 128)); // Permet d'éviter d'avoir des conflits de sens
    } else 
    {
        spriteRun.setTextureRect(sf::IntRect(runCount * 128, 0, -128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idleCount * 128, 0, -128, 128)); // Pareil, empêche les conflits de sens
    }
    fpsCount = 0;
    runCount++;
    return spriteRun;
}

sf::Sprite Ennemy::animation()
{
    if(fpsCount < switchFps)
    {
        fpsCount += 1;
    } 

    // Permet de fixer un fps et que l'image de ne se charge pas tout le temps
    if (fpsCount >= switchFps)
    {
        if (run == true && onBlock == true)
        {
            return animationRun();
        } else 
        {
            if (walk == true && onBlock == true)
            {
                return animationWalk();
            } else 
            {
                return animationIdle();
            }
        }
    } else 
    {
        if (run == true && onBlock == true)
        {
            return spriteRun;
        } else 
        {
            if (walk == true && onBlock == true)
            {
                return spriteWalk;
            } else 
            {
                return spriteIdle;
            }
        }
    }
}

void Ennemy::followPlayer(Ninja &ninja)
{
    if (ninja.getHitBoxBody().getPosition().x > hitboxBody.getPosition().x + hitboxBody.getSize().x + 20)
    {
        setWalkY(Dir::Right);
        run = true;
        idle = false;
    } else 
    {
        if (ninja.getHitBoxBody().getPosition().x + ninja.getHitBoxBody().getSize().x < hitboxBody.getPosition().x - 20)
        {
            setWalkY(Dir::Left);
            run = true;
            idle = false;
        } else 
        {
            run = false;
            idle = true;
        }
    }
}

void Ennemy::walkFunction()
{
    if (getWalkY() == Dir::Right)
    {
        move(1 * CONST_ENNEMY_SPEED, 0);
    } else 
    {
        move(-1 * CONST_ENNEMY_SPEED, 0);
    }
}

void Ennemy::runFunction()
{
    if (getWalkY() == Dir::Right)
    {
        move(1 * CONST_ENNEMY_SPEED * 2, 0);
    } else 
    {
        move(-1 * CONST_ENNEMY_SPEED * 2, 0);
    }
}

void Ennemy::gravityFunction()
{
    if (onBlock == false)
    {
        move(0, CONST_GRAVITY * getGravity());
        setGravity(getGravity() + 0.1);
    }
}

void Ennemy::botMove()
{
    if (onBlock == true)
    {
        if (run == true)
        {
            runFunction();
        } else 
        {
            if (walk == true)
            {
                walkFunction();
            }
        }
    } else 
    {
        gravityFunction();
    }
}

void Ennemy::mainMove(Ninja &ninja)
{
    followPlayer(ninja);
    botMove();
}
