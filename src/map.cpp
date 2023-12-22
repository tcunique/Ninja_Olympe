#include "../header/map.hpp"
#include "../header/data.hpp"
#include <SFML/Graphics.hpp>

Map::Map()
{
    numBlock = ground.size();

    // Pour la hitbox du sol
    hitboxWidth = CONST_GROUND_WIDTH;
    hitboxHeight = CONST_GROUND_HEIGHT;
    hitboxPosX = CONST_GROUND_POS_X;
    hitboxPosY = CONST_GROUND_POS_Y;

    // POur l'image du sol
    hitbox.setSize(sf::Vector2f(hitboxWidth, hitboxHeight));
    hitbox.setPosition(hitboxPosX, hitboxPosY);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(1);
    hitbox.setOutlineColor(sf::Color::Red);
}

Map::~Map()
{
}

sf::RectangleShape Map::getHitbox()
{
    return hitbox;
}

std::vector<block *> Map::getMonde()
{
    return monde;
}

std::vector<block *> Map::getGround()
{
    return ground;
}

float Map::getHitboxPosX()
{
    return hitboxPosX;
}

float Map::getHitboxPosY()
{
    return hitboxPosY;
}

int Map::getHitboxWidth()
{
    return hitboxWidth;
}

int Map::getHitboxHeight()
{
    return hitboxHeight;
}

void Map::createMap() {

    //ground
    ground.push_back(new block(0, 900, 2, 2, "sprite/Herbe.png"));
    ground.push_back(new block(184, 900, 2, 2, "sprite/Herbe.png"));
    ground.push_back(new block(368, 900, 2, 2, "sprite/Herbe.png"));
    ground.push_back(new block(552, 900, 2, 2, "sprite/Herbe.png"));
    ground.push_back(new block(736, 900, 2, 2, "sprite/Herbe.png"));
    ground.push_back(new block(920, 900, 2, 2, "sprite/Herbe.png"));
    ground.push_back(new block(1104, 900, 2, 2, "sprite/Herbe.png"));
    ground.push_back(new block(1288, 900, 2, 2, "sprite/Herbe.png"));
    ground.push_back(new block(1472, 900, 2, 2, "sprite/Herbe.png"));

    //Sous-sol
    monde.push_back(new block(-12, 960, 2, 2, "sprite/Terre.png"));
    monde.push_back(new block(171, 960, 2, 2, "sprite/Terre.png"));
    monde.push_back(new block(354, 960, 2, 2, "sprite/Terre.png"));
    monde.push_back(new block(537, 960, 2, 2, "sprite/Terre.png"));
    monde.push_back(new block(722, 960, 2, 2, "sprite/Terre.png"));
    monde.push_back(new block(907, 960, 2, 2, "sprite/Terre.png"));
    monde.push_back(new block(1090, 960, 2, 2, "sprite/Terre.png"));
    monde.push_back(new block(1275, 960, 2, 2, "sprite/Terre.png"));
    monde.push_back(new block(1459, 960, 2, 2, "sprite/Terre.png"));


    
    //Arbre et végétation
    monde.push_back(new block(60, 580, 2.5, 2.5, "sprite/Trees.png"));
    monde.push_back(new block(300, 868, 2, 2, "sprite/Champignon.png"));
}

void Map::presenceOnGround(Ninja &ninja)
{
    sf::Vector2f p_pos = ninja.getHitbox().getPosition();
    // std::cout << "y_p : " << p_pos.y + CONST_HITBOX_HEIGHT << std::endl;
    // std::cout << "hitboxY : " << hitboxPosY << std::endl;
    if (((p_pos.y + CONST_HITBOX_HEIGHT) <= (hitboxPosY + 6)) && ((p_pos.y + CONST_HITBOX_HEIGHT) >= (hitboxPosY - 6)))
    {
        // std::cout << "y true" << std::endl;
        if (((p_pos.x >= hitboxPosX) && (p_pos.x <= (hitboxPosX + hitboxWidth))) || ((p_pos.x + CONST_HITBOX_WIDTH >= hitboxPosX) && (p_pos.x + CONST_HITBOX_WIDTH <= (hitboxPosX + hitboxWidth))))
        {
            if (ninja.getJump() == false)
            {
                ninja.move(0, hitboxPosY - (p_pos.y + CONST_HITBOX_HEIGHT));
            }
            ninja.setonBlock(true);
            // std::cout << "on block" << std::endl;
            ninja.setJumpCount(1);
            ninja.setGravity(0);
        }
        else
        {
            ninja.setonBlock(false);
            // std::cout << "not on block" << std::endl;
        }
    }
    else
    {
        ninja.setonBlock(false);
        // std::cout << thomas.getHitbox().getPosition().y << std::endl;
        // std::cout << pos_y << std::endl;
        // std::cout << "not on block" << std::endl;
    }
}

void Map::presenceOnGroundBot(samurai &samurai)
{
    sf::Vector2f p_pos = samurai.getHitBox().getPosition();
    // std::cout << "y_p : " << p_pos.y + CONST_HITBOX_HEIGHT << std::endl;
    // std::cout << "hitboxY : " << hitboxPosY << std::endl;
    if (((p_pos.y + CONST_HITBOX_HEIGHT) <= (hitboxPosY + 6)) && ((p_pos.y + CONST_HITBOX_HEIGHT) >= (hitboxPosY - 6)))
    {
        // std::cout << "y true" << std::endl;
        if (((p_pos.x >= hitboxPosX) && (p_pos.x <= (hitboxPosX + hitboxWidth))) || ((p_pos.x + CONST_HITBOX_WIDTH >= hitboxPosX) && (p_pos.x + CONST_HITBOX_WIDTH <= (hitboxPosX + hitboxWidth))))
        {
            samurai.move(0, hitboxPosY - (p_pos.y + CONST_HITBOX_HEIGHT));
            samurai.setonBlock(true);
            // std::cout << "on block" << std::endl;
            samurai.setGravity(0);
        }
        else
        {
            samurai.setonBlock(false);
            // std::cout << "not on block" << std::endl;
        }
    }
    else
    {
        samurai.setonBlock(false);
    }
}