#include <bits/stdc++.h>
#include <cmath>
#include <GL/freeglut.h>
#include "global.h"
#include "Player.h"
#include "Point.h"

Player::Player()
{
    theta = 0;
    speed = PLAYER_SPEED;
    score = 0;
    grow();
}

void Player::incTheta(double dtheta)
{
    theta += dtheta;
}

void Player::move()
{ 
    /* Store the old head position on the body */
    body.push_front(pos); 

    pos.x += speed * sin(theta);
    pos.z += speed * cos(theta);

    /* Check for border colision */
    if (stage.isIn(pos))
        exit(0);

    /* Try to eat some food */
    if (eat())
        grow();

   body.pop_back();

   /*
    * Disconsider the firsts points of the body, since they're always close
    * to the head
    */
   bool mark = false;
   for (auto p : body) {
       if (!mark && pos.distance(p) >= 2 * PLAYER_SIZE)
           mark = true;

       if (mark && pos.distance(p) < 2 * PLAYER_SIZE)
           exit(0);
   }
}

void Player::commitCamera()
{
    Point cameraTarget(pos.x + VIEW_RANGE * sin(theta),
                       pos.z + VIEW_RANGE * cos(theta));
    Point cameraPos(pos.x - VIEW_RANGE * sin(theta),
                    pos.z - VIEW_RANGE * cos(theta));

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEW_ANGLE, fAspect, VIEW_MIN, VIEW_MAX);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(cameraPos.x, VIEW_RANGE / 2, cameraPos.z,
              cameraTarget.x, -VIEW_RANGE / 4, cameraTarget.z,
              0, 1, 0);
}

void Player::draw()
{
    /* Draw the head */
    glPushMatrix();
        glTranslatef(pos.x, PLAYER_SIZE, pos.z);
        glutSolidSphere(PLAYER_SIZE, 10, 10);
    glPopMatrix();

    /* Draw the body */
    for (auto p : body) {
        glPushMatrix();
            glTranslatef(p.x, PLAYER_SIZE, p.z);
            glutSolidSphere(PLAYER_SIZE, 10, 10);
        glPopMatrix();
    }
}

bool Player::eat()
{
    /* The food has radius=PLAYER_SIZE/2 */
    if (pos.distance(food.pos) < 3 * PLAYER_SIZE / 2) {
         score++;
         food.gen();
         return true;
     }
     return false;
}

void Player::printScore()
{
    glDisable(GL_LIGHTING);
    std::string s("Score: ");
    s += std::to_string(score);
    glRasterPos3d(pos.x + 1.5 * PLAYER_SIZE * sin(theta + M_PI_2),
                  0.6 * VIEW_RANGE,
                  pos.z + 1.5 * PLAYER_SIZE * cos(theta + M_PI_2));
    glutBitmapString(GLUT_BITMAP_9_BY_15, (unsigned char*)s.c_str());
    glEnable(GL_LIGHTING);
}

void Player::grow()
{
    for (int i = 0; i < GROWTH_BY_FOOD; i++)
        body.push_front(pos); 
}
