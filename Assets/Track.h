#pragma once
#include "D3DGraphics.h"

class Track
{
public:
    Track();
    void DrawTrack( int x,int y,D3DGraphics* gfx );
public:
    int x,y;
};