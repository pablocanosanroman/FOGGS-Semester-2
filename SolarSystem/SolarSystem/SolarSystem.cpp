#include "SolarSystem.h"
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

	delete _lightData;

}

void SolarSystem::InitObjects()
{
	//Set up of the camera
	camera = new Camera();

	//Load all the cube files
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	Mesh* mercuryCubeMesh = MeshLoader::Load((char*)"mercury.txt");
	Mesh* venusCubeMesh = MeshLoader::Load((char*)"venus.txt");
	Mesh* earthCubeMesh = MeshLoader::Load((char*)"earth.txt");
	Mesh* marsCubeMesh = MeshLoader::Load((char*)"mars.txt");
	Mesh* jupiterCubeMesh = MeshLoader::Load((char*)"jupiter.txt");
	Mesh* saturnCubeMesh = MeshLoader::Load((char*)"saturn.txt");
	Mesh* uranusCubeMesh = MeshLoader::Load((char*)"uranus.txt");
	Mesh* neptuneCubeMesh = MeshLoader::Load((char*)"neptune.txt");

	
	//Set Up textures for the planets

	Texture2D* planetTexture = new Texture2D();
	planetTexture->LoadTGA("Textures/planet.tga");

	

	//set up cubes
	sun = new Sun(cubeMesh, planetTexture, 0.0f, 0.0f, -20.0f);
	mercury = new Mercury(mercuryCubeMesh, planetTexture, 0.0f, 0.0f, -20.f);
	venus = new Venus(venusCubeMesh, planetTexture, 0.0f, 0.0f, -20.0f);
	earth = new Earth(earthCubeMesh, planetTexture, 0.0f, 0.0f, -20.0f);
	mars = new Mars(marsCubeMesh, planetTexture, 0.0f, 0.0f, -20.0f);
	jupiter = new Jupiter(jupiterCubeMesh, planetTexture, 0.0f, 0.0f, -20.0f);
	saturn = new Saturn(saturnCubeMesh, planetTexture, 0.0f, 0.0f, -20.0f);
	uranus = new Uranus(uranusCubeMesh, planetTexture, 0.0f, 0.0f, -20.0f);
	neptune = new Neptune(neptuneCubeMesh, planetTexture, 0.0f, 0.0f, -20.0f);

	//Set up camera position
	camera->eye.x = 0.0f; camera->eye.y = 150.0f; camera->eye.z = 150.0f;
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

	glEnable(GL_TEXTURE_2D); //Enable the creation of textures 2D

	glEnable(GL_DEPTH_TEST); //Enable the depth test

	glDepthFunc(GL_ALWAYS);

	glEnable(GL_CULL_FACE);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	glCullFace(GL_BACK);
	

}



void SolarSystem::InitLight()
{
	
	//Set up light parameters
	_lightData = new Lighting();

	//Ambient Light
	_lightData->ambient.x = 3.2f;
	_lightData->ambient.y = 3.2f;
	_lightData->ambient.z = 3.2f;
	_lightData->ambient.w = 1.0f;

	//Diffuse Light
	_lightData->diffuse.x = 2.7f;
	_lightData->diffuse.y = 2.7f;
	_lightData->diffuse.z = 2.7f;
	_lightData->diffuse.w = 1.0f;

	//Specular Light
	_lightData->specular.x = 2.7f;
	_lightData->specular.y = 2.7f;
	_lightData->specular.z = 2.7f;
	_lightData->specular.w = 1.0f;

	//Direction Light
	_lightData->direction.x = 0.0f;
	_lightData->direction.y = PI;
	_lightData->direction.z = 0.0f;
	_lightData->direction.w = 0.0f;

}

//Display, Update and Keyboard functions

