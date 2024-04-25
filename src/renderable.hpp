#ifndef RENDER_HPP
#define RENDER_HPP

#include <SFML/Graphics.hpp>
#include <string>

class renderable {
public:
    renderable() : SCREEN_SCALE(3.f) {}

    renderable(float scale) : SCREEN_SCALE(scale) {}

    void loadTexture() {
        if (!texture.loadFromFile(getTexturePath())) {
            std::cerr << "Error loading player texture" << std::endl;
        }

        sprite.setTexture(texture);
    }

    virtual void setRScale() = 0;

    float getPositionX() {
        return sprite.getPosition().x;
    }

    float getPositionY() {
        return sprite.getPosition().y;
    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    virtual void move(bool right) = 0;

    void moveto(renderable& r) {
        sprite.setPosition(r.getPositionX(), r.getPositionY());
    }

    void moveto(float x, float y) {
        sprite.setPosition(x, y);
    }

    void color(sf::Color color) {
        sprite.setColor(color);
    }

    sf::FloatRect getBounds() {
        return sprite.getGlobalBounds();
    }

    void moveto(renderable& r, float x_offset, float y_offset) {
        float x = r.getPositionX() + x_offset;
        float y = r.getPositionY() + y_offset;
        sprite.setPosition(x, y);
    }

    void render(sf::RenderWindow& window) {
        window.draw(sprite);
    }

protected:
    virtual std::string getTexturePath() const = 0;
    sf::Texture texture;
    sf::Sprite sprite;
    float SCREEN_SCALE;  
};

#endif // RENDER_HPP