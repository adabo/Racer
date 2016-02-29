#include "Observer.h"

Observer::Observer()
{
}

void Observer::Update(KeyboardServer &Kbd, const float dt)
{
	// float carX, carY;
	// car.GetPosition(carX, carY);
	// TrackSide ts = car.GetTrackSide(carX, carY);
	// SetCarDirection(ts);
	UpdateKeyboardInput(Kbd,dt);
	car.Update(dt);
}

void Observer::UpdateKeyboardInput(KeyboardServer &Kbd, float dt)
{
	if (kbd.SpaceIsPressed())
	{
		accel = speed;
	}

	if      (kbd.UpIsPressed())
	{
		  car.SetDirection(UP);
	}
	else if (kbd.DownIsPressed())
	{
		  car.SetDirection(DOWN);
	}
	else if (kbd.LeftIsPressed())
	{
		  car.SetDirection(LEFT);
	}
	else if (kbd.RightIsPressed())
	{
		  car.SetDirection(RIGHT);
	}
}

void Observer::Draw(D3DGraphics &gfx)
{
	track.Draw(gfx);
	car.Draw(gfx);
}
