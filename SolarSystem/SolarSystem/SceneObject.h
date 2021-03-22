#pragma once
#include "structures.h"
#include "Texture2D.h"

class SceneObject
{
protected:
	Mesh* _mesh;
	Texture2D* _texture;
	Vector3 _position;
	

public:
	SceneObject(Mesh* mesh, Texture2D* texture, float x, float y, float z );
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();
	virtual void SetPosition(Vector3 new_position);
	Vector3 GetPosition();
	
	
	
};

