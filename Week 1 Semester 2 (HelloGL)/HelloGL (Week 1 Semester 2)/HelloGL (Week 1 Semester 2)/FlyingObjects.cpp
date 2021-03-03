#include "FlyingObjects.h"
#include <fstream>
#include <iostream>

//Cube.h

FlyingObjects::FlyingObjects(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	

	for (int i = 0; i < 100; i++)
	{
		_rotation.x = rand() % 360;
		_rotation.y = rand() % 360;
		_rotation.z = rand() % 360;
		
	}

	_rotationSpeed = rand() % 2;

	_position.x = x;
	_position.y = y;
	_position.z = z;
	
	

}

FlyingObjects::~FlyingObjects()
{
	delete _mesh->Vertices;

	_mesh->Vertices = nullptr;

	delete _mesh->Colors;

	_mesh->Colors = nullptr;

	delete _mesh->Indices;

	_mesh->Indices = nullptr;
}

void FlyingObjects::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());

		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

		glRotatef(_rotation.x, 1.0f, 0.0f, 0.0f);
		glRotatef(_rotation.y, 1.0f, 1.0f, 0.0f);
		glRotatef(_rotation.z, 0.0f, 0.0f, 1.0f);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	
}

void FlyingObjects::Update()
{
	
	_rotation.x += _rotationSpeed;
	_rotation.y += _rotationSpeed;
	_rotation.z += _rotationSpeed;

}

