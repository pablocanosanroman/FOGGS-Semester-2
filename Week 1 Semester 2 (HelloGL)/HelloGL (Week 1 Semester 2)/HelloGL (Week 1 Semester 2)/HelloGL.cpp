#include "HelloGL.h"

HelloGL:: HelloGL(int argc, char* argv[])
{
	rotationSquare = 0.0f;
	rotationRectangle = 0.0f;
	rotationTriangle = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMainLoop();
	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //This clears the scene
	DrawSquare();
	
	
	
	DrawRectangle();
	
	
	
	DrawTriangle();
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
	
}

void HelloGL::Update()
{
	/*Sleep(10);*/ // it makes the app pause for 10 ms, simulating a more complex Update() function and it makes a drop on the FPS
	glutPostRedisplay();

	

	if (rotationSquare >= 360.0f) // Sets a rotation in the Square
	{
		rotationSquare = 0.0f;
	}

	rotationRectangle += 1.5f;

	if (rotationRectangle >= 360.0f)
	{
		rotationRectangle = 0.0f;
	}

	rotationTriangle += 1.0f;

	if (rotationTriangle >= 360.0f)
	{
		rotationTriangle = 0.0f;
	}
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		rotationSquare += 0.5f;
	}
	else if (key == 'a')
	{
		rotationSquare += -0.5f;
	}
}


void HelloGL::DrawSquare()
{
	glPushMatrix();
	glTranslatef(-0.5f, 0.5f, 0.0f);
	glRotatef(rotationSquare, 0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.15, 0.15); //define the first point of the polygon, top left

		glColor4f(0.0f, 4.0f, 1.0f, 0.0f);
		glVertex2f(0.15, 0.15); //next point, top rigth

		glColor4f(2.0f, 3.0f, 1.0f, 1.0f);
		glVertex2f(0.15, -0.15); //bottom right

		glColor4f(1.0f, 4.0f, 5.0f, 0.0f);
		glVertex2f(-0.15, -0.15); //next point, bottom left
		glEnd(); //defines the end of the draw
	}
	glPopMatrix();
}

void HelloGL::DrawRectangle()
{
	glPushMatrix();
	glRotatef(rotationRectangle, 0.0f, 0.0f, -1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f); //Rectangle color Yellow
		glVertex2f(-0.15, 0.25); // First point top left

		glColor4f(2.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(0.15, 0.25); //Top right

		glColor4f(0.0f, 2.0f, 2.0f, 0.0f);
		glVertex2f(0.15,-0.25); //Bottom right

		glColor4f(0.0f, 0.0f, 3.0f, 0.0f);
		glVertex2f(-0.15, -0.25); //Bottom left

		glEnd();
	}
	glPopMatrix();
}

void HelloGL::DrawTriangle()
{
	glPushMatrix();
	glTranslatef(0.5f, 0.5f, 0.0f);
	glRotatef(rotationTriangle, 0.0f, 0.0f, -1.0f);
	
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f); // Color White Triangle
		glVertex2f(-0.25, 0.0); // First Point bottom left

		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.0, 0.25); // Top point

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.25, 0.0); // Bottom Right
		glEnd();
	}
	
	glPopMatrix();
}

HelloGL::~HelloGL(void)
{

}