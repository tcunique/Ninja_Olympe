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

void Interface::Launch()
{
    // Chargement de la police de caractère
    LoadFont();
    setText("Hello World");

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

        // Vérification des inputs
        input.checkInput(p1);

        // botMove
        ennemy.mainMove(p1);

        // Vérification de présence
        // bloc.presence(p1);
        world.presenceOnGround(p1);
        world.presenceOnGroundBot(ennemy);

        // Affichage de bloc
        // interface.draw(bloc.getShape());

        // Affichage de personnages
        sf::Sprite anim = p1.animation();
        interface.draw(anim); // Dessine un sprite

        // Affichage de l'ennemi
        sf::Sprite animEnnemy = ennemy.animation();
        interface.draw(animEnnemy);

        // Create Map
        loadMap();

        // Affichage du hitbox
        interface.draw(p1.getArmHitBox());
        interface.draw(p1.getHitBoxBody());

        interface.setView(p1.getView());

        // Affichage de la barre de vie
        displayHealthBar();

        // Affichage de la fenêtre
        display();
        // interface.setView(interface.getDefaultView());
    }
}

void Interface::LoadFont()
{
    if (!font.loadFromFile("res/poppins.ttf"))
    {
        std::cout << "Erreur lors du chargement de la police de caractère" << std::endl;
    }
}

void Interface::setText(std::string str)
{
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(24);
    text.setFillColor(Color::Cyan);
    text.setStyle(Text::Bold);
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
}

void Interface::displayHealthBar()
{
    // Affichage de la barre de vie
    sf::Vector2f playerPosition = p1.getPos();
    sf::Vector2f healthBarPosition = playerPosition + sf::Vector2f(-CONST_WIDTH/2, -CONST_HEIGHT/2);

    // Mettre la position de la barre de vie à la position du joueur
    healthbar.setHealthBarPos(healthBarPosition);

    // Création de la barre de vie
    sf::RectangleShape health(sf::Vector2f(175, 21));
    health.setFillColor(sf::Color::Red);
    health.setPosition(healthBarPosition + sf::Vector2f(50, 47));

    // Affichage de la barre de vie
    interface.draw(health);
    interface.draw(healthbar.getSpriteHealthBar());
    

}