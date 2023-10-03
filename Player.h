#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

#define VIEW_MAX 1500
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
        void printScore();

    private:
        unsigned int score;
        double theta, speed;
        Point pos;
};

#endif
