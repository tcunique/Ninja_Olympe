#include "../header/window.hpp"
#include "../header/ninja.hpp"
#include "../header/data.hpp"
#include "../header/block.hpp"

Interface::Interface()
{
    interface.create(VideoMode(CONST_WIDTH, CONST_HEIGHT, 32), CONST_TITLE);
    interface.setVerticalSyncEnabled(true);
    world.createMap();

        // Chargement de l'image du fond
    if (!backgroundTexture.loadFromFile("sprite/Nature.png"))
    {
        std::cout << "Erreur lors du chargement de l'image du fond" << std::endl;
    }
    backgroundTexture.setSmooth(true);
    backgroundSprite.setScale(1, 1); // Aggrandi l'image de fond pour qu'elle soit cohérente avec la taille de la fenetre
    backgroundSprite.setTexture(backgroundTexture);
}

Interface::~Interface()
{
}

void Interface::clear()
{
    interface.clear(Color::Black);
}

void Interface::display()
{
    interface.display();
}

bool Interface::isOpen()
{
    return interface.isOpen();
}

void Interface::loadMusicIntro()
{
    if (!music.openFromFile("music/Intro.ogg"))
    {
        std::cout << "Erreur lors du chargement de la musique" << std::endl;
    }
}

void Interface::loadMusicGame()
{
    if (!music.openFromFile("music/Game.ogg"))
    {
        std::cout << "Erreur lors du chargement de la musique" << std::endl;
    }
}

void Interface::MenuWindow()
{
    loadMusicIntro();
    music.play();
    music.setLoop(true);
    while(interface.isOpen())
    {
        // Boucle d'évènements
        while (interface.pollEvent(event))
        {
            input.MouseInputHandler(menu);
        }
        // Mettre la couleur de fond à noir
        clear();

        // Affichage du fond
        interface.draw(backgroundSprite);

        // Affichage du menu
        menu.draw(interface);

        if (menu.checkMouseOnPlayButton(interface))
        {
            music.stop();
            return;
        }
        if (menu.checkMouseOnQuitButton(interface))
        {
            interface.close();
        }

        // Affichage de la fenêtre
        display();
    }
}

void Interface::Play()
{
    loadMusicGame();
    music.play();
    music.setLoop(true);
    while (interface.isOpen())
    {
        // Boucle d'évènements
        while (interface.pollEvent(event))
        {
            input.InputHandler(event, interface);
        }
        // Mettre la couleur de fond à noir
        clear();

        // Affichage du fond
        interface.draw(backgroundSprite);

        // Create Map
        loadMap();

        interface.setView(p1.getView());

        // Vérification des inputs et de la vie, et fait les animations
        checkAlive();
        
        // Vérification de présence
        // bloc.presence(p1);
        world.presenceOnGround(p1);
        world.presenceOnGroundBot(ennemy);

        // Affichage de la barre de vie
        p1.displayHealthBar(interface);
        ennemy.displayHealthBar(p1, interface);

        // Affichage de la fenêtre
        display();
        // interface.setView(interface.getDefaultView());
    }
}

void Interface::Launch()
{
    MenuWindow();
    Play();
}

void Interface::loadMap() {
    std::vector<block *> vect = world.getMonde();
    std::vector<block *> ground = world.getGround();

    for (std::size_t i = 0; i < vect.size(); i++) {
        interface.draw(vect[i]->getSprite());
    }

    for (std::size_t i = 0; i < ground.size(); i++) {
        interface.draw(ground[i]->getSprite());
    }

    // interface.draw(world.getHitbox());
    // interface.draw(world.getHitboxHouse());
}

void Interface::checkAliveNinja()
{
    // Vérification des inputs
    if (p1.checkAlive())
    {
        input.checkInput(p1, ennemy);       
        // Affichage de personnages
        sf::Sprite anim = p1.animation();
        interface.draw(anim); // Dessine un sprite
    } else 
    {
        interface.draw(p1.animationDeath());
    }
}

void Interface::checkAliveSamurai()
{
    // botMove
    if (ennemy.checkAlive())
    {
        ennemy.mainMove(p1, p1.getHealthBar());
        // Affichage de l'ennemi
        sf::Sprite animEnnemy = ennemy.animation();
        interface.draw(animEnnemy);
    } else 
    {
        interface.draw(ennemy.animationDeath());
        if (ennemy.getItem().getIsPickedUp() == false)
        {
            interface.draw(ennemy.getItem().getSprite());
            ennemy.getItem().collision(p1, interface, event);
        }
    }
}

void Interface::checkAlive()
{
    checkAliveNinja();
    checkAliveSamurai();
}

RenderWindow &Interface::getInterface()
{
    return interface;
}

Sprite &Interface::getBackgroundSprite()
{
    return backgroundSprite;
}

Ninja &Interface::getNinja()
{
    return p1;
}

samurai &Interface::getSamurai()
{
    return ennemy;
}

Map &Interface::getMap()
{
    return world;
}

Event &Interface::getEvent()
{
    return event;
}

Input &Interface::getInput()
{
    return input;
}