#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "renderable.hpp"

class missile : public renderable {
public:
    // Default constructor
    missile() : renderable(3.f) {}

    // Constructor
    missile (float scale) : renderable(scale) {
    }
    
    missile(float scale, float speed) : renderable(scale), speed(speed) {
    }

    // Destructor
    ~missile() {
    }

    void setRScale() override {
        sprite.setColor(sf::Color(0, 255, 0));
        sprite.setTextureRect(sf::IntRect(1, 3, 1 * SCREEN_SCALE, 3 * SCREEN_SCALE));
        // sprite.setScale(1.f * SCREEN_SCALE, 2.f * SCREEN_SCALE);
    }

    void move(bool _) override {
        sprite.move(0.f, speed);
    }

    float getSpeed() {
        return speed;
    }    

protected:
    std::string getTexturePath() const override { return "assets/default.png"; }
    float speed = -12.f;
};

#endif // MISSILE_HPP