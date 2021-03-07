#include "FlyingObjects.h"
#include <fstream>
#include <iostream>

//Cube.cpp

FlyingObjects::FlyingObjects(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	

	for (int i = 0; i < 100; i++)
	{
		_rotation.x = rand() % 360;
		_rotation.y = rand() % 360;
		_rotation.z = rand() % 360;
		
	}

	_rotationSpeed = rand() % 1 + 2;

	_position.x = x;
	_position.y = y;
	_position.z = z;
	
	

}

FlyingObjects::~FlyingObjects()
{
	delete _mesh->Vertices;

	_mesh->Vertices = nullptr;

	delete _mesh->Normals;

	_mesh->Normals = nullptr;

	delete _mesh->Indices;

	_mesh->Indices = nullptr;

	delete _material;

}

void FlyingObjects::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());

		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnable(GL_NORMAL_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		Light(); //calls the material light for the object

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialfv(GL_FRONT, GL_SHININESS, &(_material->shininess));

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

void FlyingObjects::Light()
{
	_material = new Material();
	_material->ambient.x = 0.8; _material->ambient.y = 0.05; _material->ambient.z = 0.05;
	_material->ambient.w = 1.0;
	_material->diffuse.x = 0.8; _material->diffuse.y = 0.05; _material->diffuse.z = 0.05;
	_material->diffuse.w = 1.0;
	_material->specular.x = 1.0; _material->specular.y = 1.0; _material->specular.z = 1.0;
	_material->specular.w = 1.0;
	_material->shininess = 100.0f;
}
