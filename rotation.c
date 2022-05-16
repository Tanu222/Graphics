#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdio.h>
#include <math.h>

float mat1[12][3];
float ans1[12][3];
float trans1[3][3];
int ch = 1;

typedef struct pixel
{
	float r,g,b;
}pixel;
pixel f_clr,b_clr;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//to set background color
    glClear(GL_COLOR_BUFFER_BIT);//to apply back ground color to screen
    glColor3f(0.0, 0.0, 0.0);//to set color of object to be shown on screen
	gluOrtho2D(0,500,0,500);
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

void initFig(){
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0;i<12;i++){
        for(int j=0;j<3;j++){
            mat1[i][j]=0;
        }
    }
  mat1[0][0]= 200;
  mat1[0][1]= mat1[1][1] = 400;
  mat1[1][0]= 300;
  mat1[2][1] = mat1[3][1] = mat1[10][1] = mat1[11][1] = 300;
  mat1[2][0]= 300;
  mat1[3][0]= 400;
  mat1[10][0]= 100;
  mat1[11][0]= 200;
  mat1[4][1] = mat1[5][1] = mat1[8][1] = mat1[9][1] =200;

  mat1[5][0]= 300;
  mat1[4][0]= 400;
  mat1[9][0]= 100;
  mat1[8][0]= 200;

  mat1[7][0]= 200;
  mat1[7][1]= mat1[6][1] = 100;
  mat1[6][0]= 300;
  for(int i=0;i<12;i++){
      mat1[i][2] = 1;
  }
  glBegin(GL_LINE_LOOP);
  for(int i=0;i<11;i++){
      glVertex2f(mat1[i][0],mat1[i][1]);
      glVertex2f(mat1[i+1][0],mat1[i+1][1]);    
  }
  glEnd();
  glFlush();
  f_clr.r=0.0f;
  f_clr.g=0.0f;
  f_clr.b=1.0f;
  boundary_fill(251,251);
  b_clr.r=0.0f;
  b_clr.g=0.0f;
  b_clr.b=0.0f;
  glFlush();
}

void rotate(){
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
				trans1[i][j]=1;
			else
				trans1[i][j]=0;
		}
	}
	trans1[2][0]=trans1[2][1]=-250;
    for(int i=0;i<12;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans1[i][j]=0;
			for(int k=0;k<3;k++)
				ans1[i][j]+=mat1[i][k]*trans1[k][j];
		}
	}


    float theta;
	theta=45*3.14/180;

    for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
				trans1[i][j]=1;
			else
				trans1[i][j]=0;
		}
	}
	
	trans1[0][0]=trans1[1][1]=cos(theta);
	trans1[0][1]=sin(theta);
	trans1[1][0]=-sin(theta);

    for(int i=0;i<20;i++)
	{
		for(int j=0;j<3;j++)
		{
			mat1[i][j]=0;
			for(int k=0;k<3;k++)
				mat1[i][j]+=ans1[i][k]*trans1[k][j];
		}
	}


    for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
				trans1[i][j]=1;
			else
				trans1[i][j]=0;
		}
	}
	trans1[2][0]=trans1[2][1]=250;
	
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans1[i][j]=0;
			for(int k=0;k<3;k++)
				ans1[i][j]+=mat1[i][k]*trans1[k][j];
		}
	}
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
  for(int i=0;i<11;i++){
      glVertex2f(ans1[i][0],ans1[i][1]);
      glVertex2f(ans1[i+1][0],ans1[i+1][1]);    
  }
  glEnd();
  glFlush();
  f_clr.r=0.0f;
  f_clr.g=0.0f;
  f_clr.b=1.0f;
  b_clr.r=0.0f;
  b_clr.g=0.0f;
  b_clr.b=0.0f;
  boundary_fill(251,300);
  glFlush();

}

void mouse_click(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)//if left click 
	{
		switch(ch)
		{
			//for selecting vertex in polygon to fill
			case 1:
				initFig();
				ch=2;
				break;
			//for selecting color in color pallette 
			case 2:
				rotate();
				ch=3;
				break;
		}
	}
}

void init_func()//empty function doesnt do anything
{
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
    glutMouseFunc(mouse_click);//to display before and after figures
    glutMainLoop();//keeps the program open until closed
 
	return 0;
}