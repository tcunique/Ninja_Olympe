#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/input.hpp"
#include "../header/ninja.hpp"
#include "../header/block.hpp"
#include "../header/map.hpp"
#include <vector>

using namespace sf;

class Interface
{
    private:
        RenderWindow interface;
        Event event;
        Font font;
        Text text;
        Input input;

        Ninja p1;
        block bloc;

        // Ajout de la texture et du sprite pour le fond d'écran
        Texture backgroundTexture;
        Sprite backgroundSprite;

        // Ajout de la map
        Map world;

    public:
        // Constructeur et destructeur de la fenêtre
        Interface();
        ~Interface();

        // Méthodes de la fenêtre
        void clear(); // Permet de vider la fenêtre
        void display(); // Permet d'afficher la fenêtre
        bool isOpen(); // Permet de savoir si la fenêtre est ouverte

        // Boucle principale
        void Launch();

        //Background
        void loadMap();

        // Police de caractère
        void LoadFont();
        void setText(std::string str);
};
