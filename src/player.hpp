#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "renderable.hpp"

// WIP abstract to Renderable
class player : public renderable {
public:

    player() = default;

    // void loadTexture(int scale) {
    //     if (!texture.loadFromFile(texturePath)) {
    //         std::cerr << "Error loading player texture" << std::endl;
    //     }

    //     sprite.setTexture(texture);
    //     sprite.setPosition(112 * scale, 200 * scale);
    //     sprite.setScale(scale, scale);
    // }

    // float getPositionX() {
    //     return sprite.getPosition().x;
    // }

    // float getPositionY() {
    //     return sprite.getPosition().y;
    // }

    // void move(float x, float y) {
    //     sprite.move(x, y);
    // }

    // void render (sf::RenderWindow& window) {
    //     window.draw(sprite);
    // }

protected:
    // std::string texturePath = "assets/laser.png";
    // sf::Texture texture;
    // sf::Sprite sprite;
    std::string getTexturePath() const override {
        return "assets/laser.png";
    }
};