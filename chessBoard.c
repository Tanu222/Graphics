#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdio.h>
#include <math.h>

float mat1[20][3];
float ans1[20][3];
float trans1[3][3];
int ch = 1;

typedef struct pixel
{
	float r,g,b;
}pixel;
pixel f_clr,b_clr;

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

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);//to set background color
    glClear(GL_COLOR_BUFFER_BIT);//to apply back ground color to screen
    glColor3f(0.0, 0.0, 0.0);//to set color of object to be shown on screen
	gluOrtho2D(0,500,0,500);
}

void initalFigure(){
    int temp = 50;
    for(int i=0;i<10;i+=2){
       mat1[i][0]= 50;
       mat1[i][1]= temp;
       mat1[i+1][0] = 210;
       mat1[i+1][1] = temp;
       temp = temp+40;
    }
    temp = 50;
    for(int i=10;i<20;i+=2){
        mat1[i][0]= temp;
       mat1[i][1]= 50;
       mat1[i+1][0] = temp;
       mat1[i+1][1] = 210;
       temp = temp+40;
    }
    glBegin(GL_LINES);
    for(int i=0;i<20;i+=2){
        glVertex2f(mat1[i][0],mat1[i][1]);
        glVertex2f(mat1[i+1][0],mat1[i+1][1]);
    }
    glEnd();
    glFlush();
    f_clr.r=0.5f;
    f_clr.g=0.1f;
    f_clr.b=0.1f;
    b_clr.r=0.0f;
    b_clr.g=0.0f;
    b_clr.b=0.0f;
    boundary_fill(71,71);
    glFlush();

}

void init_func()//empty function doesnt do anything
{
    initalFigure();
    glFlush();
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Chess board");
	init();
	glutDisplayFunc(init_func);//displays the function
    //glutMouseFunc(mouse_click);//to display before and after figures
    glutMainLoop();//keeps the program open until closed
 
	return 0;
}