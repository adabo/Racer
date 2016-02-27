#includ "Car.h"
void UpdatePosition()
{
    if( this.direction == UP )
    {
        if( this.trackside == EAST ||
            this.trackside == WEST)
        {
            this.y -= this.speed;
        }
    }
    if( this.direction == DOWN )
    {
        if( this.trackside == EAST ||
            this.trackside == SOUTH)
        {
            this.y += this.speed;
        }
    }
    if( this.direction == LEFT )
    {
        if( this.trackside == NORTH ||
            this.trackside == SOUTH)
        {
            this.x -= this.speed;
        }
    }
    if( this.direction == RIGHT )
    {
        if( this.trackside == NORTH ||
            this.trackside == SOUTH)
        {
            this.x += this.speed;
        }
    }
}

void SetTrackSide()
{
    if( this.direction == DOWN ||
        this.direction == UP)
    {
        // Check if car is on west side
        if ( this.x == 20 &&
           ( this.y >= 20 && this.y <= 540 ) &&
        {
            this.trackside = WEST;
        }
        // Check if car is on east side
        if ( this.x == 540 &&
           ( this.y >= 20 && this.y <= 540 ) &&
        {
            this.trackside = EAST;
        }
    }
    if( this.direction == LEFT ||
        this.direction == RIGHT)
    {
        // Check if car is on south side
        if ( ( this.x == 20 && this.x <= 540 ) &&
               this.y == 540 &&
        {
            this.trackside = SOUTH;
        }
        // Check if car is on north side
        if ( ( this.x == 20 && this.x <= 540 ) &&
               this.y == 20 &&
        {
            this.trackside = NORTH;
        }
    }
}

void SetCarDirection( Direction d)
{
    switch( d )
    {
        case UP:
            this.direction = UP;
        break;
        case DOWN:
            this.direction = DOWN;
        break;
        case LEFT:
            this.direction = LEFT;
        break;
        case RIGHT:
            this.direction = RIGHT;
        break;
        default:
        break;
    }
}
