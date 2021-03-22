#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"


class Mercury : public SceneObject
{
private:

	Vector3 _rotation;

	GLfloat _rotationSpeed;
	Material* _material;

public:

	Mercury(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Mercury();

	void Draw();
	void Update();
	void Materials();
};

