#include "../header/item.hpp"
#include "../header/data.hpp"

Item::Item()
{
    SpriteLoad();
}

Item::~Item()
{
}

void Item::Input(sf::Event event, Ninja &Player)
{

    if (event.key.code == sf::Keyboard::E)
    {
        if (Player.getHitbox().getGlobalBounds().intersects(itemSprite.getGlobalBounds()))
        {
            std::cout << "You picked up the item" << std::endl;
            isPickedUp = true;
            Player.setPickUp(true);
        }
    }

}

void Item::SpriteLoad()
{
    if (!itemTexture.loadFromFile("sprite/item/old_paper.png"))
    {
        std::cout << "Error while loading item sprite" << std::endl;
    }
    itemSprite.setTexture(itemTexture);
    itemSprite.setPosition(CONST_ENNEMY_POSITION_X+60, CONST_ENNEMY_POSITION_Y+210);
    itemSprite.setScale(0.1, 0.1);
}

void Item::collision(Ninja &Player, sf::RenderWindow &window, sf::Event event)
{
    sf::RectangleShape p_pos = Player.getHitbox();
    if (p_pos.getGlobalBounds().intersects(itemSprite.getGlobalBounds()))
    {
        if (isPickedUp == false)
        {
            // std::cout << "collision" << std::endl;
            Player.getText().TextDisplay(window, "You found an old paper, click E to read it");
            Input(event, Player);
        }
    }
    else
    {
        std::cout << "no collision" << std::endl;
    }
}
