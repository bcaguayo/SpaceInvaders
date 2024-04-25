#include <SFML/Graphics.hpp>
#include <cstdlib> // rand() and srand()
#include <ctime>   // time()
#include <iostream>
#include "game.hpp"
#include "player.hpp"
#include "missile.hpp"
#include "alien.hpp"

/* ________________________ Local Vars ________________________ */
float SCREEN_SCALE;
player p;
int cooldown;
std::vector<missile> missiles;

// vector of 55 bools, true if alive, false if dead
// 0-10 = squid
// 11-33 = crab
// 34-54 = octopus
// 3 sprites, rendering depends on index on vector
std::vector<std::unique_ptr<alien>> aliens;
std::vector<bool> alive;
bool direction = true;
int tick = 0;

std::vector<missile> alienMissiles;

/* ________________________ Methods ________________________ */

void game::start(sf::RenderWindow& window, float scale) {
    // Window
    SCREEN_SCALE = scale;

    // Seed the rng for alien missiles
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Player
    p = player(SCREEN_SCALE);
    p.loadTexture();
    p.setRScale();
    
    // Aliens
    aliens.clear();
    for (int i = 0; i < 55; i++) {
        alien::AlienType at =  i < 11 ? alien::AlienType::SQUID : 
                        i < 33 ? alien::AlienType::CRAB : alien::AlienType::OCTOPUS;
        // auto a = *aliensBuffer[i];
        auto a = std::make_unique<alien>(at, SCREEN_SCALE);
        a->loadTexture();
        a->setRScale(i);
        aliens.push_back(std::move(a));
        alive.push_back(true);
    }
}

void game::update(sf::RenderWindow& window) {
    tick++;
    tick %= 60;
    
    // ________________________ 1. Poll
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } 
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        window.close();
    }

    // ________________________ 2. Update Missiles
    for (int i = 0; i < missiles.size(); i++) {
        missiles[i].move(false);
        if (missiles[i].getPositionY() < 0.f || missiles[i].getPositionY() > 300.f * SCREEN_SCALE) {
            missiles.erase(missiles.begin() + i);
        }
    }

    for (int i = 0; i < alienMissiles.size(); i++) {
        alienMissiles[i].move(false);
        if (alienMissiles[i].getPositionY() < 0.f || alienMissiles[i].getPositionY() > 300.f * SCREEN_SCALE) {
            alienMissiles.erase(alienMissiles.begin() + i);
        }
    }

    // ________________________ 3. Move Aliens
    if (tick == 0 || tick == 30) {
        int size = aliens.size();
        bool changeDirection = 0;
        for (size_t i = 0; i < size; ++i) {
            auto& a = *(aliens[i]);
            a.move(direction);

            if (i == size - 11 && a.getPositionX() <= 11 * SCREEN_SCALE || 
                i == size - 1 && a.getPositionX() >= 204 * SCREEN_SCALE) {
                changeDirection = true;
            }
        }
        if (changeDirection) {
            direction = !direction;
            changeDirection = false;
        }
    } else if (tick == 1) {
        // make enemy missile
        missile m = missile(SCREEN_SCALE, 2.f);

        // Generate a random index within the range of the vector size
        size_t randomIndex = std::rand() % aliens.size();

        // Access the random alien
        auto& randomAlien = *(aliens[randomIndex]);

        m.loadTexture();
        m.setRScale();
        m.color(sf::Color::White);
        m.moveto(randomAlien.getPositionX(), randomAlien.getPositionY());
        alienMissiles.push_back(m);
    }
    
    // ________________________ 4. Player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && 
        p.getPositionX() > 10.f * SCREEN_SCALE) {
        p.move(false);
    } else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && 
                p.getPositionX() < 204.f * SCREEN_SCALE) {
        p.move(true);
    }

    if (cooldown > 0) {
        cooldown--;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        // wip missile cooldown
        missile m = missile(SCREEN_SCALE);
        m.loadTexture();
        m.setRScale();
        m.moveto(p, 6.f * SCREEN_SCALE, 0.f);
        missiles.push_back(m);
        cooldown = 15;
    }

    // 5. Draw
    game::draw(window);
}

void game::draw(sf::RenderWindow& window) {
    window.clear();
    p.render(window);
    for (int i = 0; i < missiles.size(); i++) {
        missiles[i].render(window);
    }
    for (int i = 0; i < aliens.size(); ++i) {
        aliens[i]->render(window);
    }
    for (int i = 0; i < alienMissiles.size(); i++) {
        alienMissiles[i].render(window);
    }
    window.display();
}



/*
Render Instructions

Press Enter to play
Press Q to quit the game
Optional: Press L for leaderboards
*/

std::string textString = "SPACE INVADERS\nPress Enter to play\nPress Q to quit the game";

void game::menu(sf::RenderWindow& window, float SCREEN_SCALE_) {
    sf::Font font;
    if (!font.loadFromFile("assets/Code7X5.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Set font
    sf::Text menuText;
    menuText.setFont(font);
    menuText.setString(textString);
    menuText.setCharacterSize(20); // in pixels, not points!
    menuText.setFillColor(sf::Color::White);
    menuText.setStyle(sf::Text::Bold);
    menuText.setPosition(0.f * SCREEN_SCALE_, 64.f * SCREEN_SCALE_);

    // Need to do this or textures break
    alien a1(alien::AlienType::SQUID,   SCREEN_SCALE_);
    alien a2(alien::AlienType::CRAB,    SCREEN_SCALE_);
    alien a3(alien::AlienType::OCTOPUS, SCREEN_SCALE_);

    std::vector<alien*> aliensBuffer = {&a1, &a2, &a3};

    std::vector<alien> aliensL;
    for (int i = 0; i < 3; i++) {
        alien::AlienType at = i == 0 ? alien::AlienType::SQUID : 
                              i == 1 ? alien::AlienType::CRAB : alien::AlienType::OCTOPUS;
        alien& a = *aliensBuffer[i];
        // (i == 0) ? a1 = a : (i == 1) ? a2 = a : a3 = a;
        a.loadTexture();
        a.setRScale(0);
        a.setPosition(20.f * SCREEN_SCALE_, (100.f + 20.f * i) * SCREEN_SCALE_);
        aliensL.push_back(a);
    }

    window.clear();
    window.draw(menuText);
    for (int i = 0; i < 3; i++) {
        aliensL[i].render(window);
    }
    window.display();

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } 
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        game::start(window, SCREEN_SCALE_);
        while (window.isOpen()) {
            game::update(window);
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        window.close();
    }
}

void text(sf::RenderWindow& window, std::string text) {
    sf::Font font;
    if (!font.loadFromFile("assets/Code7X5.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Set font
    sf::Text menuText;
    menuText.setFont(font);
    menuText.setString(text);
    menuText.setCharacterSize(20); // in pixels, not points!
    menuText.setFillColor(sf::Color::White);
    menuText.setStyle(sf::Text::Bold);
    menuText.setPosition(0.f * SCREEN_SCALE, 64.f * SCREEN_SCALE);

    window.clear();
    window.draw(menuText);
    window.display();
}