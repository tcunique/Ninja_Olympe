#include "../header/block.hpp"
#include "../header/data.hpp"

int JUMP_COUNT = 10/* some initial value */;

block::block()
{
    pos_x = 100;
    pos_y = 700;
    width = 300;
    height = 100;
    blockShape.setSize(sf::Vector2f(width, height));
    blockShape.setFillColor(sf::Color::White);
    blockShape.setPosition(pos_x, pos_y);
}

block::~block()
{
}

void block::setXpos(float x)
{
    this->pos_x = x;
}

void block::setYpos(float y)
{
    this->pos_y = y;
}

float block::getXpos()
{
    return pos_x;
}

float block::getYpos()
{
    return pos_y;
}

void block::setWidth(float w)
{
    this->width = w;
}

void block::setHeight(float h)
{
    this->height = h;
}

float block::getWidth()
{
    return width;
}

float block::getHeight()
{
    return height;
}

sf::RectangleShape block::getShape()
{
    return blockShape;
}


void block::presence(Thomas &thomas)
{
    sf::Vector2f p_pos = thomas.getHitbox().getPosition();
    if ((p_pos.y + CONST_HITBOX_HEIGHT) <= (pos_y + 10) && (p_pos.y + CONST_HITBOX_HEIGHT) >= (pos_y))
    {
        if (((p_pos.x >= pos_x) && (p_pos.x <= (pos_x + width))) || ((p_pos.x + CONST_HITBOX_WIDTH >= pos_x) && (p_pos.x + CONST_HITBOX_WIDTH <= (pos_x + width))))
        {
            thomas.setonBlock(true);
            std::cout << "on block" << std::endl;
        }
        else
        {
            thomas.setonBlock(false);
            std::cout << "not on block" << std::endl;
        }
    }
    else
    {
        thomas.setonBlock(false);
        // std::cout << thomas.getHitbox().getPosition().y << std::endl;
        // std::cout << pos_y << std::endl;
        std::cout << "not on block" << std::endl;
    }
}