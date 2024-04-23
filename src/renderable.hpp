#include <SFML/Graphics.hpp>

class Renderable {
public:
    Renderable(const std::string& texturePath) {
        if (!texture.loadFromFile(texturePath)) {
            // Handle error if texture loading fails
        }
        sprite.setTexture(texture);
    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    void render(sf::RenderWindow& window) {
        window.draw(sprite);
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
};