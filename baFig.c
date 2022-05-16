#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdio.h>

float x1,x2,y3,y2;
int count = 0;

typedef struct pixel
{
	GLint x;
    GLint y;
}pixel;

pixel p[2];

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0,500,0,500);
}

void BA(float x1,float y1, float x2,float y2){
    float dx, dy, xinc, yinc , e,m,x,y;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    e = 2*dy -dx;
    if(x2>x1){
        xinc = 1;
    }else{
        xinc = -1;
    }
    if(y2>y1){
        yinc = 1;
    }else{
        yinc = -1;
    }
    if(x2!=x1){
    m = (y2-y1)/(x2-x1);
    }else{
        xinc = 0;
        m=-1;
    }
    if(m==0){
        yinc = 0;
    }
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
      glVertex2i(x,y);
    glEnd();
    if(m>=0){
        for(int i=0;i<dx;i++){
            if(e<=0){
              e= e+2*dy;
            }else{
                e= e+ 2*(dy-dx);
                y = y+ yinc;
            }
            x= x+xinc;
            if(i%5!=0){
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
            }
        }
    }else{
       for(int i=0;i<dy;i++){
            if(e<=0){
              e= e+2*dy;
            }else{
                e= e+ 2*(dy-dx);
                x = x+ xinc;
            }
            y= y+yinc;
            if(i%5!=0){
            glBegin(GL_POINTS);
            glVertex2i(x,y);
            glEnd();
            }
        }
    }
    glFlush();
}


void init_func(){
    BA(x1,y3,x1,y2);
    BA(x1,y2,x2,y2);
    BA(x2,y2,x2,y3);
    BA(x2,y3,x1,y3);

    float mid1 = (x2+x1)/2;
    float mid2 = (y2+y3)/2;

     BA(mid1,y3,x1,mid2);
    BA(x1,mid2,mid1,y2);
    BA(mid1,y2,x2,mid2);
    BA(x2,mid2,mid1,y3);

    float mid3= (mid1+x1)/2;
    float mid4 = (y3+mid2)/2;
    float mid5= mid3;
    float mid6 = (y2+mid2)/2;
    float mid7= (mid1+x2)/2;
    float mid8 = mid6;
    float mid9= mid7;
    float mid10 = mid4;

    BA(mid3,mid4,mid5,mid6);
    BA(mid5,mid6,mid7,mid8);
    BA(mid7,mid8,mid9,mid10);
    BA(mid9,mid10,mid3,mid4);


    glFlush();
}

int main(int argc, char **argv){
  printf("Enter the value of x1 : ");
	scanf("%f",&x1);
	printf("Enter the value of y3 : ");
	scanf("%f",&y3);
	printf("Enter the value of x2 : ");
	scanf("%f",&x2);
	printf("Enter the value of y2 : ");
	scanf("%f",&y2);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Pattern");
  init();
  glutDisplayFunc(init_func);
  glutMainLoop();
  return 0;
}