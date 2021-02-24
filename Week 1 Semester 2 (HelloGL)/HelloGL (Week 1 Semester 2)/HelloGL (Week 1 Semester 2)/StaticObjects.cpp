#include "StaticObjects.h"
#include <fstream>
#include <iostream>

//pyramid.h

StaticObjects::StaticObjects(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{

	_position.x = x;
	_position.y = y;
	_position.z = z;
	
}

StaticObjects::~StaticObjects()
{
	delete _mesh->Vertices;

	_mesh->Vertices = nullptr;

	delete _mesh->Colors;

	_mesh->Colors = nullptr;

	delete _mesh->Indices;

	_mesh->Indices = nullptr;
}

void StaticObjects::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Colors != nullptr && _mesh->Indices != nullptr)
	{
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);

		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void StaticObjects::Update()
{

}