#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> // OpenGL Utilities
#include "GL\freeglut.h" //freeglut library

struct Vector3
{
	float x;

	float y;

	float z;
};

struct Vector4
{
	float x;

	float y;

	float z;

	float w; //Homogeneous Coordinates
};

struct Lighting
{
	

	Vector4 ambient;

	Vector4 diffuse;

	Vector4 specular;

	float constant;
	float linear;
	float quadratic;

	
};

struct Material
{
	Vector4 ambient;

	Vector4 diffuse;

	Vector4 specular;

	GLfloat shininess;
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
	Vector3* Normals;
	GLushort* Indices;
	TexCoord* TexCoords;
	int VertexCount, NormalCount, IndexCount, TexCoordsCount;
};