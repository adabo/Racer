#include "Surface.h"


Surface::Surface(const std::wstring &Filename)
{
	Gdiplus::Bitmap bitmap(Filename.c_str());
	Gdiplus::Color pixel;

	int uaWidth = (int)bitmap.GetWidth();
	height = (int)bitmap.GetHeight();
	width = uaWidth + ((4 - (uaWidth % 4)) % 4);

	surface.reset(new D3DCOLOR[width * height]);

	for (UINT y = 0; y < (UINT)height; y++)
	{
		const UINT rowOffset = y * (UINT)width;
		for (UINT x = 0; x < (UINT)width; x++)
		{
			const UINT index = x + rowOffset;
			bitmap.GetPixel(x, y, &pixel);
			surface[index] = pixel.GetValue();
		}
	}
}

Surface::Surface(int Width, int Height, std::unique_ptr<D3DCOLOR[]>& rhs)
	:
	width(Width),
	height(Height)	
{
	surface = std::move(rhs);
}

Surface::Surface(Surface && Rhs)
	:
	width(Rhs.width),
	height(Rhs.height),
	gMan(Rhs.gMan),
	surface(std::move(Rhs.surface))
{

}

Surface Surface::Load(int X, int Y, int Width, int Height)
{
	std::unique_ptr<D3DCOLOR[]> pSurf(new D3DCOLOR[Width * Height]);

	for (int y = 0; y < Height; ++y)
	{
		const int pSurfRow = y * Width;
		const int yPos = y + Y;
		const int surfRow = yPos * width;

		for (int x = 0; x < Width; ++x)
		{
			const int pSurfIndex = x + pSurfRow;
			const int xPos = x + X;
			const int surfIndex = xPos + surfRow;
			pSurf[pSurfIndex] = surface[surfIndex];
		}
	}

	return Surface(Width, Height, pSurf);
}

void Surface::Draw(int X, int Y, D3DGraphics &gfx)
{
	int xStart = max(-X, 0);
	int xEnd = min(D3DGraphics::scrWidth - X, width);
	int yStart = max(-Y, 0);
	int yEnd = min(D3DGraphics::scrHeight - Y, height);

	for (int y = yStart; y < yEnd; ++y)
	{
		for (int x = xStart; x < xEnd; ++x)
		{
			gfx.PutPixel(x + X, y + Y, surface[x + (y * width)]);
		}
	}
}

Surface::~Surface()
{
	
}