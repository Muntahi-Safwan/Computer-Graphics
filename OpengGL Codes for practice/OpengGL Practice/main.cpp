// First Basic code for Creating a a dot using standard coding apprroach


/*
//    #include <GL/glut.h>
//    Includes the GLUT library for OpenGL.
//    GL      → OpenGL
//    glut.h  → GLUT header file
//    GLUT (OpenGL Utility Toolkit) is used to:
//    - Create windows
//    - Handle keyboard and mouse input
//    - Control the display loop
//    Without GLUT, window creation and event handling are not possible.
#include <GL/glut.h>

void display()
{
    //This is a callback function.

   // OpenGL automatically calls this function when:
    //- The window needs to be drawn
    //- The screen refreshes or updates

    glClear(GL_COLOR_BUFFER_BIT);   // Clears the screen. Removes old drawings. GL_COLOR_BUFFER_BIT → means clear colour buffer.Think of it like: Erase the board before drawing again.

    glPointSize(10.0f);             // Sets point size to 10 pixels. Default size is very small (1 pixel). So this makes it visible.

    glBegin(GL_POINTS);             // Start drawing a primitive. GL_POINTS means we are drawing points. OpenGL works like: Start → Define → End
    glColor3f(.50f, 1.0f, 0.0f);// glColor3f() sets RGB colour using 3 float values (0.0–1.0): 1.0 = full intensity, 0.0 = none → (1,0,0)=Red, (0,1,0)=Green, (0,0,1)=Blue
    glVertex2f(0.50f, 0.00f);
    glColor3f(1.0f, 0.0f, 0.0f);     // glVertex2f() defines a 2D coordinate using 2 float values (x,y); (0,0) is the centre, so it draws the red point at the centre.
    glVertex2f(0.0f,0.0f);
    glEnd();         // // glEnd() ends the drawing block and must always be used after glBegin().

    glFlush();   // Render now. it means  glEnd() ends the drawing block and must always be used after glBegin().
}

// Initialization
void init()  //This runs once before drawing starts.
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Background colour = white. glClearColor() sets background colour using RGBA (Red, Green, Blue, Alpha); (1,1,1,1) gives a white background.
     // Alpha = 1.0 → Fully opaque (not transparent) Alpha = 0.0 → Fully transparent Between 0.0 and 1.0 → Semi-transparent
    glMatrixMode(GL_PROJECTION);  // glMatrixMode(GL_PROJECTION) switches to the projection matrix, which controls the camera view and coordinate system.
    glLoadIdentity(); //Reset everything before applying new settings
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);   // gluOrtho2D(left, right, bottom, top) Coordinate system or  gluOrtho2D(-1,1,-1,1) sets 2D coordinates: X and Y range from -1 to 1 → (0,0)=centre, (-1,-1)=bottom-left, (1,1)=top-right.
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); //Initialises GLUT.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  //GLUT_SINGLE → Single buffer GLUT_RGB → Use RGB colour mode
    glutInitWindowSize(500,300); // Window size = 500 × 500 pixels.
    glutInitWindowPosition(100,100); //Window appears at position (100,100) on screen.
    glutCreateWindow("Point testing - OpenGL"); // Creates window with title.

    init();
    glutDisplayFunc(display); //Whenever window needs drawing, call display()//

    glutMainLoop(); // glutMainLoop() starts the infinite loop, keeps the window open, the program running, and continuously checks events; without it, the window closes immediately.
    return 0;
}
*/

//-------------------------------------------------------------------------------------------------------

// Line drawing using  without any functions or packages


#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5.0f);

    float x1 = -0.5f;
    float y1 = -0.7f;
    float x2 =  0.2f;
    float y2 =  0.5f;

    float m = (y2 - y1) / (x2 - x1);  // slope

    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f);

        for(float x = x1; x <= x2; x += 0.001f)
        {
            float y = y1 + m * (x - x1);
            glVertex2f(x, y);
            //Pixel X_cordinate=(x−x_min)/(x_max−x_min​)​×WindowWidth
            //Pixel Y_cordinate = (y-y_min)/(y_max-y_min)x WindowWidth
        }

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Using Points");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



