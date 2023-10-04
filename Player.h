#ifndef PLAYER_H
#define PLAYER_H

#include <deque>
#include "Point.h"

#define GROWTH_BY_FOOD 10
#define PLAYER_SIZE 10.0
#define PLAYER_SPEED 2.5
#define VIEW_ANGLE 45
#define VIEW_MAX 1500
#define VIEW_MIN 0.1
#define VIEW_RANGE 400

class Player {
    public:
        Player();
        void setTheta(double theta);
        void incTheta(double dtheta);
        void move();
        void commitCamera();
        void draw();
        bool eat();
        void printScore();
        void grow();

    private:
        unsigned int score;
        double theta, speed;
        Point pos;
        std::deque<Point> body;
};

#endif
