#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include "Player.h"
#include "Range.h"
#include "global.h"

Player::Player()
{
    x = PLAYER_SIZE;
    z = -PLAYER_SIZE;
    theta = 0;
    speed = 2.0;
    score = 0;
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

void Player::move()
{
    x += speed * cos(theta);
    z += speed * -sin(theta);
    if (colides())
        exit(0);
    eat();
}

void Player::commitCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEW_ANGLE, WIDTH/HEIGHT, VIEW_MIN, VIEW_MAX);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x + VIEW_RANGE * -cos(theta), VIEW_RANGE / 2, z + VIEW_RANGE * sin(theta),
              x + VIEW_RANGE * cos(theta), 0, z + VIEW_RANGE * -sin(theta),
              0, 1, 0);
}

void Player::draw()
{
    glPushMatrix();
        glTranslatef(x, PLAYER_SIZE / 2 , z);
        glutSolidSphere(PLAYER_SIZE, 20, 20);
    glPopMatrix();
}

bool Player::colides()
{
    auto xrange = stage.xrange;
    auto zrange = stage.zrange;
    if (x - PLAYER_SIZE < xrange.begin ||
        x + PLAYER_SIZE > xrange.end   ||
        z + PLAYER_SIZE > zrange.end   ||
        z - PLAYER_SIZE < zrange.begin)
            return true;

    return false;
}

void Player::eat()
{
    const double distance = 3 * PLAYER_SIZE / 2;
    if(std::fabs(x - food.x) < distance &&
       std::fabs(z - food.z) < distance) {
         score++;
         food.gen();
     }
}
