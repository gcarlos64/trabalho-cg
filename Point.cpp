#include <cmath>
#include "Point.h"

Point::Point(double x, double z)
{
    this->x = x;
    this->z = z;
}

Point::Point()
{
    this->x = 0.0;
    this->z = 0.0;
}

/* Bezier */
Point::Point(Point *controlPoints, double t)
{
    double x, z;
    x = pow(1 - t, 3) * controlPoints[0].x +
        3 * t * pow(1 - t, 2) * controlPoints[1].x +
        3 * pow(t, 2) * (1 - t) * controlPoints[2].x +
        pow(t, 3) * controlPoints[3].x;
    z = pow(1 - t, 3) * controlPoints[0].z +
        3 * t * pow(1 - t, 2) * controlPoints[1].z +
        3 * pow(t, 2) * (1 - t) * controlPoints[2].z +
        pow(t, 3) * controlPoints[3].z;

    this->x = x;
    this->z = z;
}

double Point::distance(const Point &p)
{
    return sqrt(pow(p.x - x, 2) + pow(p.z - z, 2));
}

