#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"


class Cube
{
private:
	Mesh* _mesh;

	GLfloat _rotation;
	Vector3 _position;

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

