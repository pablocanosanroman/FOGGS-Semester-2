#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"


class Earth : public SceneObject
{
private:

	
	
	GLfloat _rotationSpeed;
	Material* _material;

public:

	Earth(Mesh* mesh, Texture2D* texture, float x, float y, float z);
	~Earth();

	void Draw();
	void Update();
	void Materials();
	
};
