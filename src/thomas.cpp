#include "../header/thomas.hpp"
#include "../header/data.hpp"

Thomas::Thomas()
{
    idle_count = 1;
    walk.x = 1;
    walk.y = Dir::Right;
    jump_count = 1;
    walk_count = 7;

    name = CONST_PLAYER_NAME;
    fpsCount = 0;
    switchFps = 5;
    fpsSpeed = 100;

    idle = true;
    jump = false;

    spriteLaunch();

    //hit box
    hitbox.setPosition(CONST_POSITION_X + 5, CONST_POSITION_Y + 100);
    hitbox.setSize(sf::Vector2f(CONST_HITBOX_WIDTH, CONST_HITBOX_HEIGHT));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(1);
    hitbox.setOutlineColor(sf::Color::Red);
}

Thomas::~Thomas()
{
}

bool Thomas::getIdle()
{
    return idle;
}

sf::RectangleShape Thomas::getHitbox()
{
    return hitbox;
}

void Thomas::setIdle(bool resp)
{
    idle = resp;
}

void Thomas::setJump(bool resp)
{
    jump = resp;
}

void Thomas::spriteWalkL()
{
    // Donne le sprite du perso en mouvement
    if(!textureWalk.loadFromFile("sprite/Walk.png"))
    {
        std::cout << "Erreur lors du chargement de la texture du personnage" << std::endl;
    }
    textureWalk.setSmooth(true); // Permet d'enlever les pixels un peu baveux

    spriteWalk.setTexture(textureWalk);
    spriteWalk.setScale(CONST_PLAYER_SIZE, CONST_PLAYER_SIZE); // Aggrandi l'image
    spriteWalk.setTextureRect(sf::IntRect(walk.x * 128, walk.y * 128, 128, 128)); // Rect la premirèe image
}

void Thomas::spriteIdleL()
{
    // Donne le sprite du perso en respiration
    if (!textureIdle.loadFromFile("sprite/Idle.png"))
    {
        std::cout << "Erreur lors du chargement de la texture du personnage" << std::endl;
    }
    textureIdle.setSmooth(true);

    spriteIdle.setTexture(textureIdle);
    spriteIdle.setScale(CONST_PLAYER_SIZE, CONST_PLAYER_SIZE); // Aggrandi l'image
    spriteIdle.setTextureRect(sf::IntRect(idle_count * 128, 0, 128, 128)); // Rect la première image
}

void Thomas::spriteJumpL()
{
    // Donne le sprite du perso en respiration
    if (!textureJump.loadFromFile("sprite/Jump.png"))
    {
        std::cout << "Erreur lors du chargement de la texture du personnage" << std::endl;
    }
    textureJump.setSmooth(true);

    spriteJump.setTexture(textureJump);
    spriteJump.setScale(CONST_PLAYER_SIZE, CONST_PLAYER_SIZE); // Aggrandi l'image
    spriteJump.setTextureRect(sf::IntRect(jump_count * 128, 0, 128, 128)); // Rect la première image
}

void Thomas::spriteLaunch()
{
    spriteIdleL();
    spriteWalkL();
    spriteJumpL();
}

sf::Sprite Thomas::animationJump()
{
    if (jump_count * 128 >= textureJump.getSize().x)
    {
        jump_count = 1;
    }
    if (walk.y == Dir::Right)
    {
        spriteJump.setTextureRect(sf::IntRect(jump_count * 128, 0, 128, 128));
    } else 
    {
        spriteJump.setTextureRect(sf::IntRect(jump_count * 128, 0, -128, 128));
    }
    fpsCount = 0;
    return spriteJump;
}

sf::Sprite Thomas::animationWalk()
{
    if (walk.y == Dir::Right)
    {
        walk.x++;
        if (walk.x * 128 >= textureWalk.getSize().x)
        {
            walk.x = 1;
        }
        spriteWalk.setTextureRect(sf::IntRect(walk.x * 128, walk.y * 128, 128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idle_count * 128, 0, 128, 128)); // Permet d'éviter d'avoir des conflits de sens
    } else 
    {
        walk_count--;
        if (walk_count * 128 <= 0)
        {
            walk_count = 7;
        }
        spriteWalk.setTextureRect(sf::IntRect(walk_count * 128, walk.y * 128, 128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idle_count * 128, 0, -128, 128)); // Pareil, empêche les conflits de sens
    }
    fpsCount = 0;
    return spriteWalk;
}

sf::Sprite Thomas::animationIdle()
{
//Respiration
    idle_count++;
    if (idle_count * 128 >= textureIdle.getSize().x)
    {
        idle_count = 1;
    }
    if (walk.y == Dir::Right)
    {
        spriteIdle.setTextureRect(sf::IntRect(idle_count * 128, 0, 128, 128));
    } else 
    {
        spriteIdle.setTextureRect(sf::IntRect(idle_count * 128, 0, -128, 128));
    }
    fpsCount = 0;
    return spriteIdle;
}
sf::Sprite Thomas::animation()
{
    if(fpsCount < switchFps)
    {
        fpsCount += 1;
    } 

    // Permet de fixer un fps et que l'image de ne se charge pas tout le temps
    if (fpsCount >= switchFps)
    {
        // Vérifie s'il y a un input ou non, si non on fait l'anim de la respiration
        if (jump == true)
        {
            return animationJump();
        } else if (idle == false && jump == false)
        {
            return animationWalk();
        } else 
        {
            return animationIdle();
        }
    } else 
    {
        if (jump == true)
        {
            return spriteJump;
        } else if (idle == false && jump == false)
        {
            return spriteWalk;
        } else 
        {
            return spriteIdle;
        }
    }
}

std::string Thomas::getName()
{
    return name;
}