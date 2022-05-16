#include<GL/freeglut.h>
#include<GL/glut.h>
#include<stdio.h>

void initialize(){
   glClearColor(1.0, 1.0, 1.0, 0.0);//to set background color
    glClear(GL_COLOR_BUFFER_BIT);//to apply back ground color to screen
    glColor3f(0.0, 0.0, 0.0);//to set color of object to be shown on screen
	gluOrtho2D(0,500,0,500);
}

void dda(int x1,int y1, int x2,int y2){
    float dx,dy,step,xinc,yinc;
    int m=0;
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>=abs(dy)){
       step = abs(dx); 
    }else{
        step = abs(dy);
    }
    xinc = dx/(float)step;
    yinc = dy/(float)step;
    float x = x1;
    float y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x1,y1);
    glEnd();
    for(int i=0;i<step;i++){
      x = x+ xinc;
      y = y+ yinc;
      int k = m%20;
      if(k%9!=0&&k%10!=0&&k%11!=0&&k%12!=0&&k%16!=0&&k%17!=0&&k%18!=0&&k%19!=0){
        glPointSize(2.0);
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
      }
      m++;

    }
    glFlush();

}

void init(){
    dda(20,20,200,200);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Dashed Lines");
    initialize();
    glutDisplayFunc(init);
    glutMainLoop();
    return 0;
}