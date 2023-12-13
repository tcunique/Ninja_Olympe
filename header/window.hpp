#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../header/input.hpp"
#include "../header/thomas.hpp"
#include "../header/block.hpp"
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

        Thomas p1;
        block bloc;

        int jump;

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

        // Police de caractère
        void LoadFont();
        void setText(std::string str);

        // Vérification des inputs
        void checkInput();
        void checkInputQ();
        void checkInputD();
        void checkInputSpace();
};
