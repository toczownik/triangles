#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"

void MyDisplay(void) {
    // The new scene
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);// OpenGLa state
    glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//Red;
    glVertex2f(100.0f, 50.0f);
    glColor4f(0.0f, 1.0f, 0.0f, 1.0f);//Green
    glVertex2f(450.0f, 400.0f);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);//Blue
    glVertex2f(450.0f, 50.0f);
    glEnd();
    // The end of scene
    glFlush();//start processing buffered OpenGL routines
}
void MyInit(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);//select clearing (background) color
    /* initialize viewing values */
    glViewport(0, 0, 300, 300);//window origin and size
    glMatrixMode(GL_PROJECTION);//
    glLoadIdentity();//=1
    gluOrtho2D(0.0, 500.0*1.2, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();//=1
}

int main(int argc, char** argv) { //<- for normal API
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//single buffer and RGBA
    glutInitWindowSize(250, 250);//initial window size
    glutInitWindowPosition(100, 100);
    glutCreateWindow("My window");//create widnow, hello title bar
    MyInit();
    glutDisplayFunc(MyDisplay);//
    glutMainLoop();//enter main loop and process events
    return 0;
}