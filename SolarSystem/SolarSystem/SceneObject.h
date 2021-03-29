#pragma once
#include "structures.h"
#include "Texture2D.h"

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;
	Vector3 _orbitalposition;
	Vector3 _rotation;
	Vector3 _position;

public:
	SceneObject(Mesh* mesh, Texture2D* texture, float x, float y, float z );
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
	virtual void SetOrbitalPosition(Vector3 new_orbital_position);
	Vector3 GetOrbitalPosition();
	virtual void SetPosition(Vector3 new_position);
	Vector3 GetPosition();
	virtual void SetRotation(Vector3 new_rotation);
	Vector3 GetRotation();
	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveForward();
	virtual void MoveBackwards();
	
};

