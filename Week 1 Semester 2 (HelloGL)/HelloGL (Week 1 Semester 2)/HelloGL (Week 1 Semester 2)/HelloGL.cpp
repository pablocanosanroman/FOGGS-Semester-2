#include "HelloGL.h"
#include "MeshLoader.h"
#include <ctime>




HelloGL:: HelloGL(int argc, char* argv[])
{
	srand(time(NULL));
	
	InitGL(argc, argv);

	InitObjects();

	InitLight();
	
	glutMainLoop(); //Loop of the game

}

void HelloGL::InitObjects()
{
	//Set up of the camera
	camera = new Camera();

	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	/*Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid.txt");*/

	Texture2D* texture = new Texture2D();
	texture->LoadTGA("earth.tga");

	//set up cube
	for (int i = 0; i < 100; i++)
	{
		objects[i] = new FlyingObjects(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	////set up pyramid
	//for (int i = 100; i < 200; i++)
	//{
	//	objects[i] = new StaticObjects(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	//}


	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
}

void HelloGL::InitLight()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->ambient.x = 0.2;
	_lightData->ambient.y = 0.2;
	_lightData->ambient.z = 0.2;
	_lightData->ambient.w = 1.0;
	_lightData->diffuse.x = 0.8;
	_lightData->diffuse.y = 0.8;
	_lightData->diffuse.z = 0.8;
	_lightData->diffuse.w = 1.0;
	_lightData->specular.x = 0.2;
	_lightData->specular.y = 0.2;
	_lightData->specular.z = 0.2;
	_lightData->specular.w = 1.0;
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); //Initialise double buffering

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

	glEnable(GL_TEXTURE_2D);//without this you only can see white boxes

	glEnable(GL_DEPTH_TEST);

	glDepthFunc(GL_ALWAYS);

	glEnable(GL_CULL_FACE);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	glCullFace(GL_BACK);
	
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //This clears the scene

	Vector3 v = { -0.7f, 0.7f, -1.0f };
	Color c = { 0.0f, 1.0f, 0.0f };

	DrawString("OpenGL FOGGS Project", &v, &c);

	for (int i = 0; i < 100; i++)
	{
		objects[i]->Draw();
	}
	
	/*for (int i = 100; i < 200; i++)
	{
		objects[i]->Draw();
	}*/
	

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

	for (int i = 0; i < 100; i++)
	{
		objects[i]->Update();
	}

	/*for (int i = 100; i < 200; i++)
	{
		objects[i]->Update();
	}
	*/

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));

	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));

	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));

	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		camera->eye.x+= -0.1f;
	}
	else if (key == 'a')
	{
		camera->eye.x+= 0.1f;
	}
	else if (key == 's')
	{
		camera->eye.y += 0.1f;

	}
	else if (key == 'w')
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

void HelloGL::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();

	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	glPopMatrix();

	
}


HelloGL::~HelloGL(void)
{
	delete camera;

	for (int i = 0; i < 100; i++)
	{
		delete objects[i];
	}

	/*for (int i = 100; i < 200; i++)
	{
		delete objects[i];
	}*/
	
	delete _lightPosition;

	delete _lightData;
}