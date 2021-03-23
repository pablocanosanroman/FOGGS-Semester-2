#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include "structures.h"
#include "Sun.h"
#include "Mercury.h"
#include "Venus.h"
#include "Earth.h"
#include "Mars.h"
#include "Jupiter.h"
#include "Saturn.h"
#include "Uranus.h"
#include "Neptune.h"

#define REFRESHRATE 16



class SolarSystem
{

public:

	SolarSystem(int argc, char* argv[]);
	~SolarSystem();

	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void InitObjects();
	void InitLight();
	void InitGL(int argc, char* argv[]);
	void DrawString(const char* text, Vector3* position, Color* color);

private:


	Camera* camera;
	Vector4* _lightPosition;
	Lighting* _lightData;
	SceneObject* sun;
	SceneObject* mercury;
	SceneObject* venus;
	SceneObject* earth;
	SceneObject* mars;
	SceneObject* jupiter;
	SceneObject* saturn;
	SceneObject* uranus;
	SceneObject* neptune;

};


