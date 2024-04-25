// main.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "game.hpp"

float SCREEN_SCALE_ = 3.f;

int main() {

    // sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");
    // Game game(window);
    // game.run();
    std::cout << "Running Game..." << std::endl;

    // Game Start
    sf::RenderWindow window(sf::VideoMode(224.f * SCREEN_SCALE_, 256.f * SCREEN_SCALE_), "Space Invaders");
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(200 * SCREEN_SCALE_, 50 * SCREEN_SCALE_));
    
    // Game Update
    while (window.isOpen()) {
        game::menu(window, SCREEN_SCALE_);
    }

    return 0;
}
