#include "Car.h"

Car::Car()
	:
	x(20),
	y(20),
	direction(DOWN),
	speed(200.0f),
	carUp(L"Images\\Car\\car_up.bmp"),
	carRight(L"Images\\Car\\car_right.bmp"),
	carDown(L"Images\\Car\\car_down.bmp"),
	carLeft(L"Images\\Car\\car_left.bmp")
{
	curSurface = &carDown;
}

void Car::ClampToTrack()
{
    if (x < 20)
    {
        x = 20;
    }
    else if (x >= 540)
    {
        x = 540;
    }
    if (y < 20)
    {
        y = 20;
    }
    else if (y >= 540)
    {
        y = 540;
    }
}

void Car::Update(KeyboardClient &Kbd, const float dt, Observer &obs)
{
	UpdatePosition(Kbd, dt);
	ClampToTrack();
	SetTrackSide();
}

TrackSide Car::SetTrackSide()
{
    int cellX = static_cast<int>(x);
    int cellY = static_cast<int>(x);


    /* ATTN: Josh*/
    /* From: Abel*/
    /* What does cell mean? */
    // Check if car is on west side
    if (cellX == 20)
    {
        if (cellY == 20)
        {
            trackside = NORTHWEST;
        }
        else if (cellY == 540)
        {
            trackside = SOUTHWEST;
        }
        else
        {
            trackside = WEST;
        }
    }
    // Check if car is on east side
    else if (cellX == 540)
    {
        if (cellY == 20)
        {
            trackside = NORTHEAST;
        }
        else if (cellY == 540)
        {
            trackside = SOUTHEAST;
        }
        else
        {
            trackside = EAST;
        }
    }
    // If it's not on East or West, the only places it could be is
    else
    {
        if (cellY == 20)
        {
            trackside = NORTH;
        }
        else if (cellY == 540)
        {
            trackside = SOUTH;
        }
    }
}

void Car::UpdatePosition(KeyboardClient &Kbd, float dt)
{
	float accel = 0.0f;
	float step = accel * dt;
	if (direction == UP &&
	   (trackside == WEST || trackside == EAST))
	{
		curSurface = &carUp;
		y -= step;
	}
	else if (direction == DOWN &&
		    (trackside == WEST || trackside == EAST))
	{
		curSurface = &carDown;
		y += step;
	}
	else if (direction == LEFT &&
		    (trackside == NORTH || trackside == SOUTH))
	{
		curSurface = &carLeft;
		x -= step;
	}
	else if (direction == RIGHT &&
		    (trackside == NORTH || trackside == SOUTH))
	{
		curSurface = &carRight;
		x += step;
	}
}

void Car::AutoTurnCorner(TrackSide Ts)
{
	// Makes the car auto turn corners
	switch (Ts)
	{
	case NORTHEAST:
		if (carDir == RIGHT)
		{
			direction = DOWN;
		}
		else if (carDir == UP)
		{
			direction = LEFT;
		}
		break;
	case SOUTHEAST:
		if (carDir == DOWN)
		{
			direction = LEFT;
		}
		else if (carDir == RIGHT)
		{
			direction = UP;
		}
		break;
	case SOUTHWEST:
		if (carDir == LEFT)
		{
			direction = UP;
		}
		else if (carDir == DOWN)
		{
			direction = RIGHT;
		}
		break;
	case NORTHWEST:
		if (carDir == UP)
		{
			direction = RIGHT;
		}
		else if (carDir == LEFT)
		{
			direction = DOWN;
		}
		break;
	}
}

Direction Car::GetDirection() const
{
	return direction;
}

void Car::GetPosition(float &X, float &Y)
{
	X = x;
	Y = y;
}

void Car::Draw(D3DGraphics &gfx)
{
	curSurface->Draw(static_cast<int>(x), static_cast<int>(y), gfx);
}
