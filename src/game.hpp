#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class game {
public:
    static void start(sf::RenderWindow& window, float scale);
    static void update(sf::RenderWindow& window);
    static void menu(sf::RenderWindow& window, float scale);
    static void draw(sf::RenderWindow& window);
    static void pauseForSeconds(int seconds);
    static void text(sf::Text& textObject, std::string text, sf::Font& font, sf::Color color, 
                bool bold, int size, float posX, float posY, int scale);
};

#endif // GAME_HPP

// wip window protected