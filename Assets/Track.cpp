#include "Track.h"


TrackSide Track::GetTrackSide(float X, float Y)
{
	int cellX = static_cast<int>(X);
	int cellY = static_cast<int>(Y);

	TrackSide trackside;
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
	return trackside;
}

void Track::Draw(D3DGraphics & gfx)
{
	int x = 0, y = 0;
	// Draw north outer
	// ==================================================
	for (int row = 0; row < 20; row++)
	{
		gfx.DrawLine(x, y + row, x + 600, y + row,
			D3DCOLOR_XRGB(168, 0, 168));
	}
	// Draw north inner
	for (int row = 0; row < 40; row++)
	{
		gfx.DrawLine(x + 20, y + 20 + row, x + 580, y + 20 + row,
			D3DCOLOR_XRGB(252, 168, 252));
	}
	// Draw north inner inner
	for (int row = 0; row < 20; row++)
	{
		gfx.DrawLine(x + 60, y + 60 + row, x + 540, y + 60 + row,
			D3DCOLOR_XRGB(168, 0, 168));
	}

	// Draw south outer
	// ==================================================
	for (int row = 0; row < 20; row++)
	{
		gfx.DrawLine(x, y + 580 + row, x + 600, y + 580 + row,
			D3DCOLOR_XRGB(168, 0, 168));
	}
	// Draw south inner
	for (int row = 0; row < 40; row++)
	{
		gfx.DrawLine(x + 20, y + 540 + row, x + 580, y + 540 + row,
			D3DCOLOR_XRGB(252, 168, 252));
	}
	// Draw south inner inner
	for (int row = 0; row < 20; row++)
	{
		gfx.DrawLine(x + 60, y + 520 + row, x + 540, y + 520 + row,
			D3DCOLOR_XRGB(168, 0, 168));
	}
	// Draw east outer
	// ==================================================
	for (int col = 0; col < 20; col++)
	{
		gfx.DrawLine(x + 580 + col, y + 20, x + 580 + col, y + 580,
			D3DCOLOR_XRGB(168, 0, 168));
	}
	// Draw east inner
	for (int col = 0; col < 40; col++)
	{
		gfx.DrawLine(x + 540 + col, y + 60, x + 540 + col, y + 540,
			D3DCOLOR_XRGB(252, 168, 252));
	}
	// Draw east inner inner
	for (int col = 0; col < 20; col++)
	{
		gfx.DrawLine(x + 520 + col, y + 80, x + 520 + col, y + 520,
			D3DCOLOR_XRGB(168, 0, 168));
	}

	// Draw west outer
	// ==================================================
	for (int col = 0; col < 20; col++)
	{
		gfx.DrawLine(x + col, y + 20, x + col, y + 580,
			D3DCOLOR_XRGB(168, 0, 168));
	}
	// Draw west inner
	for (int col = 0; col < 40; col++)
	{
		gfx.DrawLine(x + 20 + col, y + 60, x + 20 + col, y + 540,
			D3DCOLOR_XRGB(252, 168, 252));
	}
	// Draw west inner inner
	for (int col = 0; col < 20; col++)
	{
		gfx.DrawLine(x + 60 + col, y + 80, x + 60 + col, y + 520,
			D3DCOLOR_XRGB(168, 0, 168));
	}
}
