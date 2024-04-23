#ifndef VESSEL_HPP
#define VESSEL_HPP

class Vessel {
public:
    // Constructor
    Vessel(int x, int y, int speedX, int speedY, int firingSpeed)
        : x_(x), y_(y), speedX_(speedX), firingSpeed_(firingSpeed) {}
    // Default constructor
    Vessel() : x_(112), y_(200), speedX_(0), firingSpeed_(1) {}

    // Getters and setters
    int getX() const { return x_; }
    int getY() const { return y_; }
    int getSpeedX() const { return speedX_; }
    int getFiringSpeed() const { return firingSpeed_; }

    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }
    void setSpeedX(int speedX) { speedX_ = speedX; }
    void setFiringSpeed(int firingSpeed) { firingSpeed_ = firingSpeed; }

private:
    int x_;             // Location on the x-axis
    int y_;             // Location on the y-axis
    int speedX_;        // Speed on the x-axis
    int firingSpeed_;   // Firing speed per frame
};

#endif // VESSEL_HPP