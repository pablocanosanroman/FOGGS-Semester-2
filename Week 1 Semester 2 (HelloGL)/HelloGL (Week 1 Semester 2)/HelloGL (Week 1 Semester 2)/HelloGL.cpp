#include "HelloGL.h"

Vertex HelloGL::vertices[] = 
{ 1,1,1, -1,1,1,  -1,-1,1,  //v0-v1-v2 (front)
-1,-1,1,  1,-1,1,  1,1,1,  //v2-v3-v0

1,1,1,  1,-1,1,  1,-1,-1, //v0-v3-v4 (right)
1,-1,-1,  1,1,-1,  1,1,1, //v4-v5-v0

1,1,1,  1,1,-1,  -1,1,-1,  //v0-v5-v6 (top)
-1,1,-1,  -1,1,1,  1,1,1,  //v6-v1-v0

-1,1,1,  -1,1,-1,  -1,-1,-1,  //v1-v6-v7 (left)
-1,-1,-1,  -1,-1,1,  -1,1,1,  //v7-v2-v1

-1,-1,-1,  1,-1,-1,  1,-1,1,  //v7-v4-v3 (bottom)
1,-1,1,  -1,-1,1,  -1,-1,-1,  //v3-v2-v7

1,-1,-1,  -1,-1,-1,  -1,1,-1,  //v4-v7-v6 (back)
-1,1,-1,  1,1,-1,  1,-1,-1 };  //v6-v5-v4

Color HelloGL::colors[] =
{ 1,1,1,  1,1,0, 1,0,0,  // v0-v1-v2 (front)
1,0,0,  1,0,1,  1,1,1,  //v2-v3-v0

1,1,1,  1,0,1,  0,0,1,  //v0-v3-v4 (right) 
0,0,1,  0,1,1,  1,1,1,  //v4-v5-v0

1,1,1,  0,1,1,  0,1,0,  //v0-v5-v6 (top)
0,1,0,  1,1,0,  1,1,1,  //v4-v5-v0

1,1,0,  0,1,0,  0,0,0,  //v1-v6-v7 (left)
0,0,0,  1,0,0,  1,1,0,  //v3-v2-v7

0,0,0,  0,0,1,  1,0,1,  //v7-v4-v3 (bottom)
1,0,1,  1,0,0,  0,0,0,  //v3-v2-v7

0,0,1,  0,0,0,  0,1,0,  //v4-v7-v6 (back)
0,1,0,  0,1,1,  0,0,1  //v6-v5-v4
};

Vertex HelloGL::indexedVertices[] = { 1, 1, 1,  -1, 1, 1,  //v0,v1,
-1,-1,1,  1,-1,1,  //v2, v3
1,-1,-1,  1,1,-1,  //v4,v5
-1,1,-1,  -1,-1,-1 }; //v6, v7

Color HelloGL::indexedColors[] = { 1,1,1,  1,1,0, //v0, v1,
1,0,0,  1,0,1,  //v2,v3
0,0,1,  0,1,1,  //v4, v5
0,1,0,  0,0,0 }; //v6, v7

GLushort HelloGL::indices[] = { 0,1,2,  2,3,0,  //front
0,3,4,  4,5,0,  //right
0,5,6,  6,1,0,  //top
1,6,7,  7,2,1,  //left
7,4,3,  3,2,7,  //bottom
4,7,6,  6,5,4 }; //back

Vertex HelloGL::indexedVerticesPyramid[] = { 0,1,0,  -1,-1,1, //v0,v1
1,-1,1,  1,-1,-1,  //v2,v3
-1,-1,-1 //v4
};

Color HelloGL::indexedColorsPyramid[] = { 1,1,1,  1,1,0,  //v0, v1, 
1,0,0,  1,0,1,  //v2, v3
0,0,1 //v4
};

GLushort HelloGL::indicesPyramid[] = {1,2,0,  //Front
0,2,3, //Right
3,4,0, //Back
0,4,1, //Left
1,4,3,  3,2,1 //Bottom

};

HelloGL:: HelloGL(int argc, char* argv[])
{
	//Set up of the camera
	camera = new Camera();

	/*camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;*/
	camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	/*rotationSquare = 0.0f;*/
	
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

	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);
	
	glutMainLoop(); //Loop of the game
	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT); //This clears the scene

	/*DrawCubeArray();*/
	/*DrawIndexedCube();*/

	/*DrawCubeArrayAlt();*/
	/*DrawIndexedCubeAlt();*/
	DrawIndexedPyramid();
	
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

	

	//if (rotationSquare >= 360.0f) // Sets a rotation in the Square
	//{
	//	rotationSquare = 0.0f;
	//}

	

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


//void HelloGL::DrawSquare()
//{
//	glPushMatrix();
//	glTranslatef(-0.5f, 0.5f, -2.0f);
//	glRotatef(rotationSquare, 0.0f, 1.0f, 0.0f);
//	glBegin(GL_POLYGON);
//	{
//		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
//		glVertex2f(-0.15, 0.15); //define the first point of the polygon, top left
//
//		glColor4f(0.0f, 4.0f, 1.0f, 0.0f);
//		glVertex2f(0.15, 0.15); //next point, top rigth
//
//		glColor4f(2.0f, 3.0f, 1.0f, 1.0f);
//		glVertex2f(0.15, -0.15); //bottom right
//
//		glColor4f(1.0f, 4.0f, 5.0f, 0.0f);
//		glVertex2f(-0.15, -0.15); //next point, bottom left
//		glEnd(); //defines the end of the draw
//	}
//	glPopMatrix();
//}



void HelloGL::DrawCube()
{
	glBegin(GL_TRIANGLES);
	
	//face v0-v1-v2
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(1, 1, 1);
	//face v2-v3-v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	//face v0-v3-v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	//face v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	//face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);

	//face v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	//face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);

	//face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	//face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);

	//face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	//face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();
}

void HelloGL::DrawCubeArray()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		/*glColor3f(colors[i].r, colors[i].g, colors[i].b);
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);*/

		glColor3fv(&colors[i].r);
		glVertex3fv(&vertices[i].x);
	}
	glEnd();

	glPopMatrix();
}

void HelloGL::DrawIndexedCube()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glColor3f(indexedColors[indices[i]].r, indexedColors[indices[i]].g, indexedColors[indices[i]].b);
		glVertex3f(indexedVertices[indices[i]].x, indexedVertices[indices[i]].y, indexedVertices[indices[i]].z);
	}
	glEnd();
	glPopMatrix();
}

void HelloGL::DrawCubeArrayAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);

	glPushMatrix();
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedCubeAlt()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void HelloGL::DrawIndexedPyramid()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 18; i++)
	{
		glColor3f(indexedColorsPyramid[indicesPyramid[i]].r, indexedColorsPyramid[indicesPyramid[i]].g, indexedColorsPyramid[indicesPyramid[i]].b);
		glVertex3f(indexedVerticesPyramid[indicesPyramid[i]].x, indexedVerticesPyramid[indicesPyramid[i]].y, indexedVerticesPyramid[indicesPyramid[i]].z);
	}
	glEnd();
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