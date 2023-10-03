#include <cmath>
#include <random>
#include <GL/glut.h>

#include "Food.h"
#include "global.h"
#include "Player.h"
#include "Stage.h"

std::random_device rd;
std::mt19937 seed(rd());

Food::Food()
{
    gen();
}

void Food::gen()
{
    double r, theta;
    std::uniform_real_distribution<> dis(0.0, 1.0);
    r = (stage.radius - PLAYER_SIZE) * sqrt(dis(seed));
    theta = 2 * M_PI * dis(seed);

    pos.x = r * sin(theta);
    pos.z = r * cos(theta);
}

void Food::draw()
{
    glPushMatrix();
        glTranslatef(pos.x, PLAYER_SIZE / 2 , pos.z);
        glutSolidSphere(PLAYER_SIZE / 2, 20, 20);
    glPopMatrix();
}
