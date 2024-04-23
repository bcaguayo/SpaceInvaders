#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
public:
    void start(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);

private:
    private:
        sf::RenderWindow& window;
};

#endif // GAME_HPP