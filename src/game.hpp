#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class game {
public:
    static void start(sf::RenderWindow& window, float scale);
    static void update(sf::RenderWindow& window);

private:
    private:
        sf::RenderWindow& window;
};

#endif // GAME_HPP