#pragma once
#include "D3DGraphics.h"

enum TrackSide
{
    NORTH,SOUTH,EAST,WEST
};

enum Direction
{
    UP,DOWN,LEFT,RIGHT 
};

class Car
{
public:
    Car( Car* car );
    void UpdatePosition( Car* car );
    void SetTrackSide( Car* car );
    void SetCarDirection( Car* car,Direction direction );
    void DrawCar( int x,int y,D3DGraphics* gfx);

public:
    TrackSide trackside;
    Direction direction;
    float x,y;
    float speed;
};
