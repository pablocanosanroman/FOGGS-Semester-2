#include "SolarSystem.h"
#include <ctime>
#include <iostream>


//Constructor and destructor
SolarSystem::SolarSystem(int argc, char* argv[])
{
	//Initialize everything in the game
	srand(time(NULL));

	InitGL(argc, argv);

	InitObjects();

	InitLight();

	glutMainLoop(); //Loop of the game
}

SolarSystem::~SolarSystem()
{
	//Destructor

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

	//Set up the planet count
	planet_count = 0;

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

	//Set up texture for the sun
	Texture2D* sunTexture = new Texture2D();
	sunTexture->LoadTGA("Textures/sun.tga");

	

	//set up cubes
	sun = new Sun(cubeMesh, sunTexture, 0.0f, 0.0f, 0.0f);
	mercury = new Mercury(mercuryCubeMesh, planetTexture, 0.0f, 0.0f, 0.f);
	venus = new Venus(venusCubeMesh, planetTexture, 0.0f, 0.0f, 0.0f);
	earth = new Earth(earthCubeMesh, planetTexture, 0.0f, 0.0f, 0.0f);
	mars = new Mars(marsCubeMesh, planetTexture, 0.0f, 0.0f, 0.0f);
	jupiter = new Jupiter(jupiterCubeMesh, planetTexture, 0.0f, 0.0f, 0.0f);
	saturn = new Saturn(saturnCubeMesh, planetTexture, 0.0f, 0.0f, 0.0f);
	uranus = new Uranus(uranusCubeMesh, planetTexture, 0.0f, 0.0f, 0.0f);
	neptune = new Neptune(neptuneCubeMesh, planetTexture, 0.0f, 0.0f, 0.0f);

	//Set up camera position
	camera->eye.x = 0.0f; camera->eye.y = 150.0f; camera->eye.z = 170.0f;
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

	glEnable(GL_CULL_FACE); //Enable cull facing

	glEnable(GL_LIGHTING); //Enable Lighting

	glEnable(GL_LIGHT0); //Enable Lighting

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

	//Vectors for the text
	Vector3 title_string = { -60.0f, 80.0f, -2.0f };
	Vector3 eye_string = { -60.0f, 75.0f, -2.0f };
	Vector3 eyex_string = { -40.0f, 75.0f, -2.0f };
	Vector3 eyey_string = { -20.0f, 75.0f, -2.0f };
	Vector3 eyez_string = { 0.0, 75.0f, -2.0f };
	Vector3 center_string = { -62.5f, 70.0f, -2.0f };
	Vector3 centerx_string = { -40.0f, 70.0f, -2.0f };
	Vector3 centery_string = { -20.0f, 70.0f, -2.0f };
	Vector3 centerz_string = { 0.0f, 70.0f, -2.0f };
	Vector3 sun_string = { -62.5f, 65.0f, -2.0f };
	Vector3 sunx_string = { -40.0f, 65.0f, -2.0f };
	Vector3 suny_string = { -20.0f, 65.0f, -2.0f };
	Vector3 sunz_string = { 0.0f, 65.0f, -2.0f };
	Vector3 planet_count_title = { 20.0, 80.0f, -2.0f };
	Vector3 planet_count_string = { 50.0f, 80.0f, -2.0f };
	Vector3 restart_game_string = { -30.0f, 0.0f, -2.0f };
	Color color_strings = { 255.0f, 255.0f, 255.0f };

	//Change the camera eye and center to strings to use the text function
	camera_eyex_coordinates = std::to_string(camera->eye.x);
	camera_eyey_coordinates = std::to_string(camera->eye.y);
	camera_eyez_coordinates = std::to_string(camera->eye.z);
	camera_centerx_coordinates = std::to_string(camera->center.x);
	camera_centery_coordinates = std::to_string(camera->center.y);
	camera_centerz_coordinates = std::to_string(camera->center.z);
	sunx_coordinates = std::to_string(sun->GetPosition().x);
	suny_coordinates = std::to_string(sun->GetPosition().y);
	sunz_coordinates = std::to_string(sun->GetPosition().z);
	planet_count_text = std::to_string(planet_count);

	//Draws all the text in the screen
	glDisable(GL_LIGHTING);
	DrawString("Cube Solar System", &title_string, &color_strings);
	DrawString("Eye CAM: ", &eye_string, &color_strings);
	DrawString(camera_eyex_coordinates, &eyex_string, &color_strings);
	DrawString(camera_eyey_coordinates, &eyey_string, &color_strings);
	DrawString(camera_eyez_coordinates, &eyez_string, &color_strings);
	DrawString("Center CAM: ", &center_string, &color_strings);
	DrawString(camera_centerx_coordinates, &centerx_string, &color_strings);
	DrawString(camera_centery_coordinates, &centery_string, &color_strings);
	DrawString(camera_centerz_coordinates, &centerz_string, &color_strings);
	DrawString("Destroyed Planets: ", &planet_count_title, &color_strings);
	DrawString(planet_count_text, &planet_count_string, &color_strings);
	DrawString("Sun: ", &sun_string, &color_strings);
	DrawString(sunx_coordinates, &sunx_string, &color_strings);
	DrawString(suny_coordinates, &suny_string, &color_strings);
	DrawString(sunz_coordinates, &sunz_string, &color_strings);
	if (planet_count == 8)
	{
		DrawString("Press spacebar to set all the planets to the initial position", &restart_game_string, &color_strings);
	}
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

//Function with all the keyboard interaction- WASD ->Move the camera eye. QE ->Zoom the camera eye. RTYFGH ->Move the sun. IJKL-> Move the camera center
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
		

	
	}

	if (key == 'q')
	{
		camera->eye.z += -0.5f;
		
		
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

	if (planet_count == 8)
	{
		if (key == ' ')
		{
			sun->SetPosition({ 0,0,0 });
			mercury->SetOrbitalPosition({ 0,0,-10.0 });
			venus->SetOrbitalPosition({ 0,0,-15.0 });
			earth->SetOrbitalPosition({ 0,0,-25.0 });
			mars->SetOrbitalPosition({ 0,0,-35.0 });
			jupiter->SetOrbitalPosition({ 0,0,-45.0 });
			saturn->SetOrbitalPosition({ 0,0,-55.0 });
			uranus->SetOrbitalPosition({ 0,0, -65.0 });
			neptune->SetOrbitalPosition({ 0,0, -75.0 });

			planet_count = 0;
		}
	}
}

