#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture, float x, float y, float z)
{
	_mesh = mesh;
	_texture = texture;
	_orbitalposition.x = x;
	_orbitalposition.y = y;
	_orbitalposition.z = z;
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

void SceneObject::SetOrbitalPosition(Vector3 new_orbital_position)
{
	_orbitalposition = new_orbital_position;
}

Vector3 SceneObject::GetOrbitalPosition()
{
	return _orbitalposition;
}

void SceneObject::SetPosition(Vector3 new_position)
{
	_position = new_position;
}

Vector3 SceneObject::GetPosition()
{
	return _position;
}

void SceneObject::SetRotation(Vector3 new_rotation)
{
	_rotation = new_rotation;
}

Vector3 SceneObject::GetRotation()
{
	return _rotation;
}

void SceneObject::MoveLeft()
{
	_orbitalposition.x -= 0.3f;
}

void SceneObject::MoveRight()
{
	_orbitalposition.x += 0.3f;
}

void SceneObject::MoveUp()
{
	_orbitalposition.y += 0.3f;
}

void SceneObject::MoveDown()
{
	_orbitalposition.y -= 0.3f;
}

void SceneObject::MoveForward()
{
	_orbitalposition.z -= 0.3f;
}

void SceneObject::MoveBackwards()
{
	_orbitalposition.z += 0.3f;
}