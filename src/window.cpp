#include "../header/window.hpp"
#include "../header/thomas.hpp"
#include "../header/data.hpp"
#include "../header/block.hpp"

Interface::Interface()
{
    interface.create(VideoMode(CONST_WIDTH, CONST_HEIGHT, 32), CONST_TITLE);
    interface.setVerticalSyncEnabled(true);
    jump = 0;
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

        // Vérification des inputs
        checkInput();


        // Vérification de présence
        bloc.presence(p1);

        // Affichage du texte, ou de tout autre chose
        interface.draw(text);

        // Affichage de bloc
        interface.draw(bloc.getShape());

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

void Interface::checkInputQ()
{
    setText("Q");
    p1.walk.y = Thomas::Dir::Left;
    p1.move(-1 * CONST_PLAYER_SPEED, 0);
    p1.setIdle(false);
}

void Interface::checkInputD()
{
    setText("D");
    p1.walk.y = Thomas::Dir::Right;
    p1.move(1 * CONST_PLAYER_SPEED, 0);
    p1.setIdle(false);
}

void Interface::checkInputSpace()
{
    if (jump > 0)
    {
        setText("Space");
        p1.move(0, -4);
        jump--;
        p1.setJump(true);
    } else 
    {
        p1.setJump(false);
    }
}

void Interface::checkInput()
{
    if (!p1.getonBlock() && jump == false)
    {
        p1.move(0, CONST_GRAVITY * p1.getGravity());
        p1.setGravity(p1.getGravity() + 0.1);
    } else 
    {
        if (input.getButton().espace && p1.getonBlock())
        {
            jump = 30;
            p1.setGravity(2);
        }
    }
    checkInputSpace();
    if (input.getButton().q)
    {
        checkInputQ();
        return;
    }
    if (input.getButton().d)
    {
        checkInputD();
        return;
    }

    p1.setIdle(true);
}