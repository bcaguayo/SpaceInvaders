#ifndef ENTITY_HPP
#define ENTITY_HPP

class entity {
public:
    entity() : x(112.f), y(224.f), speed(0.f) {};

    entity(float x, float y, float speed) : x_(x), y_(y), speed_(speed) {};

    int getX() const;
    int getY() const;
    int getSpeed() const;

    
    virtual void move(bool right) = 0;

protected:
    float x_;
    float y_;
    float speed_;
};

#endif // ENTITY_HPP