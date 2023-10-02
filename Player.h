#ifndef PLAYER_H
#define PLAYER_H

#include "Stage.h"

class Player {
    public:
        Player();
        void setTheta(double theta);
        void incTheta(double dtheta);
        void move();
        void commitCamera();
        void draw();
        bool colides();

    private:
        double x, y, z, theta, speed;
};

#endif
