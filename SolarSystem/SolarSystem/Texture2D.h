#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"

class Texture2D
{
private:
	GLuint _ID; //Texture ID
	int _width, _height;

public:
	Texture2D();
	~Texture2D();

	bool LoadRAW(const char* cstrFilePath, const int nWidth, const int nHeight);
	int LoadTGA(const char* textureFileName);

	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};
