#include <GL/freeglut.h>
#include <math.h>
#define WIDTH 500
#define HEIGHT 580
int x = 50, y = 50;
int x2 = 150, y2 = 50;
int x3 = 150, y3 = 150;
int x4 = 50, y4 = 150;
char operation;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 640, 0, 480);
}
void resetDisplay()
{
    x = 50;
    y = 50;
    x2 = 150;
    y2 = 50;
    x3 = 150;
    y3 = 150;
    x4 = 50;
    y4 = 150;
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
void scale(float sx, float sy)
{
    int tempX = x, tempY = y;
    inverseTranslate(tempX, tempY);
    x *= sx;
    y *= sy;
    x2 *= sx;
    y2 *= sy;
    x3 *= sx;
    y3 *= sy;
    x4 *= sx;
    y4 *= sy;
    translate(tempX, tempY);
}
void inverseScale(float sx, float sy)
{
    scale(1 / sx, 1 / sy);
}
void keyy(unsigned char key, int x, int y)
{
    operation = key;
    switch (operation)
    {
    case 's':
        scale(1.1, 1.1);
        break;
    case 'S':
        inverseScale(1.1, 1.1);
        break;
    case 'r':
        resetDisplay();
        break;

    glutPostRedisplay();
}}
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