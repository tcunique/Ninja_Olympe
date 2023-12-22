#include <iostream>
#include <SFML/Graphics.hpp>

class healthBar
{
    public:
        healthBar();
        ~healthBar();

        sf::Sprite getSpriteHealthBar();
        sf::Texture getTextureHealthBar();

        // Set
        void setSpriteHealthBar(sf::Sprite spriteHealthBar);
        void setTextureHealthBar(sf::Texture textureHealthBar);
        void setHealthBarPos(sf::Vector2f pos);

        void SpriteHealthBarL();

    private:
        sf::Sprite SpritehealthBar;
        sf::Texture textureHealthBar;
        float health;
};