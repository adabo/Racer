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

void Car::Update(const float dt)
{
    UpdatePosition(dt);
    // Set position first then clamp
    // Clamping before SetTrackSide causes
    // a bug where if the car is one pixel past
    // the x or y boundary, then SetTrackSide()
    // never sets the corner which means the car
    // /may/ turn the corner, sometimes not.
    ClampToTrack();
    SetTrackSide();
    AutoTurnCorner();
}

void Car::SetSpeed(float accel)
{
    speed = accel;
}

float Car::GetSpeed()
{
    return speed;
}

void Car::SetTrackSide()
{
    int cellX = static_cast<int>(x);
    int cellY = static_cast<int>(y);

    /* ATTN: Josh*/
    /* From: Abel*/
    /* What does cell mean? */
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
}

void Car::SetAccel(float ac)
{
    accel = ac;
}

float Car::GetAccel()
{
    return accel;
}

void Car::UpdatePosition(float dt)
{
    float step = accel * dt;
    if (direction == UP &&
       (trackside == WEST || trackside == EAST ||
        trackside == NORTHWEST || trackside == SOUTHWEST ||
        trackside == NORTHEAST || trackside == SOUTHEAST))
    {
        curSurface = &carUp;
        y -= step;
    }
    else if (direction == DOWN &&
            (trackside == WEST || trackside == EAST ||
             trackside == NORTHWEST || trackside == SOUTHWEST ||
             trackside == NORTHEAST || trackside == SOUTHEAST))
    {
        curSurface = &carDown;
        y += step;
    }
    else if (direction == LEFT &&
            (trackside == NORTH || trackside == SOUTH ||
             trackside == NORTHWEST || trackside == SOUTHWEST ||
             trackside == NORTHEAST || trackside == SOUTHEAST))
    {
        curSurface = &carLeft;
        x -= step;
    }
    else if (direction == RIGHT &&
            (trackside == NORTH || trackside == SOUTH ||
             trackside == NORTHWEST || trackside == SOUTHWEST ||
             trackside == NORTHEAST || trackside == SOUTHEAST))
    {
        curSurface = &carRight;
        x += step;
    }
}

void Car::AutoTurnCorner()
{
    // Makes the car auto turn corners
    switch (trackside)
    {
    case NORTHEAST:
        if (direction == RIGHT)
        {
            direction = DOWN;
        }
        else if (direction == UP)
        {
            direction = LEFT;
        }
        break;
    case SOUTHEAST:
        if (direction == DOWN)
        {
            direction = LEFT;
        }
        else if (direction == RIGHT)
        {
            direction = UP;
        }
        break;
    case SOUTHWEST:
        if (direction == LEFT)
        {
            direction = UP;
        }
        else if (direction == DOWN)
        {
            direction = RIGHT;
        }
        break;
    case NORTHWEST:
        if (direction == UP)
        {
            direction = RIGHT;
        }
        else if (direction == LEFT)
        {
            direction = DOWN;
        }
        break;
    }
}

Direction Car::GetDirection() const
{
    return direction;
}

void Car::SetDirection( Direction dir)
{
    direction = dir;
}

void Car::GetPosition(float &X, float &Y)
{
    X = x;
    Y = y;
}

void Car::Draw(D3DGraphics &gfx)
{
    curSurface->Draw(static_cast<int>(x), static_cast<int>(y), gfx);
}
