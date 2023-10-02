#include <GL/glut.h>
#include <math.h>

#include "Player.h"
#include "global.h"

Player player;
Stage stage = Stage({
    Point(0.0, 0.0, 300.0),
    Point(600.0, 0.0, 300.0),
    Point(600.0, 0.0, -300.0),
    Point(0.0, 0.0, -300.0),
});

void display()
{
    player.commitCamera();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.1, 0.7, 0.2);
    stage.draw();
    /*
    glBegin(GL_QUADS);
        glNormal3f(1.0, 0.0, 0.0);
        glVertex3f(200.0, 0, 0.0);
        glVertex3f(200.0, 5.0, 0.0);
        glVertex3f(200.0, 5.0, -200.0);
        glVertex3f(200.0, 0.0, -200.0);
    glEnd();
    */
    glColor3f(0.0, 0.2, 1.0);
    player.draw();

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
    glutTimerFunc(50, gameLoop, 0);
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
