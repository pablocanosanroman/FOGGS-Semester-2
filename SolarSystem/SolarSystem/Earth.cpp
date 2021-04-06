#include "Earth.h"

Earth::Earth(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture, x, y, z)
{
	//Set up all the variables
	_planetrotation.y = rand() % 360;
	_orbitalrotation.y = rand() % 360;

	_rotationSpeed = 1.5f;


	_initialposition.x = x;
	_initialposition.y = y;
	_initialposition.z = z;

	//Position of the earth orbit
	_orbitalposition.x = 0.0f;
	_orbitalposition.y = 0.0f;
	_orbitalposition.z = -25.0f;
}

Earth::~Earth()
{
	delete _mesh->Vertices;

	_mesh->Vertices = nullptr;

	delete _mesh->Normals;

	_mesh->Normals = nullptr;

	delete _mesh->Indices;

	_mesh->Indices = nullptr;

	delete _material;
}

void Earth::Draw()
{
	//Draw the cube
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{

		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnable(GL_NORMAL_ARRAY);

		//Create a vertex, Normal and TexCoord pointers with the values in the text file
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		//Initialize the materials of the object
		Materials();

		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->specular.x));
		glMaterialf(GL_FRONT, GL_SHININESS, _material->shininess);

		glPushMatrix();
		//The object is drawn to the screen
		glTranslatef(_initialposition.x, _initialposition.y, _initialposition.z);

		//It puts a rotation in that point
		glRotatef(_orbitalrotation.y, 0.0f, 1.0f, 0.0f);

		//Then it moves the object to the orbital position
		glTranslatef(_orbitalposition.x, _orbitalposition.y , _orbitalposition.z);

		//And gives it a new rotation in his own axis
		glRotatef(_planetrotation.y, 0.0f, 1.0f, 0.0f);

		//Draw all the triangles to create the cube
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

void Earth::Update()
{
	//Set a rotation speed to the planet and the orbital rotation
	_planetrotation.y += _rotationSpeed;
	_orbitalrotation.y += _rotationSpeed;
}

void Earth::Materials()
{
	//Set up the material values
	_material = new Material();
	_material->ambient.x = 0.0; _material->ambient.y = 0.2; _material->ambient.z = 0.3;
	_material->ambient.w = 0.0;
	_material->diffuse.x = 0.0; _material->diffuse.y = -0.2; _material->diffuse.z = -0.3;
	_material->diffuse.w = 0.0;
	_material->specular.x = 0.0; _material->specular.y = 0.2; _material->specular.z = 0.3;
	_material->specular.w = 0.0;
	_material->shininess = 100.0f;
}