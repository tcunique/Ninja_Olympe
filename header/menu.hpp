#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu 
{
    public:
        Menu(int width, int height);
        Menu(int width, int height, bool death);
        ~Menu();

        // Load the sprite
        void SpritePlayButtonLoad(int width, int height);
        void SpriteQuitButtonLoad(int width, int height);
        void LaunchButtonPlay(int width, int height);
        void LaunchButtonQuit(int width, int height);

        // Get
        sf::Sprite getPlayButton();
        sf::Sprite getQuitButton();
        bool getClick();

        // set 
        void setClick(bool click);
        void setPosition(sf::Vector2f position);

        // Draw
        void draw(sf::RenderWindow &window);

        // Check if the mouse is on the button
        bool checkMouseOnPlayButton(sf::RenderWindow &window);
        bool checkMouseOnQuitButton(sf::RenderWindow &window);

        void LoadFont(std::string path);

    private:
        // sprite des boutons
        sf::Sprite playButton;
        sf::Texture playButtonTexture;
        sf::RectangleShape playButtonShape;

        sf::Sprite quitButton;
        sf::Texture quitButtonTexture;
        sf::RectangleShape quitButtonShape;

        // Police de caractère
        sf::Font font;
        sf::Text playText;
        sf::Text quitText;

        // Fond d'écran
        sf::RectangleShape background;

        // bool du clique de la sourie
        bool click;
        bool deathconstructor;
};