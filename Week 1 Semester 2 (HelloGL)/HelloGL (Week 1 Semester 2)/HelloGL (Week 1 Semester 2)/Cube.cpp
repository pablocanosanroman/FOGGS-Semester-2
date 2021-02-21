#include "Cube.h"
#include <fstream>
#include <iostream>



Cube::Cube(Mesh* mesh, float x, float y, float z)
{
	for (int i = 0; i < 200; i++)
	{
		_rotation = rand() % 360;
	}

	_position.x = x;
	_position.y = y;
	_position.z = z;
	_mesh = mesh;

}

Cube::~Cube()
{
	delete _mesh->Vertices;

	_mesh->Vertices = nullptr;

	delete _mesh->Colors;

	_mesh->Colors = nullptr;

	delete _mesh->Indices;

	_mesh->Indices = nullptr;
}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);

		glRotatef(_rotation, 1.0f, 1.0f, 0.0f);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
	
}

void Cube::Update()
{
	
	_rotation += rand() % 2;

	
	
}

