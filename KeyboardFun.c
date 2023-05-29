#include<GL/gl.h>
#include<GL/glut.h>
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.5,0);
    glVertex2f(-0.5,0);
    glVertex2f(0,0.5);
    glEnd();
    glFlush();

}
void key_fuction(unsigned char key, int x, int y){
    if(key=='a'){
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,0,1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.3,0);
        glVertex2f(-0.3,0);
        glVertex2f(0,0.3);
        glEnd();
        glFlush();
    }
    else if(key=='w'){
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1,1,0);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.5,0);
        glVertex2f(-0.5,0);
        glVertex2f(0,0.5);
        glEnd();
        glFlush();
    }
    else if(key=='d'){
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0,1,1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.7,0);
        glVertex2f(-0.7,0);
        glVertex2f(0,0.7);
        glEnd();
        glFlush();
    }
    
}
int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("CHANGE COLOR USING KEYBOARD");
    glutDisplayFunc(display);
    glutKeyboardFunc(key_fuction);
    glutMainLoop();
    return 0;
}