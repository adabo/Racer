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
		curSurface = &carUp;
		y -= step;
	}
	else if (direction == DOWN)
	{
		curSurface = &carDown;
		y += step;
	}
	else if (direction == LEFT)
	{
		curSurface = &carLeft;
		x -= step;
	}
	else if (direction == RIGHT)
	{
		curSurface = &carRight;
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

void Car::Draw(D3DGraphics &gfx)
{
	curSurface->Draw(static_cast<int>(x), static_cast<int>(y), gfx);
}
