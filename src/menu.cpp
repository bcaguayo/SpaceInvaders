// main.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "game.hpp"

float SCREEN_SCALE_ = 3.f;

// wip
struct Aliens {
    // alien object
    // vector of bools, true if alive, false if dead
    // 3 sprites, rendering depends on index on vector
};

int main() {

    // sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");
    // Game game(window);
    // game.run();
    std::cout << "Running Game..." << std::endl;

    // Game Start
    sf::RenderWindow window(sf::VideoMode(224.f * SCREEN_SCALE_, 256.f * SCREEN_SCALE_), "Space Invaders");
    game::start(window, SCREEN_SCALE_);
    // window.setFramerateLimit(60);
    
    // Game Update
    while (window.isOpen())
    {
       game::update(window);
    }

    return 0;
}
