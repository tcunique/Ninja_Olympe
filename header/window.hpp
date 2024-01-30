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
#include "../header/data.hpp"
#include "../header/text.hpp"
#include "../header/option_menu.hpp"
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
        Sprite backgroundSprite2;
        // Ajout de la map
        Map world;

        // Ajout du menu
        Menu menu {CONST_WIDTH, CONST_HEIGHT};
        Menu menudeath {CONST_WIDTH, CONST_HEIGHT, true};

        // musique
        sf::Music music;

        // clock
        sf::Clock clock;

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
        void DeathMenu();
        void EndWindow();
        
        //Dialogue 
        void Dialogue(std::string Text);
        void Dialogue_end();
        // Play 
        void Play();

        //Background
        void loadMap();
        void backgroundLoad();
        void backgroundLoadEnd();

        void checkAlive();
        void checkAliveNinja();
        void checkAliveSamurai();

        //Music
        void loadMusicIntro();
        void loadMusicGame();
        void loadMusicEnd();

        // get interface
        RenderWindow &getInterface();
        Sprite &getBackgroundSprite();
        Ninja &getNinja();
        samurai &getSamurai();
        Map &getMap();
        Event &getEvent();
        Input &getInput();
        Menu &getMenu();
        Menu &getMenuDeath();

        std::vector<bool> dialogue_end = {false, false, false, false, false, false, false};

        bool wait = false;
};
