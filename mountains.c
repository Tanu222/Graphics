#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdio.h>

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

void dda(int x1, int y1,int x2, int y2){
    float dy,dx,step,x,y,Xin,Yin;
        int k,m;
	dx=x2-x1;
	dy=y2-y1;
 
	if(abs(dx)> abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
 
	Xin = dx/(float)step;
	Yin = dy/(float)step;
 
	x= x1;
	y=y1;
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
 
	for (k=1 ;k<=step;k++)
	{
		x= x + Xin;
		y= y + Yin;
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
	}
    glFlush();
}

void rectangle(){
    glClear(GL_COLOR_BUFFER_BIT);
   dda(100,100,200,100);
    dda(200,100,170,75);
    dda(170,75,330,75);
    dda(330,75,300,100);
    dda(300,100,400,100);
    dda(100,100,100,300);
    dda(100,300,400,300);
    dda(400,300,400,100);
    dda(125,125,375,125);
    dda(125,125,125,275);
    dda(125,275,375,275);
    dda(375,275,375,125);
    dda(125,125,200,200);
    dda(200,200,250,125);
    dda(250,125,300,250);
    dda(300,250,375,125);
    glFlush();
    f_clr.r=1.0f;
    f_clr.g=0.0f;
    f_clr.b=0.0f;
    boundary_fill(101,101);
    f_clr.r=0.0f;
    f_clr.g=1.0f;
    f_clr.b=0.0f;
    boundary_fill(300,200);
    f_clr.r=0.0f;
    f_clr.g=1.0f;
    f_clr.b=0.0f;
    boundary_fill(134,132);
    b_clr.r=0.0f;
    b_clr.g=0.0f;
    b_clr.b=0.0f;
    glFlush();
    
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//to set background color
    glClear(GL_COLOR_BUFFER_BIT);//to apply back ground color to screen
    glColor3f(0.0, 0.0, 0.0);//to set color of object to be shown on screen
	gluOrtho2D(0,500,0,500);
}

void init_func()//empty function doesnt do anything
{
rectangle();
 b_clr.r=0.0f;
 b_clr.g=0.0f;
 b_clr.b=0.0f;
glFlush();
}
 
int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Line Clipping");
	init();
	glutDisplayFunc(init_func);//displays the function
    // glutMouseFunc(mouse_click);//to display before and after figures
    glutMainLoop();//keeps the program open until closed
 
	return 0;
}
