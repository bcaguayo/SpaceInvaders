#include <SFML/Graphics.hpp>
#include <string>

class renderable {
public:
    void loadTexture(int scale) {
        if (!texture.loadFromFile(getTexturePath())) {
            std::cerr << "Error loading player texture" << std::endl;
        }

        sprite.setTexture(texture);
        sprite.setPosition(112 * scale, 200 * scale);
        sprite.setScale(scale, scale);
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


    void render(sf::RenderWindow& window) {
        window.draw(sprite);
    }

protected:
    virtual std::string getTexturePath() const = 0;
    sf::Texture texture;
    sf::Sprite sprite;   
};
