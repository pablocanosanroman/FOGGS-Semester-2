#include "SolarSystem.h"
#include "MeshLoader.h"
#include <ctime>

//Constructor and destructor
SolarSystem::SolarSystem(int argc, char* argv[])
{
	srand(time(NULL));

	InitGL(argc, argv);

	InitObjects();

	InitLight();

	glutMainLoop(); //Loop of the game
}

SolarSystem::~SolarSystem()
{
	delete camera;

	delete sun;

	delete mercury;
	
	delete venus;

	delete _lightPosition;

	delete _lightData;

}

void SolarSystem::InitObjects()
{
	//Set up of the camera
	camera = new Camera();

	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	Mesh* mercuryCubeMesh = MeshLoader::Load((char*)"mercury.txt");
	Mesh* venusCubeMesh = MeshLoader::Load((char*)"venus.txt");
	Mesh* earthCubeMesh = MeshLoader::Load((char*)"earth.txt");
	Mesh* marsCubeMesh = MeshLoader::Load((char*)"mars.txt");

	Texture2D* texture = new Texture2D();
	texture->Load((char*)"penguins.raw", 512, 512);

	//set up cube
	sun = new Sun(cubeMesh, texture, 0.0f, 0.0f, -20.0f);
	mercury = new Mercury(mercuryCubeMesh, texture, 0.0f, 0.0f, -20.f);
	venus = new Venus(venusCubeMesh, texture, 0.0f, 0.0f, -20.0f);
	earth = new Earth(earthCubeMesh, texture, 0.0f, 0.0f, -20.0f);
	mars = new Mars(marsCubeMesh, texture, 0.0f, 0.0f, -20.0);

	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 50.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;


}

//Init functions
void SolarSystem::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // Initialise double buffering

	glutInitWindowSize(800, 800); //Size of the window

	glutInitWindowPosition(100, 100); //Position of the window

	glutCreateWindow("Solar System FOGGS"); //Create Window

	glutDisplayFunc(GLUTCallbacks::Display); //Initialise Display Function

	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE); //Initialise timer to control FPS

	glutKeyboardFunc(GLUTCallbacks::Keyboard); //Initialise the keyboard function

	glMatrixMode(GL_PROJECTION); //execute against the projection part of the pipeline

	glLoadIdentity(); //Load the identity matrix

	glViewport(0, 0, 800, 800); //Set the viewport of the entire window

	//Paramenters: (Field of view angle, Aspect Ration, Near Clipping distance, Far Clipping distance)
	gluPerspective(45, 1, 0, 1000); //Set the correct perspective for the camera 3D

	glMatrixMode(GL_MODELVIEW); //Back to the model view matrix to work with our models

	glEnable(GL_TEXTURE_2D);

	glEnable(GL_DEPTH_TEST);

	glDepthFunc(GL_ALWAYS);

	glEnable(GL_CULL_FACE);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	glCullFace(GL_BACK);
	

}



void SolarSystem::InitLight()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = -20.0;
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

//Display, Update and Keyboard functions

void SolarSystem::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //This clears the scene

	sun->Draw();
	mercury->Draw();
	venus->Draw();
	earth->Draw();
	mars->Draw();

	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
}

void SolarSystem::Update()
{
	glLoadIdentity();
	//Says the camera where to stay
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z,
		camera->center.x, camera->center.y, camera->center.z,
		camera->up.x, camera->up.y, camera->up.z); //Eye point, reference point: center(0,0,0), up vector (y)

	glutPostRedisplay();

	sun->Update();
	mercury->Update();
	venus->Update();
	earth->Update();
	mars->Update();

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));

	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));

	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));

	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

}

void SolarSystem::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		
		camera->eye.x += -0.1f;
		
		
	}
	
	if (key == 'l')
	{
		camera->center.x += 0.1f;
	}
	
	if (key == 'a')
	{
		
		camera->eye.x += 0.1f;
	

	}
	
	if (key == 'j')
	{
		camera->center.x += -0.1f;
	}
	
	if (key == 's')
	{
		
		camera->eye.y += 0.1f;
		

	}
	
	if (key == 'k')
	{
		camera->center.y += -0.1f;
	}
	
	if (key == 'w')
	{
		
		camera->eye.y += -0.1f;
		
	}
	
	if (key == 'i')
	{
		camera->center.y += 0.1f;
	}
	
	if (key == 'e')
	{
		camera->eye.z += 0.1f;
		camera->center.z += -0.1f;

	
	}
	
	if (key == 'q')
	{
		camera->eye.z += -0.1f;
		camera->center.z += 0.1f;
		
	}

}