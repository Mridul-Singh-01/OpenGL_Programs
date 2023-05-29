#include <GL/freeglut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 0.5);
    glVertex2f(0.5, 0);
    glVertex2f(-0.5, 0);
    glEnd();
    glFlush();
}
void mousee(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1, 0, 1);
        glBegin(GL_TRIANGLES);
        glVertex2f(0, 0.5);
        glVertex2f(0.5, 0);
        glVertex2f(-0.5, 0);
        glEnd();
        glFlush();
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Color change on mouse click");
    glutDisplayFunc(display);
    glutMouseFunc(mousee);
    glutMainLoop();
    return 0;
}