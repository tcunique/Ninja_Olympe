#include "../header/text.hpp"

UIText::UIText()
{
    TextLoad();
}

UIText::~UIText()
{
}

void UIText::TextLoad()
{
    if (!font.loadFromFile("font/Merchant.ttf"))
    {
        std::cout << "Error while loading font" << std::endl;
    }
    text.setFont(font);
    text.setString("Hello World");
    text.setCharacterSize(50);
    text.setPosition(-200, 500);
}

void UIText::TextDisplay(sf::RenderWindow &window, std::string str)
{
    text.setString(str);
    window.draw(text);
}