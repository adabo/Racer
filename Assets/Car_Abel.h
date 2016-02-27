#define SCREENWIDTH 600
#define SCREENWIDTH 800

enum TrackSide
{
    NORTH,SOUTH,EAST,WEST
}

enum Direction
{
    UP,DOWN,LEFT,RIGHT 
};

class Car
{
public:
    void UpdatePosition();

    void SetTrackSide();

    void SetCarDirection( Direction d);

public:
    TrackSide trackside;
    Direction direction;
    float x,y;
    float speed;
};
