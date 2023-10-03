#ifndef STAGE_H
#define STAGE_H

#include <vector>
#include "Point.h"

class Stage {
    public:
        Stage(double radius, unsigned int slice);
        void draw();
        bool isIn(Point &p);
        double radius;

    private:
        unsigned int slices;
        Point center;
        Point controlPoints[4];
        std::vector<Point> border, division;
};

#endif
