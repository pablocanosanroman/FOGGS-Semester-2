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

	glEnable(GL_DEPTH_TEST);

	glDepthFunc(GL_ALWAYS);

	glEnable(GL_CULL_FACE);

	glCullFace(GL_BACK);
	

}

void SolarSystem::InitObjects()
{

}

void SolarSystem::InitLight()
{

}

//Display, Update and Keyboard functions

void SolarSystem::Display()
{
	
}

void SolarSystem::Update()
{

}

void SolarSystem::Keyboard(unsigned char key, int x, int y)
{

}