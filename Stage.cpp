#include <cmath>
#include <GL/glut.h>
#include <vector>
#include "Player.h"
#include "Point.h"
#include "Stage.h"

#define BORDER_HEIGHT 5.0

Stage::Stage(double radius, unsigned int slices)
{
    this->radius = radius;
    this->slices = slices;

    double theta = 0.0;
    double dtheta = 2 * M_PI / slices;
    for (int i = 0; i <= slices; i++, theta += dtheta)
        border.push_back(Point(radius * sin(theta), radius * cos(theta)));
}

void Stage::draw(){
    glBegin(GL_TRIANGLE_STRIP);
        for (auto p : border) {
            glVertex3f(p.x, 0, p.z);
            glVertex3f(p.x, BORDER_HEIGHT, p.z);
        }
    glEnd();
}

bool Stage::isIn(Point &p)
{
    return p.distance(Point(0.0, 0.0)) > radius - PLAYER_SIZE;
}
