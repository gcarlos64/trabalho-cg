#include <vector>
#include <GL/glut.h>
#include "Stage.h"
#include "Point.h"
#include "Player.h"

#define BORDER_HEIGHT 5.0

Stage::Stage(std::vector<Point> points)
{
    this->points = points;
}

void Stage::draw(){
    for (int i = 0; i < points.size(); i++) {
        Point p = points[i % points.size()];
        Point np = points[(i + 1) % points.size()];

        glBegin(GL_QUADS);
            glVertex3f(p.x, 0, p.z);
            glVertex3f(p.x, BORDER_HEIGHT, p.z);
            glVertex3f(np.x, BORDER_HEIGHT, np.z);
            glVertex3f(np.x, 0, np.z);
        glEnd();
    }
}

std::vector<Point> Stage::getPoints()
{
    return points;
}
