#include "../header/ninja.hpp"
#include "../header/data.hpp"

Ninja::Ninja()
{
    // Gère les fps
    name = CONST_PLAYER_NAME;

    // Gère les sprites
    spriteLaunch();

    // set 
    setHitbox();
    setHitboxBody();
    setHitBoxArm();
}

Ninja::~Ninja()
{
}

void Ninja::setHitbox()
{
    hitbox.setPosition(x + 5, y + 100);
    hitbox.setSize(sf::Vector2f(CONST_HITBOX_WIDTH, CONST_HITBOX_HEIGHT));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(1);
    hitbox.setOutlineColor(sf::Color::Red);
}

void Ninja::setHitboxBody()
{
    hitboxBody.setPosition(x + 5, y + 10);
    hitboxBody.setSize(sf::Vector2f(40, 150));
    hitboxBody.setFillColor(sf::Color::Transparent);
    hitboxBody.setOutlineThickness(1);
    hitboxBody.setOutlineColor(sf::Color::Red);
}

void Ninja::setHitBoxArm()
{
    arm.setPosition(x + 15, y + 45);
    arm.setSize(sf::Vector2f(CONST_PLAYER_ARM_WIDTH, CONST_PLAYER_ARM_HEIGHT));
    arm.setFillColor(sf::Color::Transparent);
    arm.setOutlineThickness(1);
    arm.setOutlineColor(sf::Color::Red);
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
    spriteWalk.setTextureRect(sf::IntRect(walk_count.x * 128, 0, 128, 128)); // Rect la premirèe image
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

std::string Ninja::getName()
{
    return name;
}