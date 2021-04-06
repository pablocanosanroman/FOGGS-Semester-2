#include "Sun.h"

Sun::Sun(Mesh* mesh, Texture2D* texture, float x, float y, float z): SceneObject(mesh, texture, x, y, z)
{
	//Initialize all the variables
	_planetrotation.y = rand() % 360;
	
	

	_rotationSpeed = 0.3f;

	//Position in which the planet is drawn
	_initialposition.x = x;
	_initialposition.y = y;
	_initialposition.z = z;

}

Sun::~Sun()
{
	delete _mesh->Vertices;

	_mesh->Vertices = nullptr;

	delete _mesh->Normals;

	_mesh->Normals = nullptr;

	delete _mesh->Indices;

	_mesh->Indices = nullptr;

	delete _material;
}


void Sun::Draw()
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

		//It creates a rotation axis on the planet
		glRotatef(_planetrotation.y, 0.0f, 1.0f, 0.0f);

		//It draws all the triangles to create the cube
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Sun::Update()
{
	//It sets a speed on the rotation angles
	_planetrotation.y += _rotationSpeed;
}

void Sun::Materials()
{
	//Set up the materials
	_material = new Material();
	_material->ambient.x = 3.0; _material->ambient.y = 3.0; _material->ambient.z = 0.0;
	_material->ambient.w = 0.0;
	_material->diffuse.x = 0.0; _material->diffuse.y = 0.0; _material->diffuse.z = 0.0;
	_material->diffuse.w = 0.0;
	_material->specular.x = 0.0; _material->specular.y = 0.0; _material->specular.z = 0.0;
	_material->specular.w = 0.0;
	_material->shininess = 100.0f;
}

