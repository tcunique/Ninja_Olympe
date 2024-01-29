#include "../header/menu.hpp"

Menu::Menu(int width, int height)
{
    LoadFont("font/Roboto-Medium.ttf");
    LaunchButtonPlay(width, height);
    LaunchButtonQuit(width, height);
    click = false;
    deathconstructor = false;
}

Menu::Menu(int width, int height, bool death)
{
    // Load the font
    LoadFont("font/Roboto-Medium.ttf");

    // Load the sprite
    click = false;
    LaunchButtonPlay(width, height);
    playText.setString("Retry");
    LaunchButtonQuit(width, height);

    // Load the background
    background.setSize(sf::Vector2f(width/1.5, height/1.5));
    background.setFillColor(sf::Color(255, 255, 255, 200));

    deathconstructor = death;
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

void Menu::setPosition(sf::Vector2f position)
{
    // Set the position of the background
    background.setPosition(position + sf::Vector2f(-360, -130));

    // Set the position of the button
    playButton.setPosition(position);
    playButtonShape.setPosition(position + sf::Vector2f(26, 36));
    playText.setPosition(position + sf::Vector2f(110, 70));
    
    // Set the position of the button
    quitButton.setPosition(position + sf::Vector2f(0, 200));
    quitButtonShape.setPosition(position + sf::Vector2f(0, 200) + sf::Vector2f(26, 36));
    quitText.setPosition(position+ sf::Vector2f(0, 200) + sf::Vector2f(110, 70));
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
    // Draw the background
    if (deathconstructor == true)
    {
        window.draw(background);
    }

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

bool Menu::checkMouseOnPlayButton(sf::RenderWindow &window)
{
    if (playButtonShape.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && click == true)
    {
        return true;
    }
    return false;
}

bool Menu::checkMouseOnQuitButton(sf::RenderWindow &window)
{
    if (quitButtonShape.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && click == true)
    {
        return true;
    }
    return false;
}
