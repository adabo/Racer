#pragma once
#include "Common.h"
#include "Keyboard.h"
#include "Surface.h"
#include "D3DGraphics.h"


class Car
{
public:
	Car();
	void Update(KeyboardClient &Kbd, const float dt);
	void Draw(D3DGraphics& gfx);
	void SetDirection(Direction d);

	Direction GetDirection()const;
	void GetPosition(float &X, float &Y);

	// Having private here and private over variable list isn't necessary
	// I just like doing it to keep them separate.
private:
	void ClampToTrack();
	void UpdatePosition(KeyboardClient &Kbd, float dt);
private:
	Surface *curSurface;
	Surface carUp, carRight, carDown, carLeft;
	Direction direction;
	float x, y;
	float speed;

};
