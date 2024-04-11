// main.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
// #include "game.h"
#include <iostream>

int main()
{

    // sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");
    // Game game(window);
    // game.run();
    std::cout << "Running Game" << std::endl;

    sf::RenderWindow window(sf::VideoMode(450, 450), "SFML works!"); //, sf::Style::Fullscreen);
    // f::VideoMode(), "app.exe", sf::Style::Fullscreen
    window.setVerticalSyncEnabled(false);
    window.display();
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     window.clear();
    //     window.draw(shape);
    //     window.display();
    // }

    return 0;
}