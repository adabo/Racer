#include "Observer.h"

Observer::Observer()
{
}

void Observer::Update(KeyboardClient &Kbd, const float dt)
{
	// float carX, carY;
	// car.GetPosition(carX, carY);
	// TrackSide ts = car.GetTrackSide(carX, carY);
	// SetCarDirection(ts);
	UpdateKeyboardInput(Kbd,dt);
	car.Update(dt);
}

void Observer::UpdateKeyboardInput(KeyboardClient &kbd, float dt)
{
	if (Kbd.SpaceIsPressed())
	{
		accel = speed;
	}

	if      (Kbd.UpIsPressed())
	{
		car.direction = UP;
	}
	else if (Kbd.DownIsPressed())
	{
		car.direction = DOWN;
	}
	else if (Kbd.LeftIsPressed())
	{
		car.direction = LEFT;
	}
	else if (Kbd.RightIsPressed())
	{
		car.direction = RIGHT;
	}
}

void Observer::Draw(D3DGraphics &gfx)
{
	track.Draw(gfx);
	car.Draw(gfx);
}
