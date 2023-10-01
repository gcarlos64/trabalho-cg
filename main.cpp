#include <GL/glut.h>
#include <math.h>

#include "Player.h"

#define WIDTH 800
#define HEIGHT 600

Player player;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
        glTranslated(100, 0, -100);
        glutWireTeapot(50.0);
    glPopMatrix();

    player.draw();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
        player.move(1.0, 0.0);
        break;
    case 'a':
        player.move(1.0, M_PI / 2);
        break;
    case 's':
        player.move(1.0, M_PI);
        break;
    case 'd':
        player.move(1.0, -M_PI / 2);
        break;
    case 'k':
        player.incTheta(0.1);
        break;
    case 'l':
        player.incTheta(-0.1);
        break;
    }

    player.commitCamera();
    glutPostRedisplay();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    player.commitCamera();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("The Hardest Game 3D");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();
}
