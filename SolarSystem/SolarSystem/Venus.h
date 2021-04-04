#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "structures.h"
#include "SceneObject.h"

class Venus : public SceneObject
{
private:

	
	
	GLfloat _rotationSpeed;
	Material* _material;

public:

	Venus(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Venus();

	void Draw();
	void Update();
	void Materials();
};

