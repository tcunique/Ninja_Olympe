#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/input.hpp"
#include "../header/ninja.hpp"
#include "../header/block.hpp"
#include "../header/map.hpp"
#include "../header/healthbar.hpp"
#include "../header/samurai.hpp"
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

        // Ajout du personnage
        Ninja p1;
        block bloc;

        // Ajout de l'ennemi
        samurai ennemy;

        // Ajout de la texture et du sprite pour le fond d'écran
        Texture backgroundTexture;
        Sprite backgroundSprite;

        // Ajout de la map
        Map world;

        // Ajout de la barre de vie
        healthBar healthbar;

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

        // Affichage de la barre de vie
        void displayHealthBar();

        // Police de caractère
        void LoadFont();
        void setText(std::string str);
};
