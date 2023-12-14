#include "../header/map.hpp"
#include <SFML/Graphics.hpp>

Map::Map()
{
}

Map::~Map()
{
}

std::vector<block *> Map::getMonde()
{
    return monde;
}

void Map::createMap() {

    //Sol
    monde.push_back(new block(0, 900, 2, 2, "sprite/Herbe.png"));
    monde.push_back(new block(184, 900, 2, 2, "sprite/Herbe.png"));
    monde.push_back(new block(368, 900, 2, 2, "sprite/Herbe.png"));
    monde.push_back(new block(552, 900, 2, 2, "sprite/Herbe.png"));
    monde.push_back(new block(736, 900, 2, 2, "sprite/Herbe.png"));
    monde.push_back(new block(920, 900, 2, 2, "sprite/Herbe.png"));
    monde.push_back(new block(1104, 900, 2, 2, "sprite/Herbe.png"));
    monde.push_back(new block(1288, 900, 2, 2, "sprite/Herbe.png"));
    monde.push_back(new block(1472, 900, 2, 2, "sprite/Herbe.png"));

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