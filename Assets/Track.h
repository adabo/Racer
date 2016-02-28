#pragma once
#include "Common.h"
#include "D3DGraphics.h"

class Track
{
public:
	TrackSide GetTrackSide(float X, float Y);
	void Draw(D3DGraphics &gfx);
};
