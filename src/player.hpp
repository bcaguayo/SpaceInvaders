#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "renderable.hpp"

class player : public renderable {
private:
    std::string texturePath;

public:
    player() : texturePath("assets/laser.png") {}

    void render() override {
        // Implement the rendering logic for the player here
        // using the texturePath variable
    }
};

#endif // PLAYER_HPP