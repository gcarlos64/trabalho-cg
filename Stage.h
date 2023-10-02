#ifndef STAGE_H
#define STAGE_H

#include <vector>
#include "Point.h"
#include "Player.h"

class Stage {
    public:
        Stage(std::vector<Point> points);
        void draw();
        std::vector<Point> getPoints();

    private:
        std::vector<Point> points;
};

#endif
