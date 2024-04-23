#ifndef VESSEL_HPP
#define VESSEL_HPP

class Vessel {
public:
    // Constructor
    Vessel(int x, int y, int speedX, int speedY, int firingSpeed, bool firepower, int cooldown)
        : x_(x), y_(y), speedX_(speedX), speedY_(speedY), 
        firepower_(firepower), firingSpeed_(firingSpeed), cooldown_(cooldown) {}
    // Default constructor
    Vessel() : x_(112), y_(200), speedX_(0), speedY_(0), firepower_(false), firingSpeed_(1), cooldown_(1) {}

    // Getters and setters
    int getX() const { return x_; }
    int getY() const { return y_; }
    int getSpeedX() const { return speedX_; }
    int getSpeedY() const { return speedY_; }
    int getFiringSpeed() const { return firingSpeed_; }
    bool hasFirepower() const { return firepower_; }
    int getCooldown() const { return cooldown_; }

    void setX(int x) { x_ = x; }
    void setY(int y) { y_ = y; }
    void setSpeedX(int speedX) { speedX_ = speedX; }
    void setSpeedY(int speedY) { speedY_ = speedY; }
    void setFiringSpeed(int firingSpeed) { firingSpeed_ = firingSpeed; }
    void setFirepower(bool firepower) { firepower_ = firepower; }
    void setCooldown(int cooldown) { cooldown_ = cooldown; }

private:
    int x_;             // Location on the x-axis
    int y_;             // Location on the y-axis
    int speedX_;        // Speed on the x-axis
    int speedY_;        // Speed on the y-axis
    bool firepower_;    // Whether the vessel has firepower
    int firingSpeed_;   // Firing speed per frame
    int cooldown_;      // Cooldown for firing
};

#endif // VESSEL_HPP