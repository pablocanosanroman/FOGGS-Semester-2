#pragma once
#include "structures.h"
#include "Texture2D.h"

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;
	Vector3 _initialposition;
	Vector3 _planetrotation;
	Vector3 _orbitalrotation;
	Vector3 _orbitalposition;

public:
	SceneObject(Mesh* mesh, Texture2D* texture, float x, float y, float z );
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
	Vector3 GetPosition();
	virtual void SetOrbitalPosition(Vector3 new_position);
	Vector3 GetOrbitalPosition();
	Vector3 GetOrbitalRotation();
	virtual void MoveLeft();
	virtual void MoveRight();
	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveForward();
	virtual void MoveBackwards();
	
};

