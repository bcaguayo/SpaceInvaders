#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class game {
public:
    static void start(sf::RenderWindow& window, float scale);
    static void update(sf::RenderWindow& window);
    static void menu(sf::RenderWindow& window);
    static void draw(sf::RenderWindow& window);
};

#endif // GAME_HPP

// wip window protected