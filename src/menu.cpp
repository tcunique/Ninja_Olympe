#include "../header/menu.hpp"

Menu::Menu(int width, int height)
{
    LoadFont("font/Roboto-Medium.ttf");
    LaunchButtonPlay(width, height);
    LaunchButtonQuit(width, height);
    click = false;
}

Menu::~Menu()
{
}

bool Menu::getClick()
{
    return click;
}

void Menu::setClick(bool click)
{
    this->click = click;
}

void Menu::SpritePlayButtonLoad(int width, int height)
{
    if (!playButtonTexture.loadFromFile("sprite/menu/start.png"))
    {
        std::cout << "Erreur lors du chargement de la texture playButton.png" << std::endl;
    }
    playButtonTexture.setSmooth(true);
    playButton.setTexture(playButtonTexture);
    playButton.setScale(2, 2);
    playButton.setPosition(width / 2.15 - playButton.getGlobalBounds().width / 2, height / 3.5 - playButton.getGlobalBounds().height / 2);
}

void Menu::SpriteQuitButtonLoad(int width, int height)
{
    if (!quitButtonTexture.loadFromFile("sprite/menu/exit.png"))
    {
        std::cout << "Erreur lors du chargement de la texture quitButton.png" << std::endl;
    }
    quitButtonTexture.setSmooth(true);
    quitButton.setTexture(quitButtonTexture);
    quitButton.setScale(2, 2);
    quitButton.setPosition(width / 2.15 - quitButton.getGlobalBounds().width / 2, height / 3.5 - quitButton.getGlobalBounds().height / 2 + 200);
}

void Menu::LaunchButtonPlay(int width, int height)
{
    SpritePlayButtonLoad(width, height);

    // Texte
    playText.setString("Play");
    playText.setCharacterSize(50);
    playText.setFillColor(sf::Color::White);
    playText.setPosition(playButton.getPosition().x + playButton.getGlobalBounds().width / 2 - playText.getGlobalBounds().width / 2, playButton.getPosition().y + playButton.getGlobalBounds().height / 2.4);

    // Hitbox
    playButtonShape.setSize(sf::Vector2f(playButton.getGlobalBounds().width/1.2, playButton.getGlobalBounds().height/1.7));
    playButtonShape.setPosition(playButton.getPosition() + sf::Vector2f(playButton.getGlobalBounds().width/13, playButton.getGlobalBounds().height/5));
    playButtonShape.setFillColor(sf::Color::Transparent);
    playButtonShape.setOutlineColor(sf::Color::Red);
    playButtonShape.setOutlineThickness(2);
}

void Menu::LaunchButtonQuit(int width, int height)
{
    SpriteQuitButtonLoad(width, height);

    // Texte
    quitText.setString("Quit");
    quitText.setCharacterSize(50);
    quitText.setFillColor(sf::Color::White);
    quitText.setPosition(quitButton.getPosition().x + quitButton.getGlobalBounds().width / 2 - quitText.getGlobalBounds().width / 2, quitButton.getPosition().y + quitButton.getGlobalBounds().height / 2.4);

    // Hitbox
    quitButtonShape.setSize(sf::Vector2f(quitButton.getGlobalBounds().width/1.2, quitButton.getGlobalBounds().height/1.7));
    quitButtonShape.setPosition(quitButton.getPosition() + sf::Vector2f(quitButton.getGlobalBounds().width/13, quitButton.getGlobalBounds().height/5));
    quitButtonShape.setFillColor(sf::Color::Transparent);
    quitButtonShape.setOutlineColor(sf::Color::Red);
    quitButtonShape.setOutlineThickness(2);
}

sf::Sprite Menu::getPlayButton()
{
    return playButton;
}

sf::Sprite Menu::getQuitButton()
{
    return quitButton;
}

void Menu::draw(sf::RenderWindow &window)
{
    // Draw button play
    window.draw(playButton);
    window.draw(playText);
    window.draw(playButtonShape);

    // Draw button quit
    window.draw(quitButton);
    window.draw(quitText);
    window.draw(quitButtonShape);
}

void Menu::LoadFont(std::string path)
{
    if (!font.loadFromFile(path))
    {
        std::cout << "Erreur lors du chargement de la police de caractère" << std::endl;
    }
    playText.setFont(font);
    quitText.setFont(font);
}

bool Menu::checkMouseOnPlayButton()
{
    if (playButtonShape.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y) && click == true)
    {
        return true;
    }
    return false;
}

bool Menu::checkMouseOnQuitButton()
{
    if (quitButtonShape.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y) && click == true)
    {
        return true;
    }
    return false;
}
