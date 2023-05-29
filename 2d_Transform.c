#include <GL/freeglut.h>
#include <math.h>
#define WIDTH 500
#define HEIGHT 580
int x = 150, y = 150;
int x2 = 250, y2 = 150;
int x3 = 250, y3 = 250;
int x4 = 150, y4 = 250;
char operation;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}
void draw()
{
    glBegin(GL_LINE_LOOP);
    glVertex2i(x, y);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);
    glEnd();
}
void translate(int tx, int ty)
{
    x += tx;
    y += ty;
    x2 += tx;
    y2 += ty;
    x3 += tx;
    y3 += ty;
    x4 += tx;
    y4 += ty;
}
void inverseTranslate(int tx, int ty)
{
    x -= tx;
    y -= ty;
    x2 -= tx;
    y2 -= ty;
    x3 -= tx;
    y3 -= ty;
    x4 -= tx;
    y4 -= ty;
}
void resetDisplay()
{
    x = 150;
    y = 150;
    x2 = 250;
    y2 = 150;
    x3 = 250;
    y3 = 250;
    x4 = 150;
    y4 = 250;
}
void keyy(unsigned char key, int x, int y)
{
    operation = key;
    switch (operation)
    {
    case 't':
        translate(10, 10);
        break;
    case 'T':
        inverseTranslate(10, 10);
        break;
    case 'r':
        resetDisplay();
        break;
    }

    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    draw();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Transformations");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyy);
    glutMainLoop();
    return 0;
}