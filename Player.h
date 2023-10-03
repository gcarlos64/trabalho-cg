#ifndef PLAYER_H
#define PLAYER_H

#include "Stage.h"

#define VIEW_MAX 1000
#define VIEW_MIN 0.1
#define VIEW_ANGLE 45
#define VIEW_RANGE 400
#define PLAYER_SIZE 10.0

class Player {
    public:
        Player();
        void setTheta(double theta);
        void incTheta(double dtheta);
        void move();
        void commitCamera();
        void draw();
        void eat();
        bool colides();

    private:
        unsigned int score;
        double x, z, theta, speed;
};

#endif
