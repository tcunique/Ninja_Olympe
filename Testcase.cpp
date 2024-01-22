#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "header/window.hpp"
#include "header/ninja.hpp"
#include "./header/data.hpp"
#include "./header/block.hpp"
#include "./header/ennemy.hpp"
#include "./header/samurai.hpp"
#include "./header/input.hpp"
#include "./header/menu.hpp"

// #                          A LIRE AVANT DE LANCER LE TEST :                             #
// ##############################        TESTS       #######################################
// # Les mondes vont être généré un par un, les tests ont pour but de tester chaque        #
// # composant du jeu.                                                                     #
// # Pour passer au prochain TEST il vous suffit d'appuyer sur ECHAP, ce qui arrêtera      #
// # le jeu et vous permettra de passer au prochain test.                                  #
// #########################################################################################

TEST_SUITE("Player")
{
    TEST_CASE("Gravity Test and Animation")
    {
        Interface interface;
        while (interface.isOpen())
        {
            // Boucle d'évènements
            while(interface.getInterface().pollEvent(interface.getEvent()))
            {
                interface.getInput().InputHandler(interface.getEvent(), interface.getInterface());
            }
            interface.clear();

            interface.checkAliveNinja();
            interface.getMap().presenceOnGround(interface.getNinja());

            interface.loadMap();

            // Mets la vue sur le joueur
            interface.getInterface().setView(interface.getNinja().getView());
            
            interface.display();
        }
    }
}

TEST_SUITE("Window")
{    
    TEST_CASE("Load Map")
    {
        // LA MAP EST PLUS GRANDE EXPRES POUR QUE LE JOUEUR PUISSE ALLER PLUS LOIN
        Interface interface;
        while (interface.isOpen())
        {
            // Boucle d'évènements
            while(interface.getInterface().pollEvent(interface.getEvent()))
            {
                interface.getInput().InputHandler(interface.getEvent(), interface.getInterface());
            }

            interface.clear();

            interface.getInterface().draw(interface.getBackgroundSprite());
            interface.loadMap();

            interface.display();
        }
    }
    TEST_CASE("Menu Window")
    {
        Interface interface; 
        interface.MenuWindow();
    }

    TEST_CASE("Play Window")
    {
        Interface interface;
        interface.Play();
    }
}
