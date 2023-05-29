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

void rotate(float angle)
{
    int tempX = x, tempY = y;
    inverseTranslate(tempX, tempX);
    angle = angle * 3.14 / 180;
    x = x * cos(angle) - y * sin(angle);
    y = x * sin(angle) + y * cos(angle);
    x2 = x2 * cos(angle) - y2 * sin(angle);
    y2 = x2 * sin(angle) + y2 * cos(angle);
    x3 = x3 * cos(angle) - y3 * sin(angle);
    y3 = x3 * sin(angle) + y3 * cos(angle);
    x4 = x4 * cos(angle) - y4 * sin(angle);
    y4 = x4 * sin(angle) + y4 * cos(angle);
    translate(tempX, tempY);
}
void inverseRotate(float angle)
{
    rotate(-angle);
}
void keyy(unsigned char key, int x, int y)
{
    operation = key;
    switch (operation)
    {
    case 'r':
        rotate(10);
        break;
    case 'R':
        inverseRotate(10);
        break;
    case 'z':
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