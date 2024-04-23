#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"

float SCREEN_SCALE = 1.f;
float TESTING_SPEED = 3.f;

sf::Texture player;
sf::Sprite playerSprite;
sf::RectangleShape missile;
float missileSpeed;
bool fired;

void game::start(sf::RenderWindow& window, float scale) {
    SCREEN_SCALE = scale;
    window.setFramerateLimit(60);

    if (!player.loadFromFile("assets/laser.png")) {
        std::cerr << "Error loading player texture" << std::endl;
    }

    playerSprite.setTexture(player);
    playerSprite.setPosition(112 * SCREEN_SCALE, 200 * SCREEN_SCALE);
    playerSprite.setScale(SCREEN_SCALE, SCREEN_SCALE);

    // Missile
    missile.setSize(sf::Vector2f(1.f * SCREEN_SCALE, 2.f * SCREEN_SCALE));
    missile.setFillColor(sf::Color::Green);
    missileSpeed = 12.f;
    fired = false;
}


void game::update(sf::RenderWindow& window) {
    // sf::Event event;
    // while (window.pollEvent(event)) {
    //     if (event.type == sf::Event::Closed) {
    //         window.close();
    //     }
    // }
    
    // window.clear();    
    // window.display();

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