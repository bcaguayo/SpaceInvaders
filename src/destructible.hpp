#ifndef DESTRUCTIBLE_HPP
#define DESTRUCTIBLE_HPP

class Destructible {
public:
    Destructible() : health(1) {}
    Destructible(int initialHealth) : health(initialHealth) {}

    void takeDamage(int damage) {
        health -= damage;
        if (health <= 0) {
            // destroy texture if it exists
            if (texture.has_value()) {
                texture = nullptr;
            }
            destroy();
        }
    }

    virtual void destroy() = 0;

protected:
    int health;

private:
    std::optional<sf::Texture> texture;

};

#endif // DESTRUCTIBLE_HPP