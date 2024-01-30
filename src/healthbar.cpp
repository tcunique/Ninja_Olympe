#include "../header/data.hpp"
#include "../header/healthbar.hpp"

healthBar::healthBar(bool isPlayer)
{
    SpriteHealthBarL();
    convexHealthBarPlayerL();
    if (isPlayer)
    {
        health = CONST_PLAYER_HEALTH;
    } else 
    {
        health = CONST_ENNEMY_HP;
    }
}

healthBar::~healthBar()
{
}

void healthBar::setHealthBarPos(sf::Vector2f pos)
{
    SpritehealthBar.setPosition(pos);
    healthBarShape.setPosition(pos + sf::Vector2f(60, 58));
}

sf::Sprite healthBar::getSpriteHealthBar()
{
    return SpritehealthBar;
}

sf::Texture healthBar::getTextureHealthBar()
{
    return textureHealthBar;
}

sf::ConvexShape healthBar::getHealthBarShape()
{
    return healthBarShape;
}

void healthBar::setSpriteHealthBar(sf::Sprite spriteHealthBar)
{
    SpritehealthBar = spriteHealthBar;
}

void healthBar::setTextureHealthBar(sf::Texture textureHealthBar)
{
    this->textureHealthBar = textureHealthBar;
}

void healthBar::SpriteHealthBarL()
{
    if (!textureHealthBar.loadFromFile("sprite/healthbar.png"))
    {
        std::cout << "Erreur lors du chargement de la texture healthBar.png" << std::endl;
    }
    textureHealthBar.setSmooth(true);
    SpritehealthBar.setTexture(textureHealthBar);
    SpritehealthBar.setScale(2.5, 2.5);
    SpritehealthBar.setPosition(0, 0);
}

void healthBar::convexHealthBarPlayerL()
{
    healthBarShape.setPointCount(7);
    healthBarShape.setPoint(0, sf::Vector2f(0, 0));
    healthBarShape.setPoint(1, sf::Vector2f(200, 0));
    healthBarShape.setPoint(2, sf::Vector2f(210, 7));
    healthBarShape.setPoint(3, sf::Vector2f(220, 14));
    healthBarShape.setPoint(4, sf::Vector2f(210, 21));
    healthBarShape.setPoint(5, sf::Vector2f(200, 28));
    healthBarShape.setPoint(6, sf::Vector2f(0, 28));
    healthBarShape.setFillColor(sf::Color::Green);
}

void healthBar::convexHealthBarEnnemyL()
{
    healthBarShape.setPointCount(7);
    healthBarShape.setPoint(0, sf::Vector2f(500, 0));
    healthBarShape.setPoint(1, sf::Vector2f(700, 0));
    healthBarShape.setPoint(2, sf::Vector2f(710, 7));
    healthBarShape.setPoint(3, sf::Vector2f(720, 14));
    healthBarShape.setPoint(4, sf::Vector2f(710, 21));
    healthBarShape.setPoint(5, sf::Vector2f(700, 28));
    healthBarShape.setPoint(6, sf::Vector2f(500, 28));
    healthBarShape.setFillColor(sf::Color::Green);
}

void healthBar::updateColor()
{
    if (health > CONST_PLAYER_HEALTH / 2)
    {
        healthBarShape.setFillColor(sf::Color::Green);
    }
    else if (health > CONST_PLAYER_HEALTH / 4)
    {
        healthBarShape.setFillColor(sf::Color::Yellow);
    }
    else
    {
        healthBarShape.setFillColor(sf::Color::Red);
    }
}

void healthBar::setHealth(float health)
{
    this->health += health;
    if (this->health <= 0)
    {
        this->health = 0;
    }
    updateColor();
    healthBarShape.setPoint(1, sf::Vector2f(200 * (this->health / CONST_PLAYER_HEALTH), 0));
    healthBarShape.setPoint(2, sf::Vector2f(210 * (this->health / CONST_PLAYER_HEALTH), 7));
    healthBarShape.setPoint(3, sf::Vector2f(220 * (this->health / CONST_PLAYER_HEALTH), 14));
    healthBarShape.setPoint(4, sf::Vector2f(210 * (this->health / CONST_PLAYER_HEALTH), 21));
    healthBarShape.setPoint(5, sf::Vector2f(200 * (this->health / CONST_PLAYER_HEALTH), 28));
}

float healthBar::getHealth()
{
    return health;
} 