#include<GL/glut.h>
#include<GL/glu.h>

void display();
float mat1[3][3];
float ans1[3][3];
float trans1[3][3];

int state = 1;
void timer(int);
float scaling=1.0;

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

void scale(){
   storeCoordinates();
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
	trans1[0][0]=scaling;
    trans1[1][1]=scaling;
    for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans1[i][j]=0;
			for(int k=0;k<3;k++)
				ans1[i][j]+=mat1[i][k]*trans1[k][j];
		}
	}
    for(int i=0;i<3;i++){
        mat1[i][0] = ans1[i][0];
        mat1[i][1] = ans1[i][1];
        mat1[i][2] = 1;
    }
}
void display()
{

  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  scale();
  glBegin(GL_LINE_LOOP);
    for(int i=0;i<3;i++){
           glVertex2f(mat1[i][0],mat1[i][1]);
    }
    glEnd();
    glFlush();
  glutSwapBuffers();

}
void timer(int n)
{
    storeCoordinates();
glutPostRedisplay();   //redisplay of display
glutTimerFunc(1000/10, timer,0);
/*if(xposition<8)
{
     xposition+=0.15;
 }*/
 
 
 switch(state)
 {
   case 1:
        if(scaling<1.5)
        {
            scaling = scaling + 0.2;
         }
         else
           state=-1;
           break;
     case -1:
         if(scaling>0.5)
            scaling = scaling - 0.2;
          else
            state=1;
            break;

}
}

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glColor3f(0.0,0.0,0.0);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Animation");
    glutDisplayFunc(display);
    glutTimerFunc(1000,timer,0);
    init();
    glutMainLoop();
    return 0;
}