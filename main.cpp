#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <cmath>

#define SIZE 100
#define STRAIGHT_SPREAD (sqrt(2) * spread / 2)
#define X_MIDDLE_SPREAD (spread * 5 / 4)
#define Y_MIDDLE_SPREAD (spread / 4)
#define X_OUTER_SPREAD (spread * 9 / 4)
#define Y_OUTER_SPREAD Y_MIDDLE_SPREAD
#define INITIAL_OFFSET 25

int rotation = 0;
int spread = 0;
int spreadChange = 1;

void drawTriangle() {
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
    glVertex2f(-25.0f, -25.0f);
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
    glVertex2f(75.0f, -25.0f);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    glVertex2f(-25.0f, 75.0f);
    glEnd();
}

void drawInner() {
    glPushMatrix();
    glTranslated(INITIAL_OFFSET + STRAIGHT_SPREAD, INITIAL_OFFSET + STRAIGHT_SPREAD, 0);
    glRotated(rotation, 0, 0, 100);
    drawTriangle();
    glPopMatrix();
}

void drawMiddle() {
    glPushMatrix();
    glTranslated(INITIAL_OFFSET + Y_MIDDLE_SPREAD, INITIAL_OFFSET + SIZE + X_MIDDLE_SPREAD, 0);
    glRotated(rotation, 0, 0, 100);
    drawTriangle();
    glPopMatrix();
    glPushMatrix();
    glTranslated(INITIAL_OFFSET + SIZE + X_MIDDLE_SPREAD, INITIAL_OFFSET + Y_MIDDLE_SPREAD, 0);
    glRotated(rotation, 0, 0, 100);
    drawTriangle();
    glPopMatrix();
}

void drawOuter() {
    glPushMatrix();
    glTranslated(INITIAL_OFFSET + Y_OUTER_SPREAD, INITIAL_OFFSET + 2 * SIZE + X_OUTER_SPREAD, 0);
    glRotated(rotation, 0, 0, 100);
    drawTriangle();
    glPopMatrix();
    glPushMatrix();
    glTranslated(INITIAL_OFFSET + SIZE + 2 * STRAIGHT_SPREAD, INITIAL_OFFSET + SIZE + 2 * STRAIGHT_SPREAD, 0);
    glRotated(rotation, 0, 0, 100);
    drawTriangle();
    glPopMatrix();
    glTranslated(INITIAL_OFFSET + 2 * SIZE + X_OUTER_SPREAD, INITIAL_OFFSET + Y_OUTER_SPREAD, 0);
    glRotated(rotation, 0, 0, 100);
    drawTriangle();
    glPopMatrix();
}

void update(int) {
    rotation += 1;
    if (rotation >= 360) {
        rotation = -360;
    }
    spread += spreadChange;
    if (spread > 180 || spread < 0) {
        spreadChange = -spreadChange;
    }
    glutPostRedisplay();
}

void MyDisplay() {
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        glRotated(90 * i + rotation, 0, 0, 100);
        drawInner();
        drawOuter();
        glPopMatrix();
        glPushMatrix();
        glRotated(-90 * i - rotation, 0, 0, 100);
        drawMiddle();
        glPopMatrix();
    }
    glFlush();
    glutTimerFunc(25, update, 0);
}

void MyInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glViewport(0, 0, 500, 500);
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
