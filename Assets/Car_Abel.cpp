#include "Car_Abel.h"

Car::Car( Car* car )
{
    car->x = 20,car->y = 20;
}

void Car::UpdatePosition( Car* car )
{
    if( car->direction == UP )
    {
        if( car->trackside == EAST ||
            car->trackside == WEST)
        {
            car->y -= car->speed;
        }
    }
    if( car->direction == DOWN )
    {
        if( car->trackside == EAST ||
            car->trackside == WEST)
        {
            car->y += car->speed;
        }
    }
    if( car->direction == LEFT )
    {
        if( car->trackside == NORTH ||
            car->trackside == SOUTH)
        {
            car->x -= car->speed;
        }
    }
    if( car->direction == RIGHT )
    {
        if( car->trackside == NORTH ||
            car->trackside == SOUTH)
        {
            car->x += car->speed;
        }
    }
}

void Car::SetTrackSide( Car* car )
{
    if( car->direction == DOWN ||
        car->direction == UP)
    {
        // Check if car is on west side
        if ( car->x == 20 &&
           ( car->y >= 20 && car->y <= 540 ) )
        {
            car->trackside = WEST;
        }
        // Check if car is on east side
        if ( car->x == 540 &&
           ( car->y >= 20 && car->y <= 540 ) )
        {
            car->trackside = EAST;
        }
    }
    if( car->direction == LEFT ||
        car->direction == RIGHT)
    {
        // Check if car is on south side
        if ( ( car->x == 20 && car->x <= 540 ) &&
               car->y == 540 )
        {
            car->trackside = SOUTH;
        }
        // Check if car is on north side
        if ( ( car->x == 20 && car->x <= 540 ) &&
               car->y == 20 )
        {
            car->trackside = NORTH;
        }
    }
}

void Car::SetCarDirection( Car* car,Direction direction )
{
    switch( direction )
    {
        case UP:
            car->direction = UP;
        break;
        case DOWN:
            car->direction = DOWN;
        break;
        case LEFT:
            car->direction = LEFT;
        break;
        case RIGHT:
            car->direction = RIGHT;
        break;
        default:
        break;
    }
}
