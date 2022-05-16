#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdio.h>
#include <math.h>


float mat1[3][3];
float ans1[3][3];
float trans1[3][3];
int ch = 1;

void storeCoordinates(){
    mat1[0][0]=150;
    mat1[0][1]= 150;
    mat1[1][0]=350;
    mat1[1][1] = 150;
    mat1[2][0] = 250;
    mat1[2][1]= 300;
    for(int i=0;i<3;i++){
        mat1[i][2]=1;
    }
}
void drawOriginal(){
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
           glVertex2f(mat1[i][0],mat1[i][1]);
    }
    glEnd();
    glFlush();
}
void translate(){
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
	trans1[2][0]=trans1[2][1]=150;
    for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans1[i][j]=0;
			for(int k=0;k<3;k++)
				ans1[i][j]+=mat1[i][k]*trans1[k][j];
		}
	}
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
           glVertex2f(ans1[i][0],ans1[i][1]);
    }
    glEnd();
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
	trans1[2][0]=-225;
    trans1[2][1]=-250;
    for(int i=0;i<3;i++)
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

    for(int i=0;i<3;i++)
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
	trans1[2][0]=320;
    trans1[2][1]=320;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans1[i][j]=0;
			for(int k=0;k<3;k++)
				ans1[i][j]+=mat1[i][k]*trans1[k][j];
		}
	}

    glBegin(GL_LINE_LOOP);
  for(int i=0;i<3;i++){
      glVertex2f(ans1[i][0],ans1[i][1]);    
  }
  glEnd();
  glFlush();
}

void scale(){
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
	trans1[0][0]=1.25;
    trans1[1][1]=1.25;
    for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans1[i][j]=0;
			for(int k=0;k<3;k++)
				ans1[i][j]+=mat1[i][k]*trans1[k][j];
		}
	}
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
           glVertex2f(ans1[i][0],ans1[i][1]);
    }
    glEnd();
    glFlush();


}
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//to set background color
    glClear(GL_COLOR_BUFFER_BIT);//to apply back ground color to screen
    glColor3f(0.0, 0.0, 0.0);//to set color of object to be shown on screen
	gluOrtho2D(0,500,0,500);
}

void mouse_click(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)//if left click 
	{
		switch(ch)
		{
			//for selecting vertex in polygon to fill
			case 1:
                storeCoordinates();
                drawOriginal();
				ch=2;
				break;
			//for selecting color in color pallette 
			case 2:
                translate();
				ch=3;
				break;
            case 3:
                storeCoordinates();
                rotate();
                storeCoordinates();
                drawOriginal();
                ch=4;
                break;
            case 4:
                storeCoordinates();
                scale();
                drawOriginal();
                ch=5;
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
	glutCreateWindow ("2D Transformations");
	init();
	glutDisplayFunc(init_func);//displays the function
    glutMouseFunc(mouse_click);//to display before and after figures
    glutMainLoop();//keeps the program open until closed
 
	return 0;
}