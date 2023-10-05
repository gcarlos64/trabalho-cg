#ifndef STAGE_H
#define STAGE_H

#include <vector>
#include "Point.h"

class Stage {
    public:
        /* Create a circular stage using &slice number of points */
        Stage(double radius, unsigned int slice);

        /* Draw the borders */
        void draw();

        /* Check if point p is inside the stage */
        bool isIn(Point &p);

        double radius;

    private:
        unsigned int slices;

        /* Control points for the Bezier curve */
        Point controlPoints[4];

        /* Points for the border and the Bezier curver (division) */
        std::vector<Point> border, division;
};

#endif
