// main.cpp
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "game.hpp"

float SCREEN_SCALE = 3.f;
float TESTING_SPEED = 3.f;
float GAME_SPEED = 3.f;

int main() {

    // sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");
    // Game game(window);
    // game.run();
    std::cout << "Running Game..." << std::endl;

    // Game Start
    sf::RenderWindow window(sf::VideoMode(224.f * SCREEN_SCALE, 256.f * SCREEN_SCALE), "Space Invaders");
    window.setFramerateLimit(60);
    
    sf::Texture player;
    if (!player.loadFromFile("assets/laser.png")) {
        std::cout << "Error loading player texture" << std::endl;
    }

    sf::Sprite playerSprite(player);
    playerSprite.setPosition(112 * SCREEN_SCALE, 200 * SCREEN_SCALE);
    playerSprite.setScale(SCREEN_SCALE, SCREEN_SCALE);

    // Missile
    sf::RectangleShape missile(sf::Vector2f(3.f, 6.f));
    missile.setFillColor(sf::Color::Green);
    float missileSpeed = 12.f;
    bool fired = false;


    // Game Update
    while (window.isOpen())
    {
       
        if (fired) {
            missile.move(0.f, -missileSpeed);
            if (missile.getPosition().y > 256.f * SCREEN_SCALE) {
                // Hide missile
                missile.setPosition(0.f, -100.f);
                fired = false;
            }
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } 
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && 
            playerSprite.getPosition().x > 20.f) {
            playerSprite.move(-1.f * TESTING_SPEED, 0.f);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && 
            playerSprite.getPosition().x < 204.f * SCREEN_SCALE) {
            playerSprite.move(1.f * TESTING_SPEED, 0.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            // wip many missiles and missile cooldown
            missile.setPosition(playerSprite.getPosition().x + 6.f * SCREEN_SCALE, 
                                playerSprite.getPosition().y + 3.f * SCREEN_SCALE);
            fired = true;
        }

        window.clear();
        window.draw(playerSprite);
        window.draw(missile);
        window.display();
    }

    return 0;
}
