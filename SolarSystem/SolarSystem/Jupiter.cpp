#include "Jupiter.h"

Jupiter::Jupiter(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture, x, y, z)
{
	_rotation.x = rand() % 360;
	_rotation.y = rand() % 360;



	_rotationSpeed = 0.5f;

	_position.x = x;
	_position.y = y;
	_position.z = z;

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
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.y));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.z));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);

		glTranslatef(_position.x, _position.y, _position.z);

		glRotatef(_rotation.y, 0.0f, 1.0f, 0.0f);

		glTranslatef(0.0f, 0.0f, -45.0f);

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
	_material->ambient.x = 0.329412; _material->ambient.y = 0.223529; _material->ambient.z = 0.027451;
	_material->ambient.w = 0.0;
	_material->diffuse.x = 0.780392; _material->diffuse.y = 0.568627; _material->diffuse.z = 0.113725;
	_material->diffuse.w = 0.0;
	_material->specular.x = 0.992157; _material->specular.y = 0.941176; _material->specular.z = 0.807843;
	_material->specular.w = 0.0;
	_material->shininess = 100.0f;
}