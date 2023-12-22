#include "../header/data.hpp"
#include "../header/samurai.hpp"

samurai::samurai()
{
    idleCount = 1;
    walkCount.x = 1;
    walkCount.y = LEFT;
    idle = true;
    walk = false;

    // Launch the function to load the sprite
    SpriteIdleLoad();

    // Animation speed
    fpsCount = 0;
    switchFps = 4;
    fpsSpeed = 100;
}

samurai::~samurai()
{
}

sf::Sprite samurai::getSpriteIdle()
{
    return spriteIdle;
}

sf::Texture samurai::getTextureIdle()
{
    return textureIdle;
}

void samurai::setSpriteIdle(sf::Sprite spriteIdle)
{
    this->spriteIdle = spriteIdle;
}

void samurai::setTextureIdle(sf::Texture textureIdle)
{
    this->textureIdle = textureIdle;
}

void samurai::SpriteIdleLoad()
{
    if (!textureIdle.loadFromFile("sprite/ennemySprite/SamuraiIdle.png"))
    {
        std::cout << "Error while loading samurai idle sprite" << std::endl;
    }
    spriteIdle.setTexture(textureIdle);
    spriteIdle.setPosition(x, y);
    spriteIdle.setScale(CONST_ENNEMY_SIZE, CONST_ENNEMY_SIZE);
}

sf::Sprite samurai::animationIdle()
{
    if (idleCount * 128 >= textureIdle.getSize().x)
    {
        idleCount = 1;
    }
    if (walkCount.y == Dir::RIGHT)
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

sf::Sprite samurai::animationWalk()
{
    if (walkCount.x * 128 >= textureWalk.getSize().x)
    {
        walkCount.x = 1;
    }
    if (walkCount.y == Dir::RIGHT)
    {
        spriteWalk.setTextureRect(sf::IntRect(walkCount.x * 128, walkCount.y * 128, 128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idleCount * 128, 0, 128, 128)); // Permet d'éviter d'avoir des conflits de sens
    } else 
    {
        spriteWalk.setTextureRect(sf::IntRect(walkCount.x * 128, walkCount.y * 128, 128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idleCount * 128, 0, -128, 128)); // Pareil, empêche les conflits de sens
    }

    fpsCount = 0;
    walkCount.x++;
    return spriteWalk;
}

sf::Sprite samurai::animation()
{
    if(fpsCount < switchFps)
    {
        fpsCount += 1;
    } 

    // Permet de fixer un fps et que l'image de ne se charge pas tout le temps
    if (fpsCount >= switchFps)
    {
        if (walk == true)
        {
            return animationWalk();
        } else 
        {
            return animationIdle();
        }
    } else 
    {
        if (walk == true)
        {
            return spriteWalk;
        } else 
        {
            return spriteIdle;
        }
    }
}
