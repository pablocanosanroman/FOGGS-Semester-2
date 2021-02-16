#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#define REFRESHRATE 16


class HelloGL
{
public:

	//constructor definition
	HelloGL(int argc, char* argv[]);

	//destructor
	~HelloGL(void);

	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	void InitObjects();
	void InitGL(int argc, char* argv[]);
	

private:


	Camera* camera;
	Cube* cube[200];

};

