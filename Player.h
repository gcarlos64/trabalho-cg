#ifndef PLAYER_H
#define PLAYER_H

#include <deque>
#include "Point.h"

/* Player behaviour */
#define GROWTH_BY_FOOD 10
#define PLAYER_SIZE 7.0
#define PLAYER_SPEED 2.5

/* Camera settings */
#define VIEW_ANGLE 45
#define VIEW_MAX 1500
#define VIEW_MIN 0.1
#define VIEW_RANGE 400

class Player {
    public:
        Player();
        /* Increment theta by dtheta */
        void incTheta(double dtheta);

        /* Calculate new snake position and checks for colision */
        void move();

        /* Update camera configuration */
        void commitCamera();

        /* Draw the snake */
        void draw();

        /* Check if close enought to a food and return true on eat */
        bool eat();

        void printScore();

        /* Add new points to the snake body, increasing its size */
        void grow();

    private:
        unsigned int score;

        /*
         * This forms a speed vector in polar coords composed by the scalar
         * speed and the angle from the z axis (the snake moves over the zx
         * plane).
         */ 
        double theta, speed;

        /* Head position */
        Point pos;

        std::deque<Point> body;
};

#endif
