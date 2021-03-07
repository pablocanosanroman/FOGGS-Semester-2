#include "GLUTCallbacks.h"
#include "SolarSystem.h"

//Namespace implementation
namespace GLUTCallbacks
{
	namespace
	{
		//Initialize to a null pointer before we do anything
		SolarSystem* solarSystem = nullptr;
	}

	void Init(SolarSystem* gl)
	{
		solarSystem = gl;
	}

	void Display()
	{
		if (solarSystem != nullptr)
		{
			solarSystem->Display();
		}
	}

	void Timer(int preferredRefresh)
	{
		preferredRefresh = 16;
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		solarSystem->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		solarSystem->Keyboard(key, x, y);
	}
}