/*
//  -----------------------------------------------------------------------------------------------------
//   With DDA algorithm
#include <GL/glut.h>
#include <cmath>
void drawLineDDA_mLess1(float x1, float y1, float x2, float y2)
{

    float dx = x2 - x1;
    float dy = y2 - y1;
    float m = dy / dx;
    float x = x1;
    float y = y1;
    glBegin(GL_POINTS);

        for (int i = 0; i <= (int)dx; i++)
        {
            glVertex2f(x, y);
            x = x + 1;
            y = y + m; //make it round according to the rule // for m is less than 1
        }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    glColor3f(1.0f, 0.0f, 0.0f);   // Red
    // Example points (pixel coordinates)
    drawLineDDA_mLess1(250,250 ,400, 400);
    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1);
    // IMPORTANT: Use pixel coordinate system so x+1 means "one pixel step"
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA (|m|<=1) using GL_POINTS");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

// -----------------------------------------------------------------------------------------------------//
*/
/*

// Rectangle drawing using GL_Quads
#include <windows.h>   // (Optional on Windows, safe to keep)
#include <GL/glut.h>   // GLUT / FreeGLUT

// Initialise OpenGL Graphics
void initGL()
{
    // Set background (clearing) colour: Black, fully opaque
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Handler for window repaint event //
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the colour buffer

    // Draw shapes using quads
    glBegin(GL_QUADS);  //  glBegin(GL_QUADS): Starts drawing quadrilaterals. Every 4 vertices = 1 quad (rectangle-like shape).

        // Quad 1 (Red)
        glColor3f(0.0f, 1.0f, 1.0f);  // color setting
        glVertex2f(-0.8f,  0.1f);   // bottom left
        glVertex2f(0.2f,  0.1f);   // bottom right
        glVertex2f(0.2f,  0.7f);   // top right
        glVertex2f(-0.8f,  0.7f);   // top left

        // Quad 2 (Green)
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.7f, -0.6f); // bottom left
        glVertex2f(-0.1f, -0.6f); // bottom right
        glVertex2f(-0.1f,  0.0f);// top right
        glVertex2f(-0.7f,  0.0f);// top left

        // Quad 3 (Mixed colours per vertex: Dark Gray / White)
        // (OpenGL interpolates colours between vertices)
        //glColor3f(1.f, 1.0f, 0.0f);  // Dark Gray
        //glVertex2f(-0.9f, -0.7f);

        //glColor3f(1.0f, 1.0f, 1.0f);  // White
        //glVertex2f(-0.5f, -0.7f);

        //glColor3f(0.2f, 0.2f, 0.2f);  // Dark Gray
        //glVertex2f(-0.5f, -0.3f);

        //glColor3f(1.0f, 1.0f, 1.0f);  // White
        //glVertex2f(-0.9f, -0.3f);

    glEnd();

    glFlush();  // Render now (single buffer)
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Quads - Code::Blocks");

    initGL();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

//---------------------------------------------------------
*/
// traingle
/*
#include <windows.h>
#include <GL/glut.h>

// Initialize OpenGL
void initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // Black background
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear screen

    glBegin(GL_TRIANGLES);


        glColor3f(0.0f, 0.0f, 1.0f);   // Blue
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(-0.1f, 0.0f);
        glVertex2f(-0.4f, 0.3f);

        // -------- Second Triangle (Mixed Colors) --------
        glColor3f(1.0f, 0.0f, 0.0f);   // Red
        glVertex2f(0.3f, -0.4f);

        glColor3f(0.0f, 1.0f, 0.0f);   // Green
        glVertex2f(0.9f, -0.4f);

        glColor3f(0.0f, 0.0f, 1.0f);   // Blue
        glVertex2f(0.6f, -0.9f);

    glEnd();

    glFlush();  // Render
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(150, 50);
    glutCreateWindow("OpenGL Triangles");

    initGL();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

*/
//------------------------------------

// USE of GL_LINES
//
/*
#include <windows.h>
#include <GL/glut.h>

// Initialize OpenGL
void initGL()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);  // White background
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Clear screen

    glBegin(GL_LINES);

        // Line 1 (Blue)
        glColor3f(0.0f, 0.0f, 1.0f);  // Blue color
        glVertex2f(-0.8f, 0.6f);   // Point 1
        glVertex2f(0.8f, 0.6f);    // Point 2

        // Line 2 (Red)
        glColor3f(1.0f, 0.0f, 0.0f);  // Red color
        glVertex2f(-0.8f, -0.6f);  // Point 3
        glVertex2f(0.8f, -0.6f);   // Point 4

        // Line 3 (Green)
        glColor3f(0.0f, 1.0f, 0.0f);  // Green color
        glVertex2f(0.6f, -0.8f);  // Point 5
        glVertex2f(0.6f, 0.8f);   // Point 6

    glEnd();

    glFlush();  // Render
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(150, 50);
    glutCreateWindow("OpenGL Lines");

    initGL();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
