#include "Venus.h"

Venus::Venus(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture, x, y, z)
{
	_rotation.x = rand() % 360;
	_rotation.y = rand() % 360;



	_rotationSpeed = 2.0f;

	_orbitalposition.x = x;
	_orbitalposition.y = y;
	_orbitalposition.z = z;

	_position.x = 0.0f;
	_position.y = 0.0f;
	_position.z = -15.0f;

}

Venus::~Venus()
{
	delete _mesh->Vertices;

	_mesh->Vertices = nullptr;

	delete _mesh->Normals;

	_mesh->Normals = nullptr;

	delete _mesh->Indices;

	_mesh->Indices = nullptr;

	delete _material;
}

void Venus::Draw()
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
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.y));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.z));
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

void Venus::Update()
{
	_rotation.y += _rotationSpeed;
}

void Venus::Materials()
{
	_material = new Material();
	_material->ambient.x = 0.25; _material->ambient.y = 0.20725; _material->ambient.z = 0.20725;
	_material->ambient.w = 1.0;
	_material->diffuse.x = 1; _material->diffuse.y = 0.829; _material->diffuse.z = 0.829;
	_material->diffuse.w = 1.0;
	_material->specular.x = 0.296648; _material->specular.y = 0.296648; _material->specular.z = 0.296648;
	_material->specular.w = 1.0;
	_material->shininess = 100.0f;
}
