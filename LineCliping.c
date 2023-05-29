#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdio.h>
float xmin, xmax, ymin, ymax, x1, y1, x2, y2;
void init()
{
    gluOrtho2D(-200, 200, -200, 200);
}

int sign(int a)
{
    if (a > 0)
        return 1;
    else
        return 0;
}
void display(void)
{

    int b1[4], b2[4];

    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(xmin, ymin);
    glVertex2f(xmin, ymax);
    glVertex2f(xmax, ymax);
    glVertex2f(xmax, ymin);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    b1[0] = sign(xmin - x1);
    b2[0] = sign(xmin - x2);
    b1[1] = sign(x1 - xmax);
    b2[1] = sign(x2 - xmax);
    b1[2] = sign(ymin - y1);
    b2[2] = sign(ymin - y2);
    b1[3] = sign(y1 - ymax);
    b2[3] = sign(y2 - ymax);
    float m = (y2 - y1) / (x2 - x1);
    float c = y1 - m * x1;
    if (b1[0] == 0 && b1[1] == 0 && b1[2] == 0 && b1[3] == 0 && b2[0] == 0 && b2[1] == 0 && b2[2] == 0 && b2[3] == 0) // If completely inside
    {
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
    else
    {
        int i, var, flag = 0;
        for (i = 0; i < 4; i++)
        {
            if ((b1[i] == b2[i]) && (b1[i] == 1))
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (i = 0; i < 4; i++)
            {
                if (b1[i] == b2[i])
                    continue;
                if (i == 0 && b1[i] == 1)
                {
                    var = m * xmin + c;
                    y1 = var;
                    x1 = xmin;
                }
                if (i == 0 && b2[i] == 1)
                {
                    var = m * xmin + c;
                    y2 = var;
                    x2 = xmin;
                }
                if (i == 1 && b1[i] == 1)
                {
                    var = m * xmax + c;
                    y1 = var;
                    x1 = xmax;
                }
                if (i == 1 && b2[i] == 1)
                {
                    var = m * xmax + c;
                    y2 = var;
                    x2 = xmax;
                }
                if (i == 2 && b1[i] == 1)
                {
                    var = (float)(ymin - c) / m;
                    y1 = ymin;
                    x1 = var;
                }
                if (i == 2 && b2[i] == 1)
                {
                    var = (float)(ymin - c) / m;
                    y2 = ymin;
                    x2 = var;
                }
                if (i == 3 && b1[i] == 1)
                {
                    var = (float)(ymax - c) / m;
                    y1 = ymax;
                    x1 = var;
                }
                if (i == 3 && b2[i] == 1)
                {
                    var = (float)(ymax - c) / m;
                    y2 = ymax;
                    x2 = var;
                }
                b1[0] = sign(xmin - x1);
                b2[0] = sign(xmin - x2);
                b1[1] = sign(x1 - xmax);
                b2[1] = sign(x2 - xmax);
                b1[2] = sign(ymin - y1);
                b2[2] = sign(ymin - y2);
                b1[3] = sign(y1 - ymax);
                b2[3] = sign(y2 - ymax);
            }
            glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 1.0f, 1.0f);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glEnd();
        }
    }
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("COHEN SUTHERLAND LINE CLIPING ALGORITHM");
    printf("Enter the boundary (xmin,xmax,ymin,ymax)\n");
    scanf("%f %f %f %f", &xmin, &xmax, &ymin, &ymax);
    printf("Enter the first point\n");
    scanf("%f %f", &x1, &y1);
    printf("Enter the second point\n");
    scanf("%f %f", &x2, &y2);
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}