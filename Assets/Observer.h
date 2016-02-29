#pragma once
#include "Car.h"
#include "Track.h"

class Observer
{
public:
	Observer();
    void Observer::UpdateKeyboardInput(KeyboardClient &kbd, float dt);
	void Update(KeyboardClient &Kbd, const float dt);
	void Draw(D3DGraphics &gfx);

private:
	Car car;
	Track track;
};
