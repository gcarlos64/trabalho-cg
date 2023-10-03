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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    player.commitCamera();

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

    player.printScore();

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

    GLfloat ambientLight[4]  = { 0.2, 0.2, 0.2, 0.0 };
    GLfloat difuseLight[4]   = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat specularLight[4] = { 0.6, 0.6, 0.6, 0.0 };
    GLfloat lightPos[4]      = { 0.0, VIEW_RANGE / 2, 0.0, 0.0 };

    glShadeModel(GL_SMOOTH);

    GLint materialShininess = 100;
    GLfloat materialSpecularity[4]  = { 0.5, 0.5, 0.7, 0.0 };
    GLfloat materialDifusebility[4] = { 0.5, 0.5, 0.5, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecularity);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDifusebility);
    glMateriali(GL_FRONT, GL_SHININESS, materialShininess);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight); 
    glLightfv(GL_LIGHT0, GL_DIFFUSE, difuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Snake3D");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(50, gameLoop, 0);

    init();

    glutMainLoop();
}
