#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "player.hpp"

float SCREEN_SCALE = 1.f;
float TESTING_SPEED = 3.f;

player p;
sf::RectangleShape missile;
float missileSpeed;
bool fired;

void game::start(sf::RenderWindow& window, float scale) {
    SCREEN_SCALE = scale;
    window.setFramerateLimit(60);

    // Player
    p = player();
    p.loadTexture(SCREEN_SCALE);

    // Missile
    missile.setSize(sf::Vector2f(1.f * SCREEN_SCALE, 2.f * SCREEN_SCALE));
    missile.setFillColor(sf::Color::Green);
    missileSpeed = 12.f;
    fired = false;
}


void game::update(sf::RenderWindow& window) {
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && p.getPositionX() > 10.f * SCREEN_SCALE) {
        p.move(-1.f * TESTING_SPEED, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && p.getPositionX() < 204.f * SCREEN_SCALE) {
        p.move(1.f * TESTING_SPEED, 0.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        // wip many missiles and missile cooldown
        missile.setPosition(p.getPositionX() + 6.f * SCREEN_SCALE, 
                            p.getPositionY() + 3.f * SCREEN_SCALE);
        fired = true;
    }

    window.clear();
    p.render(window);
    window.draw(missile);
    window.display();

}

/*
Render Instructions

Press Enter to play
Press Q to quit the game
Optional: Press L for leaderboards
*/
std::string textString = "SPACE INVADERS\nPress Enter to play\nPress Q to quit the game";

void game::menu(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("assets/Code7X5.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Set font
    sf::Text menuText;
    menuText.setFont(font);
    
    // set the string to display
    menuText.setString(textString);

    // set the character size
    menuText.setCharacterSize(24); // in pixels, not points!

    // set the color
    menuText.setFillColor(sf::Color::White);

    // set the menuText style
    menuText.setStyle(sf::Text::Bold);

    // centered
    menuText.setPosition(0.f * SCREEN_SCALE, 128.f * SCREEN_SCALE);

    window.clear();
    window.draw(menuText);
    window.display();

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } 
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        while (window.isOpen()) {
            game::update(window);
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        window.close();
    }
}

/*
BASE
sf::Event event;
while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
}

window.clear();    
window.display();
*/