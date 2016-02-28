#pragma once
#include "D3DGraphics.h"
#include <string>
#include <memory>
#include "GPlus.h"


class Surface
{
	// Only the load function uses this version of the constructor.
	Surface(int Width, int Height, std::unique_ptr<D3DCOLOR[]>& rhs);
public:
	Surface(const std::wstring &Filename);
	Surface(Surface &&Rhs);
	Surface Load(int X, int Y, int Width, int Height);
	virtual void Draw(int X, int Y, D3DGraphics &gfx);
	D3DCOLOR *GetSurface()const
	{
		return surface.get();
	}
	UINT GetWidth() const
	{
		return width;
	}
	UINT GetHeight() const
	{
		return height;
	}
	RECT GetRect() const
	{
		RECT rc;
		rc.left = 0;
		rc.right = width;
		rc.top = 0;
		rc.bottom = height;

		return rc;
	}
	RECT GetClipRect(const int X, const int Y) const
	{
		RECT rc;
		rc.left = max(-X, 0);
		rc.right = min(D3DGraphics::scrWidth - X, width);
		rc.top = max(-Y, 0);
		rc.bottom = min(D3DGraphics::scrHeight - Y, height);

		return rc;
	}
	~Surface();

protected:
	int width, height;
	std::unique_ptr<D3DCOLOR[]> surface;
	GdiPlusManager gMan;
};