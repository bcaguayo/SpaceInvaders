#include <SFML/Graphics.hpp>
#include "game.hpp"

void start(sf::RenderWindow& window) {
    window.setFramerateLimit(60);
}

void update(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
    
    window.clear();    
    window.display();
}