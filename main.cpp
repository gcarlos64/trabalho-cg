#include <cmath>
#include <GL/glut.h>
#include "Food.h"
#include "global.h"
#include "Player.h"

Player player;
Stage stage(500.0, 100);
Food food;

void display()
{
    player.commitCamera();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.1, 0.7, 0.2);
    stage.draw();

    glColor3f(0.0, 0.2, 1.0);
    player.draw();

    glColor3f(1.0, 0.7, 0.0);
    food.draw();

    glColor3f(1.0, 0.2, 0.0);
    glPushMatrix();
        glTranslated(100, 0, -100);
        glutWireTeapot(50.0);
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'k':
        player.incTheta(0.1);
        break;
    case 'l':
        player.incTheta(-0.1);
        break;
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void gameLoop(int val)
{
    player.move();
    glutPostRedisplay();
    glutTimerFunc(16.6, gameLoop, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Snake3D");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(50, gameLoop, 0);

    init();

    glutMainLoop();
}
