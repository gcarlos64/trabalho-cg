#include <GL/glut.h>
#include <cmath>
#include "global.h"
#include "Player.h"
#include "Point.h"

Player::Player():
pos(PLAYER_SIZE, -PLAYER_SIZE)
{
    theta = 0;
    speed = 2.0;
    score = 0;
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
    pos.x += speed * cos(theta);
    pos.z += speed * -sin(theta);
    if (stage.isIn(pos))
        exit(0);
    eat();
}

void Player::commitCamera()
{
    Point cameraTarget(pos.x + VIEW_RANGE * cos(theta),
                       pos.z - VIEW_RANGE * sin(theta));
    Point cameraPos(pos.x - VIEW_RANGE * cos(theta),
                    pos.z + VIEW_RANGE * sin(theta));

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEW_ANGLE, WIDTH/HEIGHT, VIEW_MIN, VIEW_MAX);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(cameraPos.x, VIEW_RANGE / 2, cameraPos.z,
              cameraTarget.x, 0, cameraTarget.z,
              0, 1, 0);
}

void Player::draw()
{
    glPushMatrix();
        glTranslatef(pos.x, PLAYER_SIZE / 2 , pos.z);
        glutSolidSphere(PLAYER_SIZE, 20, 20);
    glPopMatrix();
}

void Player::eat()
{
    if (pos.distance(food.pos) < 3 * PLAYER_SIZE / 2) {
         score++;
         speed += 0.1;
         food.gen();
     }
}
