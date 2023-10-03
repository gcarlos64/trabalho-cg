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

    controlPoints[0] = Point(0.0, -radius);
    controlPoints[1] = Point(radius * -sin(M_PI / 3), radius * -cos(M_PI / 3));
    controlPoints[2] = Point(radius * sin(M_PI / 3), radius * cos(M_PI / 3));
    controlPoints[3] = Point(0.0, radius);
    /*
    controlPoints = {
        Point(0.0, -radius),
        Point(radius * sin(-M_PI_4), radius * cos(-M_PI_4)),
        Point(radius * sin(M_PI_4), radius * cos(M_PI_4)),
        Point(0.0, radius),
    };
    */

    double t = 0.0;
    double dt = 1.0 / slices;
    for (int i = 0; i <= slices; i++, t += dt)
        division.push_back(Point(controlPoints, t));
}

void Stage::draw(){
    /* Ground */
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.5, 0.5, 0.5);
        for (int i = 0; i <= slices; i++) {
            Point p = border[i];
            glVertex3f(p.x, 0, p.z);
        }
    glEnd();

    /* Division line */
    glBegin(GL_LINE_STRIP);
        glLineWidth(10);
        glColor3f(0.0, 0.0, 0.0);
        for (Point p : division) {
            glVertex3f(p.x, 0.1, p.z);
        }
    glEnd();

    /* Border */
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.2, 1.0, 0.5);
        for (Point p : border) {
            glVertex3f(p.x, 0, p.z);
            glVertex3f(p.x, BORDER_HEIGHT, p.z);
        }
    glEnd();
}

bool Stage::isIn(Point &p)
{
    return p.distance(Point(0.0, 0.0)) > radius - PLAYER_SIZE;
}
