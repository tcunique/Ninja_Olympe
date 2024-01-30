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

    backgroundSprite2.setScale(1, 1); // Aggrandi l'image de fond pour qu'elle soit cohérente avec la taille de la fenetre
    backgroundSprite2.setTexture(backgroundTexture);
    backgroundSprite2.setPosition(0, -1650);
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

void Interface::loadMusicEnd()
{
    if (!music.openFromFile("music/End.ogg"))
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
            std::cout << "state " << menu.getClick() << std::endl;
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

void Interface::DeathMenu()
{
    menudeath.draw(interface);

    if (menudeath.checkMouseOnPlayButtonDead(interface))
    {
        // std::cout << "State " << menudeath.getClick() << std::endl;
        // std::cout << "Play" << std::endl;

        // Résurection des personnages
        p1.setLife(CONST_PLAYER_HEALTH);
        ennemy.setLife(CONST_ENNEMY_HP);

        // p1.setLife(CONST_PLAYER_HEALTH);
        p1.setAlive(true);
        ennemy.setAlive(true);

        p1.getHealthBar().setHealth(CONST_PLAYER_HEALTH);

        healthBar ennemy_healthbar = ennemy.getHealthBar();
        ennemy.getHealthBar().setHealth(-ennemy_healthbar.getHealth()+CONST_ENNEMY_HP);

        music.play();
        music.setLoop(true);
    } 

    if(menudeath.checkMouseOnQuitButtonDead(interface))
    {
        std::cout << "Quit" << std::endl;
        interface.close();
    }
}

void Interface::backgroundLoad()
{
    // Affichage du fond
    interface.draw(backgroundSprite);
    interface.draw(backgroundSprite2); 
}

void Interface::backgroundLoadEnd()
{
    // Affichage du fond
    if (!backgroundTexture.loadFromFile("sprite/background/Background.png"))
    {
        std::cout << "Erreur lors du chargement de l'image du fond" << std::endl;
    }
    backgroundTexture.setSmooth(true);
    backgroundSprite.setScale(3.5, 3.5); // Aggrandi l'image de fond pour qu'elle soit cohérente avec la taille de la fenetre
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, -1650);
}

void Interface::EndWindow()
{
    //Music
    loadMusicEnd();
    music.play();
    music.setLoop(true);

    // Remet le perso en place
    p1.move(-200, 0);
    ennemy.move(3000, 0);
    p1.getText().move(100, 0); // oN remet en place le texte
    clock.restart();
    while(interface.isOpen())
    {
        // Boucle d'évènements
        while (interface.pollEvent(event))
        {
            input.InputHandler(event, interface, menudeath);
        }
        // Mettre la couleur de fond à noir
        clear();

        backgroundLoadEnd();

        // Map
        loadMap();

        // COllision de la map
        world.presenceOnGround(p1);

        interface.setView(p1.getView());

        // Affichage du fond
        interface.draw(backgroundSprite);

        // Person on the scene
        checkAliveNinja();
        sf::Sprite animEnnemy = ennemy.animation();
        interface.draw(animEnnemy);

        Dialogue_end();

        display();
    }
}

Menu &Interface::getMenu()
{
    return menu;
}

Menu &Interface::getMenuDeath()
{
    return menudeath;
}

