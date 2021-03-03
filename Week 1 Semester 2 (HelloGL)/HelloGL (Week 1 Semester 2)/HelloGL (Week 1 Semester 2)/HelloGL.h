#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "FlyingObjects.h"
#include "StaticObjects.h"
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
	void InitLight();
	void InitGL(int argc, char* argv[]);
	

private:


	Camera* camera;
	SceneObject* objects[200];
	Vector4* _lightPosition;
	Lighting* _lightData;
	

};

