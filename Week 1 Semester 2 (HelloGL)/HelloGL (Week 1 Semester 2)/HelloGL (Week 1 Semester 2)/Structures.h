#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library

struct Vector3
{
	float x;

	float y;

	float z;
};

struct Camera
{
	Vector3 eye;

	Vector3 center;

	Vector3 up;

};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u, v;
};

struct Mesh
{
	Vertex* Vertices;
	Color* Colors;
	GLushort* Indices;
	TexCoord* TexCoords;
	int VertexCount, ColorCount, IndexCount, TexCoordsCount;
};