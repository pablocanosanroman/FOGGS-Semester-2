#include "HelloGL.h"

HelloGL:: HelloGL(int argc, char* argv[])
{
	rotationSquare = 0.0f;
	rotationRectangle = 0.0f;
	rotationTriangle = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutMainLoop();
	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //This clears the scene
	DrawSquare();
	glFlush(); //flushes the scene drawn to the graphics card

	
	DrawRectangle();
	glFlush(); // flushes the scene drawn to the graphics card

	
	DrawTriangle();
	glFlush(); //flushes the scene drawn to the graphics card

	
}

void HelloGL::Update()
{
	glutPostRedisplay();

	rotationSquare += 0.5f;

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


void HelloGL::DrawSquare()
{
	glPushMatrix();
	glRotatef(rotationSquare, 0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.75, 0.75); //define the first point of the polygon, top left

		glColor4f(0.0f, 4.0f, 1.0f, 0.0f);
		glVertex2f(-0.5, 0.75); //next point, top rigth

		glColor4f(2.0f, 3.0f, 1.0f, 1.0f);
		glVertex2f(-0.5, 0.5); //bottom right

		glColor4f(1.0f, 4.0f, 5.0f, 0.0f);
		glVertex2f(-0.75, 0.5); //next point, bottom left
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
	glTranslatef(0.0f, 0.1f, 0.0f);
	glRotatef(rotationTriangle, 0.0f, 0.0f, -1.0f);
	
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f); // Color White Triangle
		glVertex2f(0.25, 0.25); // First Point bottom left

		glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.25, 0.5); // Top point

		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
		glVertex2f(0.5, 0.25); // Bottom Right
		glEnd();
	}
	
	glPopMatrix();
}

HelloGL::~HelloGL(void)
{

}