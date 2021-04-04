#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "structures.h"
#include "SceneObject.h"


class Saturn : public SceneObject
{
private:

	

	GLfloat _rotationSpeed;
	Material* _material;

public:

	Saturn(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Saturn();

	void Draw();
	void Update();
	void Materials();
};
