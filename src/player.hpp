#include <SFML/Graphics.hpp>
#include <iostream>

class player {
public:

    player() {
        texture = sf::Texture();
        sprite = sf::Sprite();
    }

    void loadTexture(int scale) {
        if (!texture.loadFromFile("assets/laser.png")) {
            std::cerr << "Error loading player texture" << std::endl;
        }

        sprite.setTexture(texture);
        sprite.setPosition(112 * scale, 200 * scale);
        sprite.setScale(scale, scale);
    }

    sf::Sprite getSprite() {
        return sprite;
    }

    float getPositionX() {
        return sprite.getPosition().x;
    }

    float getPositionY() {
        return sprite.getPosition().y;
    }

    void move(float x, float y) {
        sprite.move(x, y);
    }

    void render (sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};