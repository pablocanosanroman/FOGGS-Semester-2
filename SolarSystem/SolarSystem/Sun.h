#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"

class Sun: public SceneObject
{
private:

	
	
	GLfloat _rotationSpeed;
	Material* _material;

public:
	Sun(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Sun();

	void Draw();
	void Update();
	void Materials();
	
};

