#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "structures.h"
#include "SceneObject.h"


class Mars : public SceneObject
{
private:

	
	
	GLfloat _rotationSpeed;
	Material* _material;

public:

	Mars(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Mars();

	void Draw();
	void Update();
	void Materials();
};

