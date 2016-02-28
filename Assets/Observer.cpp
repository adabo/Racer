#include "Observer.h"

Observer::Observer()
{
}

void Observer::Update(KeyboardClient &Kbd, const float dt)
{
	float carX, carY;
	car.GetPosition(carX, carY);
	TrackSide ts = track.GetTrackSide(carX, carY);
	SetCarDirection(ts);

	car.Update(Kbd, dt);
}

void Observer::Draw(D3DGraphics & gfx)
{
	track.Draw(gfx);
	car.Draw(gfx);
}

void Observer::SetCarDirection(TrackSide Ts)
{
	float carX, carY;
	car.GetPosition(carX, carY);
	Direction carDir = car.GetDirection();
	
	switch (Ts)
	{
	case NORTHEAST:
		if (carDir == RIGHT)
		{
			car.SetDirection(DOWN);
		}
		else if (carDir == UP)
		{
			car.SetDirection(LEFT);
		}
		break;
	case SOUTHEAST:
		if (carDir == DOWN)
		{
			car.SetDirection(LEFT);
		}
		else if (carDir == RIGHT)
		{
			car.SetDirection(UP);
		}
		break;
	case SOUTHWEST:
		if (carDir == LEFT)
		{
			car.SetDirection(UP);
		}
		else if (carDir == DOWN)
		{
			car.SetDirection(RIGHT);
		}
		break;
	case NORTHWEST:
		if (carDir == UP)
		{
			car.SetDirection(RIGHT);
		}
		else if (carDir == LEFT)
		{
			car.SetDirection(DOWN);
		}
		break;
	}
}