//Function to create text in the screen
void SolarSystem::DrawString(std::string text, Vector3* position, Color* color)
{
	glPushMatrix();

	//It sets the text in a specific position and gives it a color
	glTranslatef(position->x, position->y, position->z);
	glColor3f(color->r, color->g, color->b);
	glRasterPos2f(0.0f, 0.0f);

	//It sets the font of the text and write the text
	glutBitmapString(GLUT_BITMAP_HELVETICA_12, (unsigned char*)text.c_str());
	

	glPopMatrix();
}

//Calculate the distance of the planet and the sun calculating the module in space of both objects.
float SolarSystem::calculateDistance(Vector3 object1, Vector3 object2)
{
	float distance = sqrt(((object1.x - object2.x) * (object1.x - object2.x))
		+ ((object1.y - object2.y) * (object1.y - object2.y))
		+ ((object1.z - object2.z) * (object1.z  - object2.z)));

	return distance;
}

//Function to get the position of the planets in their orbits
Vector3 SolarSystem::GetOffsetPosition(Vector3 planet, Vector3 orbit_rotation)
{
	//Calculate the difference between planet and the center of the solar system
	float difference = abs(planet.z);

	//Calculate the x, y and z of the planet in the orbit and return it
	float x = -(difference * sin(orbit_rotation.y * (PI/180)));
	float y = planet.y;
	float z = -(difference * cos(orbit_rotation.y * (PI/180)));

	Vector3 planet_real_position = { x, y, z };
	

	return planet_real_position;
}

//Function to make the collisions. When the sun hits a planet, the planet disappear.
void SolarSystem::DoCollision()
{

	Vector3 new_position = { -500000000, -500000000, -500000000 };

	//We get the position of the planets in the orbit and the distance between the sun and the planet
	Vector3 mercury_offset_position = GetOffsetPosition(mercury->GetOrbitalPosition(), mercury->GetOrbitalRotation());
	float mercury_distance = calculateDistance(sun->GetPosition(), mercury_offset_position);

	Vector3 venus_offset_position = GetOffsetPosition(venus->GetOrbitalPosition(), venus->GetOrbitalRotation());
	float venus_distance = calculateDistance(sun->GetPosition(), venus_offset_position);

	Vector3 earth_offset_position = GetOffsetPosition(earth->GetOrbitalPosition(), earth->GetOrbitalRotation());
	float earth_distance = calculateDistance(sun->GetPosition(), earth_offset_position);

	Vector3 mars_offset_position = GetOffsetPosition(mars->GetOrbitalPosition(), mars->GetOrbitalRotation());
	float mars_distance = calculateDistance(sun->GetPosition(), mars_offset_position);

	Vector3 jupiter_offset_position = GetOffsetPosition(jupiter->GetOrbitalPosition(), jupiter->GetOrbitalRotation());
	float jupiter_distance = calculateDistance(sun->GetPosition(), jupiter_offset_position);

	Vector3 saturn_offset_position = GetOffsetPosition(saturn->GetOrbitalPosition(), saturn->GetOrbitalRotation());
	float saturn_distance = calculateDistance(sun->GetPosition(), saturn_offset_position);

	Vector3 uranus_offset_position = GetOffsetPosition(uranus->GetOrbitalPosition(), uranus->GetOrbitalRotation());
	float uranus_distance = calculateDistance(sun->GetPosition(), uranus_offset_position);

	Vector3 neptune_offset_position = GetOffsetPosition(neptune->GetOrbitalPosition(), neptune->GetOrbitalRotation());
	float neptune_distance = calculateDistance(sun->GetPosition(), neptune_offset_position);



	//If distance is more than 0 and less than 5, set the planet to the new position

	if (mercury_distance > 0 && mercury_distance < 5)
	{
		mercury->SetOrbitalPosition(new_position);
		planet_count += 1;
	}

	if (venus_distance > 0 && venus_distance < 5)
	{
		venus->SetOrbitalPosition(new_position);
		planet_count += 1;
	}

	if (earth_distance > 0 && earth_distance < 5)
	{
		earth->SetOrbitalPosition(new_position);
		planet_count += 1;
	}

	if (mars_distance > 0 && mars_distance < 5)
	{
		mars->SetOrbitalPosition(new_position);
		planet_count += 1;
	}

	if (jupiter_distance > 0 && jupiter_distance < 5)
	{
		jupiter->SetOrbitalPosition(new_position);
		planet_count += 1;
	}

	if (saturn_distance > 0 && saturn_distance < 5)
	{
		saturn->SetOrbitalPosition(new_position);
		planet_count += 1;
	}

	if (uranus_distance > 0 && uranus_distance < 5)
	{
		uranus->SetOrbitalPosition(new_position);
		planet_count += 1;
	}

	if (neptune_distance > 0 && neptune_distance < 5)
	{
		neptune->SetOrbitalPosition(new_position);
		planet_count += 1;
	}

	
}