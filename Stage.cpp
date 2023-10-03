#include <vector>
#include <GL/glut.h>
#include "Stage.h"
#include "Point.h"
#include "Player.h"

#define BORDER_HEIGHT 5.0

Stage::Stage(double xbegin, double xend, double zbegin, double zend):
xrange(xbegin, xend), zrange(zbegin, zend) {}

void Stage::draw(){
    glBegin(GL_QUADS);
        glVertex3f(xrange.begin, 0, zrange.begin);
        glVertex3f(xrange.begin, BORDER_HEIGHT, zrange.begin);
        glVertex3f(xrange.end, BORDER_HEIGHT, zrange.begin);
        glVertex3f(xrange.end, 0, zrange.begin);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(xrange.begin, 0, zrange.end);
        glVertex3f(xrange.begin, BORDER_HEIGHT, zrange.end);
        glVertex3f(xrange.end, BORDER_HEIGHT, zrange.end);
        glVertex3f(xrange.end, 0, zrange.end);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(xrange.begin, 0, zrange.begin);
        glVertex3f(xrange.begin, BORDER_HEIGHT, zrange.begin);
        glVertex3f(xrange.begin, BORDER_HEIGHT, zrange.end);
        glVertex3f(xrange.begin, 0, zrange.end);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(xrange.end, 0, zrange.end);
        glVertex3f(xrange.end, BORDER_HEIGHT, zrange.end);
        glVertex3f(xrange.end, BORDER_HEIGHT, zrange.begin);
        glVertex3f(xrange.end, 0, zrange.begin);
    glEnd();
}
