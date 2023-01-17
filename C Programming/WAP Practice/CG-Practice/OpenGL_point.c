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

	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POINTS);
		glVertex2f(-0.5, 0.5);
	glEnd();
	
	glutSwapBuffers();
}
