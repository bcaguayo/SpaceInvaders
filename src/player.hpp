#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "renderable.hpp"

// WIP abstract to Renderable
class player : public renderable {
public:

    player() : renderable(3.f) {}

    player(float scale) : renderable(scale) {}

    void setRScale() override {
        sprite.setPosition(112 * SCREEN_SCALE, 200 * SCREEN_SCALE);
        sprite.setScale(SCREEN_SCALE, SCREEN_SCALE);
    }

    void move(bool right) override {
        float localSpeed = 1.f * SCREEN_SCALE;
        right ? sprite.move(localSpeed, 0.f) : sprite.move(-localSpeed, 0.f);
    }

protected:
    std::string getTexturePath() const override {
        return "assets/laser.png";
    }
    float speed;
};

#endif // PLAYER_HPP