void Interface::Dialogue_end()
{
    if (dialogue_end[0] == false)
    {
        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asSeconds() < 3)
        {
            p1.getText().TextDisplay(interface, "You : Where am I ?");
        } else 
        {
            dialogue_end[0] = true;
        }
    }

    if (dialogue_end[0] == true && dialogue_end[1] == false)
    {
        if (p1.getPos().x >= 2700)
        {
            if (wait == false)
            {
                clock.restart();
                wait = true;
            } else 
            {
                sf::Time elapsed = clock.getElapsedTime();
                if (elapsed.asSeconds() < 3)
                {
                    p1.getText().TextDisplay(interface, "Stranger : you are dreaming.");
                } else 
                {
                    dialogue_end[1] = true;
                    clock.restart();
                    wait = false;
                }
            }
        }
    }

    if (dialogue_end[1] == true && dialogue_end[2] == false)
    {
        if (p1.getPos().x >= 2700)
        {
            if (wait == false)
            {
                clock.restart();
                wait = true;
            } else 
            {
                sf::Time elapsed = clock.getElapsedTime();
                if (elapsed.asSeconds() < 3)
                {
                    p1.getText().TextDisplay(interface, "You : Wait ... What ?");
                } else 
                {
                    dialogue_end[2] = true;
                    clock.restart();
                    wait = false;
                }
            }
        }
    }

    if (dialogue_end[2] == true && dialogue_end[3] == false)
    {
        if (p1.getPos().x >= 2700)
        {
            if (wait == false)
            {
                clock.restart();
                wait = true;
            } else 
            {
                sf::Time elapsed = clock.getElapsedTime();
                if (elapsed.asSeconds() < 3)
                {
                    p1.getText().TextDisplay(interface, "Stranger : You are trapped in your project");
                } else 
                {
                    dialogue_end[3] = true;
                    clock.restart();
                    wait = false;
                }
            }
        }
    }

    if (dialogue_end[3] == true && dialogue_end[4] == false)
    {
        if (p1.getPos().x >= 2700)
        {
            if (wait == false)
            {
                clock.restart();
                wait = true;
            } else 
            {
                sf::Time elapsed = clock.getElapsedTime();
                if (elapsed.asSeconds() < 3)
                {
                    p1.getText().TextDisplay(interface, "Stranger : that took you way too much time.");
                } else 
                {
                    dialogue_end[4] = true;
                    clock.restart();
                    wait = false;
                }
            }
        }
    }

    if (dialogue_end[4] == true && dialogue_end[5] == false)
    {
        if (p1.getPos().x >= 2700)
        {
            if (wait == false)
            {
                clock.restart();
                wait = true;
            } else 
            {
                sf::Time elapsed = clock.getElapsedTime();
                if (elapsed.asSeconds() < 3)
                {
                    p1.getText().TextDisplay(interface, "Stranger : Wake Up !! Click Echap Fast !");
                } else 
                {
                    dialogue_end[5] = true;
                    clock.restart();
                    wait = false;
                }
            }
        }
    }
}

void Interface::Play()
{
    loadMusicGame();
    music.play();
    music.setLoop(true);

    p1.move(0, 600);

    // Pour le dialogue
    clock.restart();
    while (interface.isOpen())
    {
        // Boucle d'évènements
        while (interface.pollEvent(event))
        {
            input.InputHandler(event, interface, menudeath);
        }
        // Mettre la couleur de fond à noir
        clear();

        // Affichage du fond
        backgroundLoad();

        // Create Map
        loadMap();

        interface.setView(p1.getView());

        
        // Vérification de présence
        // bloc.presence(p1);
        world.presenceOnGround(p1);
        world.presenceOnGroundBot(ennemy);
        if(world.collisionHouse(p1, interface, event))
        {
            music.stop();
            break;
        }

        // Affichage de la barre de vie
        p1.displayHealthBar(interface);
        p1.moveMenu(interface, menudeath);
        ennemy.displayHealthBar(p1, interface);

        // DeathMenu();

        // Vérification des inputs et de la vie, et fait les animations
        checkAlive();

        // Dialogue
        Dialogue("You : I Have to get rid of him.");

        // Affichage de la fenêtre
        display();
        // interface.setView(interface.getDefaultView());
    }
}

void Interface::Dialogue(std::string Text)
{
    sf::Time elapsed = clock.getElapsedTime();
    if (elapsed.asSeconds() < 3)
    {
        p1.getText().TextDisplay(interface, Text);
    }
}

void Interface::Launch()
{
    MenuWindow();
    Play();
    EndWindow();
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
        DeathMenu();
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
    checkAliveSamurai();
    checkAliveNinja();
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