#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float x1,x2,y3,y2;
int c;
 
void display(void)
{
	float dy,dx,step,x,y,Xin,Yin; 
        int k,m;
        if(c==1){
         m=1;
        }else if(c==2){
         m=3;
        }else if(c==3){
         m=5;
        }
	dx=x2-x1;
	dy=y2-y3;
 
	if(abs(dx)> abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
 
	Xin = dx/step;
	Yin = dy/step;
 
	x= x1;
	y=y3;
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
 
	for (k=1 ;k<=step;k++)
	{
		x= x + Xin;
		y= y + Yin;
                if(k%m==0){
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
               }
	}
 
 
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
	printf("Enter the value of x1 : ");
	scanf("%f",&x1);
	printf("Enter the value of y3 : ");
	scanf("%f",&y3);
	printf("Enter the value of x2 : ");
	scanf("%f",&x2);
	printf("Enter the value of y2 : ");
	scanf("%f",&y2);
    printf("Enter 1 for solid line \n");
    printf("Enter 2 for dashed line \n");
    printf("Enter 3 for dotted line \n");
        printf("Enter your choice: ");
        scanf("%d",&c);
 
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100,100);
	glutCreateWindow ("DDA Line Algo");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
 
	return 0;
}
