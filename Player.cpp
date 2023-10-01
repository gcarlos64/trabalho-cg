#include <GL/glut.h>
#include <math.h>
#include "Player.h"

Player::Player()
{
    x = 0;
    y = 0;
    z = 0;
    theta = 0;
    commitCamera();
}

void Player::setTheta(double theta)
{
    this->theta = theta;
}

void Player::incTheta(double dtheta)
{
    theta = (theta + dtheta);
}

void Player::move(double distance, double direction)
{
    x += distance * cos(theta + direction);
    z += distance * -sin(theta + direction);
}

void Player::commitCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 800/600, 0.1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x + 200 * -cos(theta), 200, z + 200 * sin(theta),
              x + 200 * cos(theta), 0, z + 200 * -sin(theta),
              0, 1, 0);
}

void Player::draw()
{
    glPushMatrix();
        glTranslatef(x, y + 30.0, z);
        glutSolidCube(10.0);
    glPopMatrix();
}
