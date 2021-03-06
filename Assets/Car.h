#pragma once
#include "Common.h"
#include "Surface.h"
#include "D3DGraphics.h"

class Car
{
public:
	Car();
	void Update(const float dt);
	void Draw(D3DGraphics& gfx);
	// void SetDirection(Direction d);

    void ClampToTrack();
	Direction GetDirection()const;
	void AutoTurnCorner();
	void SetDirection( Direction dir);
    void SetTrackSide();
	void GetPosition(float &X, float &Y);
    void SetSpeed(float accel);
    float GetSpeed();
    void SetAccel(float ac);
    float GetAccel();
	// Having private here and private over variable list isn't necessary
	// I just like doing it to keep them separate.
private:
	void UpdatePosition(float dt);
private:
	Surface *curSurface;
	Surface carUp, carRight, carDown, carLeft;
	Direction direction;
    TrackSide trackside;
	float x, y;
	float speed;
    float accel;
};
