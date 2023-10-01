#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player();
        void setTheta(double theta);
        void incTheta(double dtheta);
        void move(double distance, double direction);
        void commitCamera();
        void draw();

    private:
        double x, y, z, theta;
};

#endif
