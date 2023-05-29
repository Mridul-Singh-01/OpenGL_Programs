#include <GL/freeglut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glBegin(GL_POINTS);
    int x,y,r,pk;
    x=0;
    r=8;
    y=r;

    pk=3-2*r;
    while(x<=y){
        if(pk<0){
            pk=pk+4*x+6;
            x=x+1;
            y=y;
        }
        else if(pk>=0){
            pk=pk+4*(x-y)+10;
            x=x+1;
            y=y-1;
        }
        glVertex2f(x,y);
        glVertex2f((-x),y);
        glVertex2f((-x),(-y));
        glVertex2f(x,(-y));
        glVertex2f(y,x);
        glVertex2f((-y),x);
        glVertex2f((-y),(-x));
        glVertex2f(y,(-x));
    }
    glEnd();
    glFlush();

}
int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,300);
    glutCreateWindow("Circle Drawing using BRENSENHEM algorithm");
    gluOrtho2D(-25,25,-25,25);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}