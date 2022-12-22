// WAP a command to create a polygon in OpenGL

// Pseudo Definition to avoid errors
bool GL_COLOR_BUFFER_BIT = true;
bool GL_DEPTH_BUFFER_BIT = false;
bool GL_POLYGON = true;
void glClear(bool){}
void glColor3f(float, float, float){}
void glBegin(bool){}
void glEnd(){}
void glVertex2f(float, float){}
void glutSwapBuffers(){}

// Actual Prorgam Stucture
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_POLYGON);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
		glVertex2f(-0.5, -0.5);
	glEnd();

	glutSwapBuffers();
}