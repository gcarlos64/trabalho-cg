#include <cmath>
#include "Point.h"

Point::Point(double x, double z)
{
    this->x = x;
    this->z = z;
}

Point::Point()
{
    Point(0.0, 0.0);
}

double Point::distance(const Point &p)
{
    return sqrt(pow(p.x - x, 2) + pow(p.z - z, 2));
}
