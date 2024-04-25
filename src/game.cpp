#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
#include "player.hpp"
#include "missile.hpp"

float SCREEN_SCALE = 3.f;
player p;
std::vector<missile> missiles;
sf::RectangleShape missileRect;
float missileSpeed;
bool fired;


void game::start(sf::RenderWindow& window, float scale) {
    // Window
    SCREEN_SCALE = scale;
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(600, 400));

    // Player
    p = player(SCREEN_SCALE);
    p.loadTexture();
    p.setRScale();

    // Missile
    missileRect.setSize(sf::Vector2f(1.f * SCREEN_SCALE, 2.f * SCREEN_SCALE));
    missileRect.setFillColor(sf::Color::Green);
    missileSpeed = 12.f;
    fired = false;
}

void game::update(sf::RenderWindow& window) {
    
    // 1. Poll
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } 
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        window.close();
    }

    // 2. Missiles

    if (fired) {
        missileRect.move(0.f, -missileSpeed);
        if (missileRect.getPosition().y > 256.f * SCREEN_SCALE) {
            // Hide missile
            missileRect.setPosition(0.f, -100.f);
            fired = false;
        }
    }

    for (int i = 0; i < missiles.size(); i++) {
        missiles[i].move(false);
        if (missiles[i].getPositionY() < 0.f || missiles[i].getPositionY() > 300.f * SCREEN_SCALE) {
            missiles.erase(missiles.begin() + i);
        }
    }

    // 3. Player

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && 
        p.getPositionX() > 10.f * SCREEN_SCALE) {
        p.move(false);
    } else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && 
                p.getPositionX() < 204.f * SCREEN_SCALE) {
        p.move(true);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        // wip missile cooldown
        missile m = missile(SCREEN_SCALE);
        m.loadTexture();
        m.setRScale();
        m.moveto(p, 6.f * SCREEN_SCALE, 0.f);
        missiles.push_back(m);
    }


    window.clear();
    p.render(window);
    for (int i = 0; i < missiles.size(); i++) {
        missiles[i].render(window);
    }
    // window.draw(missileRect);
    window.display();

}

void game::draw(sf::RenderWindow& window) {
    // wip
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