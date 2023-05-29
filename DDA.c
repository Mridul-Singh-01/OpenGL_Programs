#include<GL/glut.h>
#include<math.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    glBegin(GL_LINES);
    double x1=0;
    double y1=0;
    double x2=4;
    double y2=8;
    double m=(y2-y1)/(x2-x1);
    double xk,yk;
    xk=x1;
    yk=y1;
    glVertex2f(round(xk),round(yk));
    while(xk!=x2 && yk!=y2){
        if(m>1){
            xk=(xk+(1/m));
            yk=yk+1;
        }
        if(m<1){
            xk=xk+1;
            yk=yk+m;
        }
        if(m==1){
            xk=xk+1;
            yk=yk+1;
        }
        glVertex2f(round(x2),(y2));
    }
    glEnd();
    glFlush();

}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,300);
    glutCreateWindow("Line drawing using DDA algorithm");
    gluOrtho2D(-10, 10, -10, 10);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}