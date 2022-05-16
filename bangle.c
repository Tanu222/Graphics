#include<GL/freeglut.h>
#include<stdio.h>
#include<GL/glut.h>
#include <math.h>
#define PI 3.14235

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0,500,0,500);
}

void plotpixel(int xc,int yc, int x, int y){
    glBegin(GL_POINTS);
     glVertex2i(xc+x,yc+y);
     glVertex2i(xc-x,yc+y);
     glVertex2i(xc+x,yc-y);
     glVertex2i(xc-x,yc-y);
     glVertex2i(xc+y,yc+x);
     glVertex2i(xc-y,yc+x);
     glVertex2i(xc+y,yc-x);
     glVertex2i(xc-y,yc-x);
    glEnd();
}
void circle(int xc, int yc, int r){
int x = 0;
int y = r;
int d = 3- 2*r;
plotpixel(xc,yc,x,y);
while(x<=y){
    x++;
if(d<=0){
    d = d+4*x+6;
}else{
    d = d+ 10 + 4*(x-y);
    y=y-1;
}
plotpixel(xc,yc,x,y);
}
}

void display1(int cx, int cy, int radius){
  circle(cx,cy,radius);
  circle(cx,cy,radius-10);
  int j = 0;
  while(j<=90){
    circle((cx+(radius+15)*cos(PI/180*j)),(cy+(radius+15)*sin(PI/180*j)),15);
    j+=15;
  }
   j = 0;
  while(j<=90){
    circle((cx-(radius+15)*cos(PI/180*j)),(cy-(radius+15)*sin(PI/180*j)),15);
    j+=15;
  }
   j = 0;
  while(j<=90){
    circle((cx+(radius+15)*cos(PI/180*j)),(cy-(radius+15)*sin(PI/180*j)),15);
    j+=15;
  }
   j = 0;
  while(j<=90){
    circle((cx-(radius+15)*cos(PI/180*j)),(cy+(radius+15)*sin(PI/180*j)),15);
    j+=15;
  }
}

void init_func(){
    display1(200,200,100);
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Bangle");
    init();
    glutDisplayFunc(init_func);
    glutMainLoop();
    return 0;
}