#pragma once

#include "SolarSystem.h"

class SolarSystem;

namespace GLUTCallbacks
{
	void Init(SolarSystem* gl);

	void Display();

	void Timer(int preferredRefresh);

	void Keyboard(unsigned char key, int x, int y);
};

