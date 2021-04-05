#include "Neptune.h"


Neptune::Neptune(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture, x, y, z)
{

	_rotation.y = rand() % 360;

	_rotationSpeed = 0.2f;

	_orbitalposition.x = x;
	_orbitalposition.y = y;
	_orbitalposition.z = z;

	_position.x = 0.0f; 
	_position.y = 0.0f;
	_position.z = -75.0;

}

Neptune::~Neptune()
{
	delete _mesh->Vertices;

	_mesh->Vertices = nullptr;

	delete _mesh->Normals;

	_mesh->Normals = nullptr;

	delete _mesh->Indices;

	_mesh->Indices = nullptr;

	delete _material;
}

void Neptune::Draw()
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

		Materials();

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));

		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);

		glPushMatrix();

		glTranslatef(_orbitalposition.x, _orbitalposition.y, _orbitalposition.z);

		glRotatef(_rotation.y, 0.0f, 1.0f, 0.0f);

		glTranslatef(_position.x, _position.y, _position.z);

		glRotatef(_rotation.y, 0.0f, 1.0f, 0.0f);

		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Neptune::Update()
{
	_rotation.y += _rotationSpeed;
}

void Neptune::Materials()
{
	_material = new Material();
	_material->ambient.x = 0.0; _material->ambient.y = 0.0; _material->ambient.z = 1.0;
	_material->ambient.w = 0.0;
	_material->diffuse.x = 0.0; _material->diffuse.y = 0.0; _material->diffuse.z = -1.5;
	_material->diffuse.w = 0.0;
	_material->specular.x = 0.0; _material->specular.y = 0.0; _material->specular.z = 1.5;
	_material->specular.w = 0.0;
	_material->shininess = 100.0f;
}

