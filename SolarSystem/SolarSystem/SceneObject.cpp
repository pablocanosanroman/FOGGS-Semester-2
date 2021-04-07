#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture, float x, float y, float z)
{
	//Initialize all the variables of the objects
	_mesh = mesh;
	_texture = texture;
	_initialposition.x = x;
	_initialposition.y = y;
	_initialposition.z = z;
}

SceneObject::~SceneObject()
{

}

void SceneObject::Draw()
{

}

void SceneObject::Update()
{

}

void SceneObject::SetPosition(Vector3 new_position)
{
	_initialposition = new_position;
}

//Function that gives me the position of the sun or the position of the orbital axis for the other planets
Vector3 SceneObject::GetPosition()
{
	return _initialposition;
}

//Function that sets the orbital position of the planets to a new one
void SceneObject::SetOrbitalPosition(Vector3 new_position)
{
	_orbitalposition = new_position;
}

//Function that gets the orbital position of the planets
Vector3 SceneObject::GetOrbitalPosition()
{
	return _orbitalposition;
}

//Function that gets the orbital angle of the orbit of a planet
Vector3 SceneObject::GetOrbitalRotation()
{
	return _orbitalrotation;
}

//Function to move left an object on the screen
void SceneObject::MoveLeft()
{
	_initialposition.x -= 0.7f;
}

//Function to move right an object on the screen
void SceneObject::MoveRight()
{
	_initialposition.x += 0.7f;
}

//Function to move up an object on the screen
void SceneObject::MoveUp()
{
	_initialposition.y += 0.7f;
}

//Function to move down an object on the screen
void SceneObject::MoveDown()
{
	_initialposition.y -= 0.7f;
}

//Function to move forward an object on the screen
void SceneObject::MoveForward()
{
	_initialposition.z += 0.7f;
}

//Function to move backwards an object on the screen
void SceneObject::MoveBackwards()
{
	_initialposition.z -= 0.7f;
}