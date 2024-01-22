#include "../header/item.hpp"
#include "../header/data.hpp"

Item::Item()
{
    SpriteLoad();
}

Item::~Item()
{
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
