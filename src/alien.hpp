#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <string>
#include "renderable.hpp"

class alien : public renderable {
public:
    enum class AlienType {
        SQUID,
        CRAB,
        OCTOPUS
    };

    alien() : renderable(3.f), type_(AlienType::CRAB), alt_(false) {}

    alien(AlienType type, float scale) : renderable(scale), type_(type), alt_(false) {}

    void setRScale() override {
        setRScale(0);
    }

    void setRScale(int index) {
        int x = index % 11;
        int y = index / 11;
        // Do NOT change these values
        sprite.setPosition((10 + 15 * x)  * SCREEN_SCALE - 2 * y, (10 + 15 * y) * SCREEN_SCALE);
        sprite.setScale(SCREEN_SCALE, SCREEN_SCALE);
    }

    void move(bool right) override {
        float localSpeed = 4.f * SCREEN_SCALE;
        right ? sprite.move(localSpeed, 0.f) : sprite.move(-localSpeed, 0.f);
    }

    std::string getTexturePath() const override {
        switch (type_) {
            case AlienType::CRAB :
                return (!alt_ ? "assets/enemy1B.png" : "assets/enemy1A.png");
            case AlienType::OCTOPUS :
                return (!alt_ ? "assets/enemy2B.png" : "assets/enemy2A.png");
            case AlienType::SQUID :
                return (!alt_ ? "assets/enemy3B.png" : "assets/enemy3A.png");
            default:
                return "assets/default.png";
        }
    }

public:
    AlienType type_;
    bool alt_;
};

#endif // ALIEN_HPP
