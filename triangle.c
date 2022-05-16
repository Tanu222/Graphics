#include <GL/freeglut.h>
#include <GL/gl.h>

void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(5);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_LINE_LOOP);
      glVertex2f(-0.3, -0.3);
      glVertex2f(0,0.3);
      glVertex2f(0.3,-0.3);
    glEnd();
    glBegin(GL_LINE_LOOP);
      glVertex2f(-0.3,-0.3);
      glVertex2f(0.9,-0.3);
      glVertex2f(0.9,-0.8);
      glVertex2f(-0.3,-0.8);
    glEnd();
    glBegin(GL_LINE_STRIP);
      glVertex2f(0,0.3);
      glVertex2f(0.6,0.3);
      glVertex2f(0.9,-0.3);
      glVertex2f(0.3,-0.3);
    glEnd();
    glBegin(GL_LINES);
      glVertex2f(0.3,-0.3);
      glVertex2f(0.3,-0.8);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}

//g++ triangle.c -lglut -lGL -lGLEW -lGLU -o OpenGLExample
//./OpenGLExample