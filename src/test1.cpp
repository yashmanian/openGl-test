#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

float x_pos = -10.0f;

// Display Callback function
void display();

void init();

void reshape(int w, int h);

void timer(int);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	// Initialize the frame buffer with RGB and DOUBLE mode
	// Using two buffers to prevent lag on weaker machines.
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	// Initialize Window
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(500, 500);

	// Create Window
	glutCreateWindow("Window 1");

	// Callback function
	glutDisplayFunc(display);

	// Reshape function
	glutReshapeFunc(reshape);

	// Call display function repeatedly
	glutTimerFunc(1000, timer, 0);

	// Flush screen to different color
	init();

	// Main loop which keeps window alive
	glutMainLoop();
}

// Create a square of 2x2 and have it move from -10 on the X axis to +8
void display()
{
	// Clear Frame buffer
	glClear(GL_COLOR_BUFFER_BIT);

	// Reset transformations of current matrix
	glLoadIdentity();

	// Set size of point to 10 pixels
	glPointSize(10);


	// Draw polygon on screen
	glBegin(GL_POLYGON);

	glVertex2f(x_pos, 1.0f);
	glVertex2f(x_pos, -1.0f);
	glVertex2f(x_pos + 2.0f, -1.0f);
	glVertex2f(x_pos + 2.0f, 1.0f);


	// Vertices
	glEnd();

	// Flush contents of COLOR_BUFFER to screen
	//glFlush();

	// Swap back and front buffers
	glutSwapBuffers();
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

// Function is called everytime the window size is changed. Arguments passed in by the API
void reshape(int w, int h)
{
	// Here, the xy coordinates are with respect to the bottom left corner of the window.
	// Also takes in the width and height of the window
	// Specify viewport
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	// Specify projection matrix
	glMatrixMode(GL_PROJECTION);

	// Intiailize the projection matrix to identity
	glLoadIdentity();

	// Specify 2D projection of a 20x20 grid with (0, 0) at the center of the grid
	int Xmax = 10;
	int Xmin = -10;
	int Ymax = 10;
	int Ymin = -10;
	gluOrtho2D(-10, 10, -10, 10);

	// Switch back to model view matrix
	glMatrixMode(GL_MODELVIEW);
}	


// Timer function
void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);

	if(x_pos < 8.0f)
	{
		x_pos += 0.50f;
	}
	else
	{
		x_pos = -10.0f;
	}
}
