#include "Cube.h"
#include <fstream>
#include <iostream>

Vertex* Cube::indexedVertices = nullptr;

Color* Cube::indexedColors = nullptr;

GLushort* Cube::indices = nullptr;

int Cube::numVertices = 0;

int Cube::numColors = 0;

int Cube::numIndices = 0;


Cube::Cube(float x, float y, float z)
{
	for (int i = 0; i < 200; i++)
	{
		_rotation = rand() % 360;
	}

	_position.x = x;
	_position.y = y;
	_position.z = z;

	
}

Cube::~Cube()
{
	delete indexedVertices;

	indexedVertices = nullptr;

	delete indexedColors;

	indexedColors = nullptr;

	delete indices;

	indices = nullptr;
}

void Cube::Draw()
{
	if (indexedVertices != nullptr && indexedColors != nullptr && indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
		glColorPointer(3, GL_FLOAT, 0, indexedColors);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);

		glRotatef(_rotation, 1.0f, 1.0f, 0.0f);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);

		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	
}

void Cube::Update()
{
	
	_rotation += rand() % 2;

	
	
}

bool Cube::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file" << path << std::endl;
		return false;
	}

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		inFile.read(path, i);
	}

	inFile >> numColors;
	indexedColors = new Color[numColors];
	for (int i = 0; i < numColors; i++)
	{
		inFile.read(path, i);
	}

	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++)
	{
		inFile.read(path, i);
	}

	inFile.close();

	return true;
}