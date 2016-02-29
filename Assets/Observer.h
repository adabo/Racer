#pragma once
#include "Car.h"
#include "Track.h"
#include "Keyboard.h"

class Observer
{
public:
	Observer();
    void UpdateKeyboardInput(KeyboardClient &Kbd, float dt);
	void Update(KeyboardClient &Kbd, const float dt);
	void Draw(D3DGraphics &gfx);

private:
	Car car;
	Track track;
};
