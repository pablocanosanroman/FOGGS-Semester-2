#include "Venus.h"

Venus::Venus(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture, x, y, z)
{
	//Initialize all the variables
	_planetrotation.y = rand() % 360;
	_orbitalrotation.y = rand() % 360;


	_rotationSpeed = 2.0f;

	//Position in which the planet is drawn initially
	_initialposition.x = x;
	_initialposition.y = y;
	_initialposition.z = z;

	//Orbital position of the planet
	_orbitalposition.x = 0.0f;
	_orbitalposition.y = 0.0f;
	_orbitalposition.z = -15.0f;

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

		//Create a pointer for the vertices, normals and TexCoords of the planet
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		//Initialize the materials
		Materials();

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);

		glPushMatrix();

		//The planet is drawn in the initial position
		glTranslatef(_initialposition.x, _initialposition.y, _initialposition.z);

		//It sets a rotation in the center of the solar system
		glRotatef(_orbitalrotation.y, 0.0f, 1.0f, 0.0f);

		//Then the object moves to the orbital position keeping the rotation axis in the center
		glTranslatef(_orbitalposition.x, _orbitalposition.y, _orbitalposition.z);

		//It creates a new rotation axis on the planet
		glRotatef(_planetrotation.y, 0.0f, 1.0f, 0.0f);

		//It draws all the triangles to create the cube
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Venus::Update()
{
	//It sets a speed on the rotation angles
	_planetrotation.y += _rotationSpeed;
	_orbitalrotation.y += _rotationSpeed;
}

void Venus::Materials()
{
	//Set Up materials
	_material = new Material();
	_material->ambient.x = 0.50; _material->ambient.y = 0.50; _material->ambient.z = 0.50;
	_material->ambient.w = 0.0;
	_material->diffuse.x = -0.70; _material->diffuse.y = -0.70; _material->diffuse.z = -0.70;
	_material->diffuse.w = 0.0;
	_material->specular.x = 0.70; _material->specular.y = 0.70; _material->specular.z = 0.70;
	_material->specular.w = 0.0;
	_material->shininess = 100.0f;
}
