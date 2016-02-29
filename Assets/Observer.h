#pragma once
#include "Car.h"
#include "Track.h"

class Observer
{
public:
	Observer();
    void Observer::UpdateKeyboardInput(KeyboardServer &Kbd, float dt);
	void Update(KeyboardServer &Kbd, const float dt);
	void Draw(D3DGraphics &gfx);

private:
	Car car;
	Track track;
    KeyboardClient kbd;
};
