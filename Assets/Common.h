#pragma once


enum TrackSide
{
	NORTH		= 1,				// 00000001
	EAST		= 1 << 1,			// 00000010
	SOUTH		= 1 << 2,			// 00000100
	WEST		= 1 << 3,			// 00001000
	NORTHEAST	= 1 << 4,			// 00010000
	SOUTHEAST	= 1 << 5,			// 00100000
	NORTHWEST	= 1 << 6,			// 01000000
	SOUTHWEST	= 1 << 7			// 10000000
};

enum Direction
{
	UP, DOWN, LEFT, RIGHT
};

