#pragma once
#include "Car.h"
#include "Track.h"

class Observer
{
public:
	Observer();
	void Update(KeyboardClient &Kbd, const float dt);
	void Draw(D3DGraphics &gfx);
private:
	void SetCarDirection(TrackSide Ts);

private:
	Car car;
	Track track;
};