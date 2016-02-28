#include "GPlus.h"

GdiPlusManager::GdiPlusManager()
{
	Gdiplus::GdiplusStartupInput gdiPlusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiPlusStartupInput, nullptr);
}

GdiPlusManager::~GdiPlusManager()
{
	
}
