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

void Observer::UpdateKeyboardInput(KeyboardClient &Kbd, float dt)
{
	car.SetAccel(0.0f);
	if (Kbd.SpaceIsPressed())
	{
		car.SetAccel(car.GetSpeed());
	}

	if      (Kbd.UpIsPressed())
	{
		  car.SetDirection(UP);
	}
	else if (Kbd.DownIsPressed())
	{
		  car.SetDirection(DOWN);
	}
	else if (Kbd.LeftIsPressed())
	{
		  car.SetDirection(LEFT);
	}
	else if (Kbd.RightIsPressed())
	{
		  car.SetDirection(RIGHT);
	}
}

void Observer::Draw(D3DGraphics &gfx)
{
	track.Draw(gfx);
	car.Draw(gfx);
}
