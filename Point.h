#ifndef POINT_H
#define POINT_H

class Point {
    public:
        Point();
        Point(double x, double z);
        double distance(const Point &p);
        double x;
        double z;
};

#endif
