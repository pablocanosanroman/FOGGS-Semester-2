#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"


class Jupiter : public SceneObject
{
private:

	Vector3 _rotation;
	Vector3 _position;
	GLfloat _rotationSpeed;
	Material* _material;

public:

	Jupiter(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Jupiter();

	void Draw();
	void Update();
	void Light();
};