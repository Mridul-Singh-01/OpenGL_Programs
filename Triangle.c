#include <GL/gl.h>
#include <GL/glut.h>
void display()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(-0.8, -0.8);
    glColor3f(1, 0, 0);
    glVertex2f(0.8, -0.8);
    glColor3f(1, 0, 0);
    glVertex2f(0, 0.9);
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mridul");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}