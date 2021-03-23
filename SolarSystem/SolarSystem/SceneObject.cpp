#include "SceneObject.h"

SceneObject::SceneObject(Mesh* mesh, Texture2D* texture, float x, float y, float z)
{
	_mesh = mesh;
	_texture = texture;
	_position.x = x;
	_position.y = y;
	_position.z = z;
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
	_position = new_position;
}

Vector3 SceneObject::GetPosition()
{
	return _position;
}

void SceneObject::MoveLeft()
{
	_position.x -= 0.3f;
}

void SceneObject::MoveRight()
{
	_position.x += 0.3f;
}

void SceneObject::MoveUp()
{
	_position.y += 0.3f;
}

void SceneObject::MoveDown()
{
	_position.y -= 0.3f;
}

void SceneObject::MoveForward()
{
	_position.z -= 0.3f;
}

void SceneObject::MoveBackwards()
{
	_position.z += 0.3f;
}