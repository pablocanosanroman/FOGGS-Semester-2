#include "GLUTCallbacks.h"


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
		//Initialize the solar system
		solarSystem = gl;
	}

	void Display()
	{
		//It calls the solar system display / draw all the objects
		if (solarSystem != nullptr)
		{
			solarSystem->Display();
		}
	}

	void Timer(int preferredRefresh)
	{
		//It set a timer and calls the update
		preferredRefresh = 16;
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		solarSystem->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		//Initialize the keyboard function in the solar system cpp
		solarSystem->Keyboard(key, x, y);
	}
}
