#ifndef STAGE_H
#define STAGE_H

#include <vector>
#include "Point.h"
#include "Player.h"
#include "Range.h"

class Stage {
    public:
        Stage(double xbegin, double xend, double zbegin, double zend);
        void draw();
        Range xrange, zrange;
};

#endif
