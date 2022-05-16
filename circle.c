#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float xc,yc,radius;

void setPixel(int x,int y)
{
  glBegin(GL_POINTS);
    glVertex2i(x,y);
  glEnd();
}

//To plot in 8 octants
void plotPixel(int xc,int yc,int x,int y) 
{
  setPixel(xc+x, yc+y);
  setPixel(xc-x, yc+y);
  setPixel(xc+x, yc-y);
      setPixel(xc-x, yc-y);
      setPixel(xc+y, yc+x);
      setPixel(xc-y, yc+x);
      setPixel(xc+y, yc-x);
      setPixel(xc-y, yc-x);
}

// Bresenham’s circle drawing algorithm:
void drawCircle(int xc,int yc,int r){
  int x=0,y=r;
  int d = 3-2*r;

  // First point plot in 8 octants
  plotPixel(xc,yc,x,y); 
  while(x<=y)
  {
    
    x++;
    if(d<=0)
    {
      d=d+4*x+6;
      y=y;
    }
    else
    {
      d=d+4*(x-y)+10;
      y=y-1;
    }
    plotPixel(xc,yc,x,y);
  }
}

void display(void)
{
    drawCircle(xc,yc,radius);
  drawCircle(xc,yc,2*radius);
  
  drawCircle(xc+(radius/sqrt(2)),yc+(radius/sqrt(2)),radius);
      drawCircle(xc+(radius/sqrt(2)),yc-(radius/sqrt(2)),radius);
      drawCircle(xc-(radius/sqrt(2)),yc+(radius/sqrt(2)),radius);
      drawCircle(xc-(radius/sqrt(2)),yc-(radius/sqrt(2)),radius);
      drawCircle(xc+radius,yc,radius);
      drawCircle(xc-radius,yc,radius);
      drawCircle(xc,yc-radius,radius);
      drawCircle(xc,yc+radius,radius);
	glFlush();
}
 

void init(void)
{
	glClearColor(0.7,0.7,0.7,0.7);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}
 
int main(int argc, char** argv) 
{
	printf("Enter the value of xc : ");
	scanf("%f",&xc);
	printf("Enter the value of yc : ");
	scanf("%f",&yc);
	printf("Enter the value of r : ");
	scanf("%f",&radius);
 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("Bresenhams Circle Algo");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
 
	return 0;
}
