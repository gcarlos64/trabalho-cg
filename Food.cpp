#include "Food.h"
#include "Player.h"
#include "global.h"
#include <random>
#include <GL/glut.h>

std::random_device rd;
std::mt19937 seed(rd());

Food::Food()
{
    gen();
}

void Food::gen()
{
    std::uniform_int_distribution<> xdis(stage.xrange.begin + PLAYER_SIZE / 2,
                                         stage.xrange.end + PLAYER_SIZE / 2);
    x = xdis(seed);

    std::uniform_int_distribution<> zdis(stage.zrange.begin + PLAYER_SIZE / 2,
                                         stage.zrange.end + PLAYER_SIZE / 2);
    z = zdis(seed);
}

void Food::draw()
{
    glPushMatrix();
        glTranslatef(x, PLAYER_SIZE / 2 , z);
        glutSolidSphere(PLAYER_SIZE / 2, 20, 20);
    glPopMatrix();
}
