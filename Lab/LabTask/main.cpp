#include <GL/glut.h>
#include <cmath>

// ----------- Screen mapping -----------
const int WIDTH = 500;
const int HEIGHT = 500;
const int ORIGIN_X = 250;
const int ORIGIN_Y = 250;
const int SCALE = 20;

// Convert world → pixel
int mapX(float x) { return ORIGIN_X + (int)(x * SCALE); }
int mapY(float y) { return ORIGIN_Y + (int)(y * SCALE); }


// ---------------- TRUE DDA (integer grid) ----------------
void drawLineDDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2i(round(x), round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
}


// ---------------- TRUE BRESENHAM ----------------
void drawLineBresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int p = (2*dy)-dx;
    int x = x1;
    int y = y1;

    glBegin(GL_POINTS);
    while (true)
    {
        glVertex2i(x, y);

        if (x == x2 && y == y2)
            break;

        if (p<0)
        {
            x = x + 1;
            p = p + (2*dy);
        }else {
            x = x + 1;
            y = y + 1;
            p = p + 2 * (dy-dx);
        }
    }
    glEnd();
}



// ---------------- Display ----------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4.0f);

    // Convert world coordinates → pixel coordinates
    int x1 = mapX(5),  y1 = mapY(2);
    int x2 = mapX(5),  y2 = mapY(-7);
    int x3 = mapX(10), y3 = mapY(2);
    int x4 = mapX(10), y4 = mapY(-2);
    int x5 = mapX(5),  y5 = mapY(-7);

    // -------- DDA lines --------
    glColor3f(1, 0, 0);
    drawLineDDA(x1, y1, x2, y2);
    drawLineDDA(x1, y1, x3, y3);

    // -------- Bresenham line --------
    glColor3f(0, 0, 1);
    drawLineBresenham(x5, y5, x4, mapY(-2));

    // -------- GL_LINES --------
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
        glVertex2i(x3, y3);
        glVertex2i(x4, y4);
    glEnd();

    glFlush();
}

// ---------------- Init ----------------
void init()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, WIDTH, 0, HEIGHT);   // pixel coordinate system
}


// ---------------- Main ----------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Bresenham and DDA");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
