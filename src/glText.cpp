#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

/**
 * Function to draw a character string
 * @param x X coordinate
 * @param y Y coordinate
 * @param z Z coordinate
 * @param string
 */
void drawString(float x,
				float y,
				float z,
				char* string){
	glRasterPos3f(x, y, z);
	for(char* c = string; *c != '/0'; c++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}

