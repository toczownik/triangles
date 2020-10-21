#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"

void drawTriangle() {
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    glVertex2f(100.0f, 0.0f);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glVertex2f(0.0f, 100.0f);
    glEnd();
}

void drawQuarter() {
    drawTriangle();
    glTranslated(0,100, 0);
    drawTriangle();
    glTranslated(0, 100, 0);
    drawTriangle();
    glTranslated(100, -100, 0);
    drawTriangle();
    glTranslated(0, -100, 0);
    drawTriangle();
    glTranslated(100, 0, 0);
    drawTriangle();
}

void MyDisplay() {
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    for (int i = 0; i < 4; ++i) {
        glRotated(90 * i, 0, 0, 100);
        drawQuarter();
        glLoadIdentity();
    }
    glFlush();
}

void MyInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(0, 0, 300, 300);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("My window");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}