#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../header/menu.hpp"
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

        // Ajout du menu
        Menu menu {CONST_WIDTH, CONST_HEIGHT};

        // musique
        sf::Music music;

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

        // Menu
        void MenuWindow();

        // Play 
        void Play();

        //Background
        void loadMap();

        void checkAlive();
        void checkAliveNinja();
        void checkAliveSamurai();

        //Music
        void loadMusicIntro();
        void loadMusicGame();

        // get interface
        RenderWindow &getInterface();
        Sprite &getBackgroundSprite();
        Ninja &getNinja();
        samurai &getSamurai();
        Map &getMap();
        Event &getEvent();
        Input &getInput();
};
