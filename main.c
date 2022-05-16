#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdio.h>

double x1,x2,y3,y2;

typedef struct pixel
{
	float r,g,b;
}pixel;
pixel f_clr,b_clr;

void dda(double x1,double y3,double x2,double y2)
{
	double dx,dy,steps;
	float xi,yi;
	dx=x2-x1;
	dy=y2-y3;
	steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
	xi=dx/(float)steps;
	yi=dy/(float)steps;
	int i;
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2d(x1,y3);
	for(i=0;i<steps;i++)
	{
		x1+=xi;
		y3+=yi;
		glVertex2d(x1,y3);//function to print one pixel
	}
	glEnd();
	glFlush();
}

void boundary_fill(int x,int y)
{
	pixel c;
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,&c);
	if((c.r!=b_clr.r||c.g!=b_clr.g||c.b!=b_clr.b)&&(c.r!=f_clr.r||c.g!=f_clr.g||c.b!=f_clr.b))
	{
		glBegin(GL_POINTS);
		glColor3f(f_clr.r,f_clr.g,f_clr.b);
		glVertex2i(x,y);
		glEnd();
		glFlush();
		boundary_fill(x-1,y);
		boundary_fill(x+1,y);
		boundary_fill(x,y-1);
		boundary_fill(x,y+1);
	}
	glFlush();
}
void renderFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);
   dda(100,400,400,400);
    dda(100,450,400,450);
    dda(100,400,100,450);
    dda(400,400,400,450);

    f_clr.r=1.0f;
    f_clr.g=0.0f;
    f_clr.b=0.0f;
    boundary_fill(150,410);
     b_clr.r=0.0f;
    b_clr.g=0.0f;
    b_clr.b=0.0f;
    glFlush();
  }

void init()
{
	  glClearColor(1.0, 1.0, 1.0, 0.0);//to set background color
    glClear(GL_COLOR_BUFFER_BIT);//to apply back ground color to screen
    glColor3f(0.0, 0.0, 0.0);//to set color of object to be shown on screen
    gluOrtho2D(0,500,0,500);//to set 2D projection rectangle
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL - First window demo");
    init();
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}

//g++ main.c -lglut -lGL -lGLEW -lGLU -o OpenGLExample
//./OpenGLExample
