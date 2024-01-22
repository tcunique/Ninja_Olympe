#include "../header/item.hpp"

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
    itemSprite.setScale(0.1, 0.1);
}