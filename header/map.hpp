#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "block.hpp"


using namespace sf;

class Map
{
    private :
        std::vector<block *> monde; 

    public :
        Map();
        ~Map();

        void createMap();

        std::vector<block *> getMonde();
};