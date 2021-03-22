#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"


class Neptune : public SceneObject
{
private:

	Vector3 _rotation;
	
	GLfloat _rotationSpeed;
	Material* _material;

public:

	Neptune(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Neptune();

	void Draw();
	void Update();
	void Materials();
	
	
};