#ifndef FOOD_H
#define FOOD_H

#include "Point.h"

class Food {
    public:
        Food();

        /* Render the food */
        void draw();

        /* Set the food position randomly */
        void gen();

        /* Food positoin */
        Point pos;
};

#endif 