void SolarSystem::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //This clears the scene

	//Draw text to the screen
	Vector3 vector_title_string = { -60.0f, 80.0f, -2.0f };
	Vector3 vector_eye_string = { -62.5f, 70.0f, -2.0f };
	Vector3 vector_eyex_string = { -40.0f, 70.0f, -2.0f };
	Vector3 vector_eyey_string = { -22.5f, 70.0f, -2.0f };
	Vector3 vector_eyez_string = { 0.0, 70.0f, -2.0f };
	Vector3 vector_center_string = { -65.0f, 60.0f, -2.0f };
	Vector3 vector_centerx_string = { -40.0f, 60.0f, -2.0f };
	Vector3 vector_centery_string = { -20.0f, 60.0f, -2.0f };
	Vector3 vector_centerz_string = { 0.0f, 60.0f, -2.0f };
	Color color_strings = { 255.0f, 255.0f, 255.0f };

	camera_eyex_coordinates = std::to_string(camera->eye.x);
	camera_eyey_coordinates = std::to_string(camera->eye.y);
	camera_eyez_coordinates = std::to_string(camera->eye.z);
	camera_centerx_coordinates = std::to_string(camera->center.x);
	camera_centery_coordinates = std::to_string(camera->center.y);
	camera_centerz_coordinates = std::to_string(camera->center.z);

	glDisable(GL_LIGHTING);
	DrawString("Cube Solar System", &vector_title_string, &color_strings);
	DrawString("Eye CAM: ", &vector_eye_string, &color_strings);
	DrawString(camera_eyex_coordinates, &vector_eyex_string, &color_strings);
	DrawString(camera_eyey_coordinates, &vector_eyey_string, &color_strings);
	DrawString(camera_eyez_coordinates, &vector_eyez_string, &color_strings);
	DrawString("Center CAM: ", &vector_center_string, &color_strings);
	DrawString(camera_centerx_coordinates, &vector_centerx_string, &color_strings);
	DrawString(camera_centery_coordinates, &vector_centery_string, &color_strings);
	DrawString(camera_centerz_coordinates, &vector_centerz_string, &color_strings);
	glEnable(GL_LIGHTING);
	
	//Draw Objects
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

	//Update the objects 
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

	//Set Up Light in the screen
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, &(_lightData->direction.x)); //Position of the light

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->ambient.x));//Ambient Light initialization

	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->diffuse.x)); //Diffuse Light Initialization

	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->specular.x)); //Specular Light initialization

	

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
		sun->MoveBackwards();
	

	}

	if (key == 'f')
	{
		sun->MoveLeft();
	}
	if (key == 'g')
	{
		sun->MoveForward();

	}

	if (key == 'h')
	{
		sun->MoveRight();
	}

	if (key == 'r')
	{
		sun->MoveDown();
	}

	if (key == 'y')
	{
		sun->MoveUp();
	}
}

void SolarSystem::DrawString(std::string text, Vector3* position, Color* color)
{
	glPushMatrix();

	glTranslatef(position->x, position->y, position->z);
	glColor3f(color->r, color->g, color->b);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)text.c_str());
	

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
	float x = difference * sin(planet_rotation.y * (PI/180));
	float y = planet.y;
	float z = difference * cos(planet_rotation.y * (PI/180));

	Vector3 planet_real_position = { x, y, z };
	

	return planet_real_position;
}

void SolarSystem::DoCollision()
{
	Vector3 new_position = { -500000000, -500000000, -500000000 };

	Vector3 mercury_offset_position = GetOffsetPosition(sun->GetOrbitalPosition(), neptune->GetOrbitalPosition(), neptune->GetRotation());
	float distance = calculateDistanceSquared(sun->GetOrbitalPosition(), mercury_offset_position);
	
	std::cout << distance << std::endl;
	std::cout << neptune->GetPosition().z << std::endl;
	/*std::cout << mercury_offset_position.z << std::endl;
	std::cout << mercury_offset_position.x << std::endl;*/
	std::cout << neptune->GetRotation().y << std::endl;
	
	if (distance <= 0)
	{
		mercury->SetPosition(new_position);
	}
}