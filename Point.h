#ifndef POINT_H
#define POINT_H

class Point {
    public:
        /* Defaults to x-0.0 and y=0.0 */
        Point();

        Point(double x, double z);

        /* Just create a copy of p */
        Point(const Point &p);

        /* Calculate a point from a Bezier curve control points (exactly 4) */
        Point(Point *controlPoints, double t);

        /* Returns the distanc between the caller point and p */
        double distance(const Point &p);
        double x, z;
};

#endif
