#include "../header/ninja.hpp"
#include "../header/data.hpp"

Ninja::Ninja()
{
    // Gère les animations
    idle_count = 1;
    walk.x = 1;
    walk.y = Dir::Right;
    jump_count = 1;
    walk_count = 7;
    run_count = 1;
    attack_1_count = 1;

    // Gère les fps
    name = CONST_PLAYER_NAME;

    // Gère les inputs
    idle = true;
    jump = false;
    walk_state = false;
    run_state = false;
    attack_1_state = false;

    // Gère les sprites
    spriteLaunch();

    //hit box
    hitbox.setPosition(CONST_POSITION_X + 5, CONST_POSITION_Y + 100);
    hitbox.setSize(sf::Vector2f(CONST_HITBOX_WIDTH, CONST_HITBOX_HEIGHT));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(1);
    hitbox.setOutlineColor(sf::Color::Red);

    // hitbox arm
    arm.setPosition(CONST_POSITION_X+15, CONST_POSITION_Y+45);
    arm.setSize(sf::Vector2f(CONST_PLAYER_ARM_WIDTH, CONST_PLAYER_ARM_HEIGHT));
    arm.setFillColor(sf::Color::Transparent);
    arm.setOutlineThickness(1);
    arm.setOutlineColor(sf::Color::Red);

    // hitbox body
    hitboxBody.setPosition(CONST_POSITION_X+5, CONST_POSITION_Y+10);
    hitboxBody.setSize(sf::Vector2f(40, 150));
    hitboxBody.setFillColor(sf::Color::Transparent);
    hitboxBody.setOutlineThickness(1);
    hitboxBody.setOutlineColor(sf::Color::Red);
}

Ninja::~Ninja()
{
}

bool Ninja::getIdle()
{
    return idle;
}

sf::RectangleShape Ninja::getHitbox()
{
    return hitbox;
}

unsigned int Ninja::getJumpCount()
{
    return jump_count;
}

bool Ninja::getJump()
{
    return jump;
}

bool Ninja::getRun()
{
    return run_state;
}

bool Ninja::getAttack_1()
{
    return attack_1_state;
}

void Ninja::setIdle(bool resp)
{
    idle = resp;
}

void Ninja::setJump(bool resp)
{
    jump = resp;
}

void Ninja::setJumpCount(unsigned int count)
{
    jump_count = count;
}

void Ninja::setRun(bool resp)
{
    run_state = resp;
}

void Ninja::setAttack_1(bool resp)
{
    attack_1_state = resp;
}

void Ninja::spriteWalkL()
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

void Ninja::spriteIdleL()
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

void Ninja::spriteJumpL()
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

void Ninja::spriteRunL()
{
    // Donne le sprite du perso en respiration
    if (!textureRun.loadFromFile("sprite/Run.png"))
    {
        std::cout << "Erreur lors du chargement de la texture du personnage" << std::endl;
    }
    textureRun.setSmooth(true);

    spriteRun.setTexture(textureRun);
    spriteRun.setScale(CONST_PLAYER_SIZE, CONST_PLAYER_SIZE); // Aggrandi l'image
    spriteRun.setTextureRect(sf::IntRect(run_count * 128, 0, 128, 128)); // Rect la première image
}

void Ninja::spriteAttack_1L()
{
    // Donne le sprite du perso en respiration
    if (!textureAttack_1.loadFromFile("sprite/Attack_1.png"))
    {
        std::cout << "Erreur lors du chargement de la texture du personnage" << std::endl;
    }
    textureAttack_1.setSmooth(true);

    spriteAttack_1.setTexture(textureAttack_1);
    spriteAttack_1.setScale(CONST_PLAYER_SIZE, CONST_PLAYER_SIZE); // Aggrandi l'image
    spriteAttack_1.setTextureRect(sf::IntRect(attack_1_count * 128, 0, 128, 128)); // Rect la première image
}

void Ninja::spriteLaunch()
{
    spriteIdleL();
    spriteWalkL();
    spriteJumpL();
    spriteRunL();
    spriteAttack_1L();
}

sf::Sprite Ninja::animationJump()
{
    if (jump_count * 128 >= textureJump.getSize().x)
    {
        jump_count = 9;
    }
    if (walk.y == Dir::Right)
    {
        spriteJump.setTextureRect(sf::IntRect(jump_count * 128, 0, 128, 128));
    } else 
    {
        spriteJump.setTextureRect(sf::IntRect(jump_count * 128, 0, -128, 128));
    }
    jump_count++;
    fpsCount = 0;
    return spriteJump;
}

sf::Sprite Ninja::animationWalk()
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

sf::Sprite Ninja::animationIdle()
{
//Respiration
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
    idle_count++;
    return spriteIdle;
}

sf::Sprite Ninja::animationRun()
{
    if (run_count * 128 >= textureRun.getSize().x)
    {
        run_count = 1;
    }
    if (walk.y == Dir::Right)
    {
        spriteRun.setTextureRect(sf::IntRect(run_count * 128, 0, 128, 128));
    } else 
    {
        spriteRun.setTextureRect(sf::IntRect(run_count * 128, 0, -128, 128));
    }
    run_count++;
    fpsCount = 0;
    return spriteRun;
}

sf::Sprite Ninja::animationAttack_1()
{
    if (attack_1_count * 128 >= textureAttack_1.getSize().x)
    {
        attack_1_count = 1;
        attack_1_state = false;
        setArmHitboxLength(sf::Vector2f(CONST_PLAYER_ARM_WIDTH, CONST_PLAYER_ARM_HEIGHT));
        setArmHitboxPosX(x + 15);
    } else 
    {
        if (walk.y == Dir::Right)
        {
            spriteAttack_1.setTextureRect(sf::IntRect(attack_1_count * 128, 0, 128, 128));
        } else 
        {
            spriteAttack_1.setTextureRect(sf::IntRect(attack_1_count * 128, 0, -128, 128));
        }
        attack_1_count++;
        fpsCount = 0;
    }
    return spriteAttack_1;
}


sf::Sprite Ninja::animation()
{
    if(fpsCount < switchFps)
    {
        fpsCount += 1;
    } 

    // Permet de fixer un fps et que l'image de ne se charge pas tout le temps
    if (fpsCount >= switchFps)
    {
        if (attack_1_state == true)
        {
            return animationAttack_1();
        }
        // Vérifie s'il y a un input ou non, si non on fait l'anim de la respiration
        if (jump == true || (jump == false && onBlock == false))
        {
            return animationJump();
        } else if (idle == false && jump == false && run_state == true)
        {
            return animationRun();
        } else if (idle == false && jump == false && run_state == false)
        {
            return animationWalk();
        } else 
        {
            return animationIdle();
        }
    } else 
    {
        if (attack_1_state == true)
        {
            return spriteAttack_1;
        }
        if (jump == true || (jump == false && onBlock == false))
        {
            return spriteJump;
        } else if (idle == false && jump == false && run_state == true)
        {
            return spriteRun;
        } else if (idle == false && jump == false && run_state == false)
        {
            return spriteWalk;
        } else 
        {
            return spriteIdle;
        }
    }
}

std::string Ninja::getName()
{
    return name;
}