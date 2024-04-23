#include <SFML/Graphics.hpp>

class Renderable {
public:
    virtual ~Renderable() = default;

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    void setScale(float x, float y) {
        sprite.setScale(x, y);
    }

    void render(sf::RenderWindow& window) {
        window.draw(sprite);
    }

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    
    virtual void loadTexture() = 0;
};
