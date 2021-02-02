#pragma once
#include <Windows.h> //Required for OpenDL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#define REFRESHRATE 16

struct Vector3
{
	float x;

	float y;

	float z;
};

struct Camera
{
	Vector3 eye;

	Vector3 center;

	Vector3 up;

};



class HelloGL
{
public:

	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();
	void DrawSquare();
	void DrawRectangle();
	void DrawTriangle();
	void DrawCube();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	

private:

	float rotationSquare;
	float rotationRectangle;
	float rotationTriangle;
	float rotationCube;

	Camera* camera;

};

