#include "SolarSystem.h"
#include "MeshLoader.h"
#include <ctime>
#include <iostream>



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

	delete earth;

	delete mars;

	delete jupiter;

	delete saturn;

	delete uranus;

	delete neptune;

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
	Mesh* jupiterCubeMesh = MeshLoader::Load((char*)"jupiter.txt");
	Mesh* saturnCubeMesh = MeshLoader::Load((char*)"saturn.txt");
	Mesh* uranusCubeMesh = MeshLoader::Load((char*)"uranus.txt");
	Mesh* neptuneCubeMesh = MeshLoader::Load((char*)"neptune.txt");

	Texture2D* texture = new Texture2D();
	texture->Load((char*)"penguins.raw", 512, 512);

	//set up cube
	sun = new Sun(cubeMesh, texture, 0.0f, 0.0f, -20.0f);
	mercury = new Mercury(mercuryCubeMesh, texture, 0.0f, 0.0f, -20.f);
	venus = new Venus(venusCubeMesh, texture, 0.0f, 0.0f, -20.0f);
	earth = new Earth(earthCubeMesh, texture, 0.0f, 0.0f, -20.0f);
	mars = new Mars(marsCubeMesh, texture, 0.0f, 0.0f, -20.0f);
	jupiter = new Jupiter(jupiterCubeMesh, texture, 0.0f, 0.0f, -20.0f);
	saturn = new Saturn(saturnCubeMesh, texture, 0.0f, 0.0f, -20.0f);
	uranus = new Uranus(uranusCubeMesh, texture, 0.0f, 0.0f, -20.0f);
	neptune = new Neptune(neptuneCubeMesh, texture, 0.0f, 0.0f, -20.0f);

	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 150.0f;
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
	_lightPosition->x = sun->GetOrbitalPosition().x;
	_lightPosition->y = sun->GetOrbitalPosition().y;
	_lightPosition->z = sun->GetOrbitalPosition().z;
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

	Vector3 v = { -50.0f, 50.0f, -2.0f };
	Color c = { 0.0f, 1.0f, 0.0f };

	glDisable(GL_LIGHTING);
	DrawString("Cube Solar System", &v, &c);
	glEnable(GL_LIGHTING);
	
	sun->Draw();
	mercury->Draw();
	venus->Draw();
	earth->Draw();
	mars->Draw();
	jupiter->Draw();
	saturn->Draw();
	uranus->Draw();
	neptune->Draw();

	

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
	jupiter->Update();
	saturn->Update();
	uranus->Update();
	neptune->Update();

	DoCollision();

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));

	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x));

	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x));

	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

}

void SolarSystem::Keyboard(unsigned char key, int x, int y)
{
	
	if (key == 'd')
	{
		
		camera->eye.x += -0.5f;
		
		
	}
	
	if (key == 'l')
	{
		camera->center.x += 0.5f;
	}
	
	if (key == 'a')
	{
		
		camera->eye.x += 0.5f;
	

	}
	
	if (key == 'j')
	{
		camera->center.x += -0.5f;
	}
	
	if (key == 's')
	{
		
		camera->eye.y += 0.5f;
		

	}
	
	if (key == 'k')
	{
		camera->center.y += -0.5f;
	}
	
	if (key == 'w')
	{
		
		camera->eye.y += -0.5f;
		
	}
	
	if (key == 'i')
	{
		camera->center.y += 0.5f;
	}
	
	if (key == 'e')
	{
		camera->eye.z += 0.5f;
		camera->center.z += -0.5f;

	
	}
	
	if (key == 'q')
	{
		camera->eye.z += -0.5f;
		camera->center.z += 0.5f;
		
	}

	if (key == 't')
	{
		sun->MoveUp();
	

	}

	if (key == 'f')
	{
		sun->MoveLeft();
	}
	if (key == 'g')
	{
		sun->MoveDown();

	}

	if (key == 'h')
	{
		sun->MoveRight();
	}

	if (key == 'r')
	{
		sun->MoveForward();
	}

	if (key == 'y')
	{
		sun->MoveBackwards();
	}
}

void SolarSystem::DrawString(const char* text, Vector3* position, Color* color)
{
	glPushMatrix();

	glTranslatef(position->x, position->y, position->z);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

	glPopMatrix();
}

float SolarSystem::calculateDistanceSquared(Vector3 object1, Vector3 object2)
{
	float distance = ((object1.x - object2.x) * (object1.x - object2.x))
		+ ((object1.y - object2.y) * (object1.y - object2.y))
		+ ((object1.z - object2.z) * (object1.z - object2.z));

	return distance;
}

Vector3 SolarSystem::GetOffsetPosition(Vector3 sun, Vector3 planet, Vector3 planet_rotation)
{
	float difference = abs(planet.z) - abs(sun.z);
	float x = difference * sin(planet_rotation.y);
	float y = planet.y;
	float z = difference * cos(planet_rotation.y);

	Vector3 planet_real_position = { x, y, z };
	

	return planet_real_position;
}

void SolarSystem::DoCollision()
{
	Vector3 new_position = { -500000000, -500000000, -500000000 };

	Vector3 mercury_real_position = GetOffsetPosition(sun->GetOrbitalPosition(), mercury->GetPosition(), mercury->GetRotation());
	float distance = calculateDistanceSquared(sun->GetOrbitalPosition(), mercury_real_position);
	

	std::cout << sun->GetOrbitalPosition().x << " " << sun->GetOrbitalPosition().y << " " << sun->GetOrbitalPosition().z << std::endl;
	std::cout << mercury_real_position.x << " " << mercury_real_position.y << " " << mercury_real_position.z << std::endl;
	
	
	/*if (distance == 0)
	{
		mercury->SetPosition(new_position);
	}*/
}