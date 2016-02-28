#include "Car.h"

Car::Car()
	:
	x(20),
	y(20),
	direction(DOWN),
	speed(200.0f)
{
}

void Car::Update(KeyboardClient &Kbd, const float dt)
{
	UpdatePosition(Kbd, dt);
	ClampToTrack();
}

void Car::UpdatePosition(KeyboardClient &Kbd, float dt)
{
	float accel = 0.0f;
	if (Kbd.SpaceIsPressed())
	{
		accel = speed;
	}

	float step = accel * dt;
	if (direction == UP)
	{
		y -= step;
	}
	else if (direction == DOWN)
	{
		y += step;
	}
	else if (direction == LEFT)
	{
		x -= step;
	}
	else if (direction == RIGHT)
	{
		x += step;
	}
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

void Car::SetDirection(Direction d)
{
	direction = d;
}

Direction Car::GetDirection() const
{
	return direction;
}

void Car::GetPosition(float & X, float & Y)
{
	X = x;
	Y = y;
}
