#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
public:
    void start(sf::RenderWindow& window) { window.setFramerateLimit(60); }
    void update(sf::RenderWindow& window);

private:
    private:
        sf::RenderWindow& window;
};

#endif // GAME_HPP