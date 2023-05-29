#include <stdio.h>
#include <GL/freeglut.h>

#define WIDTH 640
#define HEIGHT 480

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void floodFill(int x, int y, float *fillColor, float *oldColor)
{
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
    if (color[0] == oldColor[0] && color[1] == oldColor[1] && color[2] == oldColor[2])
    {
        glColor3f(fillColor[0], fillColor[1], fillColor[2]);
        setPixel(x, y);
        glFlush();
        floodFill(x + 1, y, fillColor, oldColor);
        floodFill(x - 1, y, fillColor, oldColor);
        floodFill(x, y + 1, fillColor, oldColor);
        floodFill(x, y - 1, fillColor, oldColor);
    }
}

void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float fillColor[3] = {0.0, 1.0, 1.0};
        float oldColor[3] = {0.0, 0.0, 0.0};
        floodFill(x, HEIGHT - y, fillColor, oldColor);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 100);
    glVertex2i(100, 250);
    glVertex2i(250, 250);
    glVertex2i(250, 100);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Flood Filling");
    init();
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}