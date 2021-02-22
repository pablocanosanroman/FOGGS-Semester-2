#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"

class StaticObjects : public SceneObject
{
private:

	GLfloat _rotation;
	Vector3 _position;

public:
	StaticObjects(Mesh* mesh, float x, float y, float z);
	~StaticObjects();

	void Draw();
	void Update();
};

