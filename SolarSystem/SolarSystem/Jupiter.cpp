#include "Jupiter.h"

Jupiter::Jupiter(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture, x, y, z)
{

	_rotation.y = rand() % 360;



	_rotationSpeed = 0.7f;

	_orbitalposition.x = x;
	_orbitalposition.y = y;
	_orbitalposition.z = z;

	_position.x = 0.0f;
	_position.y = 0.0f;
	_position.z = -45.0f;

}

Jupiter::~Jupiter()
{
	delete _mesh->Vertices;

	_mesh->Vertices = nullptr;

	delete _mesh->Normals;

	_mesh->Normals = nullptr;

	delete _mesh->Indices;

	_mesh->Indices = nullptr;

	delete _material;
}

void Jupiter::Draw()
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

		glPushMatrix();

		Materials();

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);

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

void Jupiter::Update()
{
	_rotation.y += _rotationSpeed;
}

void Jupiter::Materials()
{
	_material = new Material();
	_material->ambient.x = 1.0f; _material->ambient.y = 0.20; _material->ambient.z = 0.06f;
	_material->ambient.w = 0.0;
	_material->diffuse.x = -1.0; _material->diffuse.y = -0.20; _material->diffuse.z = -0.06;
	_material->diffuse.w = 0.0;
	_material->specular.x = 1.0; _material->specular.y = 0.20; _material->specular.z = 0.06;
	_material->specular.w = 0.0;
	_material->shininess = 100.0f;
}