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

#include <string>

#define REFRESHRATE 16
#define PI 3.14159265359


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
	void DrawString(std::string text, Vector3* position, Color* color);
	float calculateDistanceSquared(Vector3 object1, Vector3 object2);
	void DoCollision();
	Vector3 GetOffsetPosition(Vector3 sun, Vector3 planet, Vector3 planet_rotation);

private:

	std::string camera_eyex_coordinates;
	std::string camera_eyey_coordinates;
	std::string camera_eyez_coordinates;
	std::string camera_centerx_coordinates;
	std::string camera_centery_coordinates;
	std::string camera_centerz_coordinates;
	Camera* camera;
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


