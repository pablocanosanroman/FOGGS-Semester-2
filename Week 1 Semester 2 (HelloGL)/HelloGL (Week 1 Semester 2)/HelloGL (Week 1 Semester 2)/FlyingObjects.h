#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"


class FlyingObjects : public SceneObject
{
private:

	GLfloat _rotation;
	Vector3 _position;

public:
	FlyingObjects(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~FlyingObjects();

	void Draw();
	void Update();
};

