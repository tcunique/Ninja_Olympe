#include "../header/data.hpp"
#include "../header/healthbar.hpp"

healthBar::healthBar()
{
    SpriteHealthBarL();
    health = CONST_PLAYER_HEALTH;
}

healthBar::~healthBar()
{
}

void healthBar::setHealthBarPos(sf::Vector2f pos)
{
    SpritehealthBar.setPosition(pos);
}

sf::Sprite healthBar::getSpriteHealthBar()
{
    return SpritehealthBar;
}

sf::Texture healthBar::getTextureHealthBar()
{
    return textureHealthBar;
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
    SpritehealthBar.setScale(2, 2);
    SpritehealthBar.setPosition(0, 0);
}