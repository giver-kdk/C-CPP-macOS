#include <stdio.h>

#define GL_COLOR_BUFFER_BIT 1
#define GL_DEPTH_BUFFER_BIT 1
#define GL_POINTS 1
#define GL_LINES 1
#define GL_POLYGON 1

void glClear(int x){}
void glColor3f(float x, float y, float z){}
void glBegin(int x){}
void glVertex2f(float x, float y){}
void glEnd(){}
void glutSwapBuffers(){}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);

	// Can try: "GL_LINE_LOOP" and "GL_LINE_STRIP" for line loop and strip
	glBegin(GL_POLYGON);
		glVertex2f(0.5, 0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(-0.5, -0.5);
		glVeretx2f(0.5, -0.5);
	glEnd();

	glutSwapBuffers();
}
