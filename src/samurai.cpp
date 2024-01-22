#include "../header/data.hpp"
#include "../header/samurai.hpp"

samurai::samurai()
{
    // Launch the function to load the sprite
    SpriteIdleLoad();
    SpriteWalkLoad();
    SpriteRunLoad();
    SpriteAttack1Load();
    SpriteHurtLoad();
    SpriteDeathLoad();

    // hitbox
    setHitbox();
    setHitboxBody();
    setHitBoxArm();

    // Hp
    hp = CONST_ENNEMY_HP;

    path = "music/Samurai/";
}

void samurai::setHitbox()
{
    hitbox.setPosition(x + 100, y + 200);
    hitbox.setSize(sf::Vector2f(CONST_HITBOX_WIDTH, CONST_HITBOX_HEIGHT));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(1);
    hitbox.setOutlineColor(sf::Color::Red);
}

void samurai::setHitboxBody()
{
    hitboxBody.setPosition(x + 110, y + 100);
    hitboxBody.setSize(sf::Vector2f(CONST_HITBOX_WIDTH, CONST_HITBOX_HEIGHT+ 100));
    hitboxBody.setFillColor(sf::Color::Transparent);
    hitboxBody.setOutlineThickness(1);
    hitboxBody.setOutlineColor(sf::Color::Red);
}

void samurai::setHitBoxArm()
{
    hitboxArm.setPosition(x + 120, y + 150);
    hitboxArm.setSize(sf::Vector2f(CONST_PLAYER_ARM_WIDTH, CONST_PLAYER_ARM_HEIGHT));
    hitboxArm.setFillColor(sf::Color::Transparent);
    hitboxArm.setOutlineThickness(1);
    hitboxArm.setOutlineColor(sf::Color::Red);
}

samurai::~samurai()
{
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

void samurai::SpriteWalkLoad()
{
    if (!textureWalk.loadFromFile("sprite/ennemySprite/SamuraiWalk.png"))
    {
        std::cout << "Error while loading samurai walk sprite" << std::endl;
    }
    spriteWalk.setTexture(textureWalk);
    spriteWalk.setPosition(x, y);
    spriteWalk.setScale(CONST_ENNEMY_SIZE, CONST_ENNEMY_SIZE);
    spriteWalk.setTextureRect(sf::IntRect(128, 0, 128, 128));
}

void samurai::SpriteRunLoad()
{
    if (!textureRun.loadFromFile("sprite/ennemySprite/SamuraiRun.png"))
    {
        std::cout << "Error while loading samurai run sprite" << std::endl;
    }
    spriteRun.setTexture(textureRun);
    spriteRun.setPosition(x, y);
    spriteRun.setScale(CONST_ENNEMY_SIZE, CONST_ENNEMY_SIZE);
    spriteRun.setTextureRect(sf::IntRect(128, 0, 128, 128));
}

void samurai::SpriteAttack1Load()
{
    if (!textureAttack_1.loadFromFile("sprite/ennemySprite/SamuraiAttack_1.png"))
    {
        std::cout << "Error while loading samurai attack sprite" << std::endl;
    }
    spriteAttack_1.setTexture(textureAttack_1);
    spriteAttack_1.setPosition(x, y);
    spriteAttack_1.setScale(CONST_ENNEMY_SIZE, CONST_ENNEMY_SIZE);
    spriteAttack_1.setTextureRect(sf::IntRect(128, 0, 128, 128));
}

void samurai::SpriteHurtLoad()
{
    if (!textureHurt.loadFromFile("sprite/ennemySprite/SamuraiHurt.png"))
    {
        std::cout << "Error while loading samurai hurt sprite" << std::endl;
    }
    spriteHurt.setTexture(textureHurt);
    spriteHurt.setPosition(x, y);
    spriteHurt.setScale(CONST_ENNEMY_SIZE, CONST_ENNEMY_SIZE);
    spriteHurt.setTextureRect(sf::IntRect(128, 0, 128, 128));
}

void samurai::SpriteDeathLoad()
{
    if (!textureDeath.loadFromFile("sprite/ennemySprite/SamuraiDead.png"))
    {
        std::cout << "Error while loading samurai death sprite" << std::endl;
    }
    spriteDeath.setTexture(textureDeath);
    spriteDeath.setPosition(x, y);
    spriteDeath.setScale(CONST_ENNEMY_SIZE, CONST_ENNEMY_SIZE);
    spriteDeath.setTextureRect(sf::IntRect(128, 0, 128, 128));
}