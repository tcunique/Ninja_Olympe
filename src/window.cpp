#include "../header/window.hpp"
#include "../header/ninja.hpp"
#include "../header/data.hpp"
#include "../header/block.hpp"

Interface::Interface()
{
    interface.create(VideoMode(CONST_WIDTH, CONST_HEIGHT, 32), CONST_TITLE);
    interface.setVerticalSyncEnabled(true);
    world.createMap();
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

        // Chargement de l'image du fond
        if (!backgroundTexture.loadFromFile("sprite/Nature.png"))
        {
            std::cout << "Erreur lors du chargement de l'image du fond" << std::endl;
        }
        backgroundTexture.setSmooth(true);
        backgroundSprite.setScale(1, 1); // Aggrandi l'image de fond pour qu'elle soit cohérente avec la taille de la fenetre
        backgroundSprite.setTexture(backgroundTexture);

        // Affichage du fond
        interface.draw(backgroundSprite);

        // Vérification des inputs
        input.checkInput(p1);

        // Create Map
        loadMap();

        // Vérification de présence
        // bloc.presence(p1);
        world.presenceOnGround(p1);

        // Affichage du texte, ou de tout autre chose
        interface.draw(text);

        // Affichage de bloc
        // interface.draw(bloc.getShape());

        // Affichage de personnages
        // interface.draw(person.getShape()); // Dessine un cercle
        sf::Sprite anim = p1.animation();
        interface.draw(anim); // Dessine un sprite

        // Affichage du hitbox
        interface.draw(p1.getHitbox());

        // Affichage de la fenêtre
        display();
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

    interface.draw(world.getHitbox());
}