#include "HelloGL.h"

HelloGL:: HelloGL(int argc, char* argv[])
{
	//Set up of the camera
	camera = new Camera();

	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	rotationSquare = 0.0f;
	rotationRectangle = 0.0f;
	rotationTriangle = 0.0f;
	rotationCube = 0.0f;
	rotationSphere = 0.0f;
	rotationTeapot = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE); //Initialise double buffering
	
	glutInitWindowSize(800, 800); //Size of the window
	
	glutInitWindowPosition(100, 100); //Position of the window
	
	glutCreateWindow("Simple OpenGL Program"); //Create Window
	
	glutDisplayFunc(GLUTCallbacks::Display); //Initialise Display func
	
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE); //Initialise timer to control the FPS
	
	glutKeyboardFunc(GLUTCallbacks::Keyboard); //Initialise the keyboard function
	
	glMatrixMode(GL_PROJECTION); // execute against the projection part of the pipeline
	
	glLoadIdentity(); //Load the identity matrix
	
	glViewport(0, 0, 800, 800); //Set the viewport of the entire window
	
	//Parameters: (Field of View angle, Aspect Ratio, Near Clipping distance, Far Clipping Distance)
	gluPerspective(45, 1, 0, 1000); //Set the correct perspective (camera 3D)
	
	glMatrixMode(GL_MODELVIEW); //Back to the model view matrix to work with our models
	
	glutMainLoop(); //Loop of the game
	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //This clears the scene
	/*DrawSquare();
	
	
	
	DrawRectangle();
	
	
	
	DrawTriangle();*/
	DrawCube();

	DrawSphere();

	DrawTeapot();
	
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
	
}

void HelloGL::Update()
{
	/*Sleep(10);*/ // it makes the app pause for 10 ms, simulating a more complex Update() function and it makes a drop on the FPS
	glLoadIdentity();
	//Says the camera where to stay
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z); //Eye point, reference point: center(0,0,0), up vector (y)


	glutPostRedisplay();

	

	if (rotationSquare >= 360.0f) // Sets a rotation in the Square
	{
		rotationSquare = 0.0f;
	}

	rotationRectangle += 2.0f;

	if (rotationRectangle >= 360.0f)
	{
		rotationRectangle = 0.0f;
	}

	rotationTriangle += 1.0f;

	if (rotationTriangle >= 360.0f)
	{
		rotationTriangle = 0.0f;
	}

	rotationCube += 2.0f;

	if (rotationCube >= 360.0f)
	{
		rotationCube = 0.0f;
	}

	rotationSphere += 1.5f;

	if (rotationSphere >= 360.0f)
	{
		rotationSphere = 0.0f;
	}

	rotationTeapot += 1.0f;

	if (rotationTeapot >= 360.0f)
	{
		rotationTeapot = 0.0f;
	}
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		camera->eye.x+= -0.1f;
	}
	else if (key == 'd')
	{
		camera->eye.x+= 0.1f;
	}
	else if (key == 'w')
	{
		camera->eye.y += 0.1f;

	}
	else if (key == 's')
	{
		camera->eye.y += -0.1f;
	}
	else if (key == 'e')
	{
		camera->eye.z += 0.1f;
	}
	else if (key == 'q')
	{
		camera->eye.z += -0.1f;
	}
	
}


void HelloGL::DrawSquare()
{
	glPushMatrix();
	glTranslatef(-0.5f, 0.5f, -2.0f);
	glRotatef(rotationSquare, 0.0f, 1.0f, 0.0f);
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
	glTranslatef(0.0f, -0.25f, -2.0f);
	glRotatef(rotationRectangle, 1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	{
		glColor4f(1.0f, 1.0f, 0.0f, 0.0f); //Rectangle color Yellow
		glVertex2f(-0.25, -0.15); // First point top left

		glColor4f(2.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(0.25, -0.15); //Top right

		glColor4f(0.0f, 2.0f, 2.0f, 0.0f);
		glVertex2f(0.25,-0.35); //Bottom right

		glColor4f(0.0f, 0.0f, 3.0f, 0.0f);
		glVertex2f(-0.25, -0.35); //Bottom left

		glEnd();
	}
	glPopMatrix();
}

void HelloGL::DrawTriangle()
{
	glPushMatrix();
	glTranslatef(0.5f, 0.5f, -2.0f);
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

void HelloGL::DrawCube()
{
	glPushMatrix();
	
	glRotatef(rotationCube, 0.0f, 1.0f, 0.0f);
	glutWireCube(0.1);
	glPopMatrix();
}

void HelloGL::DrawSphere()
{
	glPushMatrix();
	glTranslatef(0.0f, 0.2f, 0.0f);
	glRotatef(rotationSphere, 1.0f, 0.0f, 0.0f);
	glutWireSphere(0.05, 20, 20);
	glPopMatrix();
}

void HelloGL::DrawTeapot()
{
	glPushMatrix();
	glTranslatef(0.0f, -0.2f, 0.0f);
	glRotatef(rotationTeapot, 0.0f, 1.0f, 0.0f);
	glutWireTeapot(0.15);
	glPopMatrix();
}

HelloGL::~HelloGL(void)
{
	delete camera;
}