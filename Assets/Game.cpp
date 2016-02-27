/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	Game.cpp																			  *
 *	Copyright 2011 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

Game::Game( HWND hWnd,const KeyboardServer& kServer )
:	gfx ( hWnd ),
	kbd( kServer ),
    car( &car )
{
    car.direction = DOWN;
    car.trackside = WEST;
    car.speed = 2;
	srand( (unsigned int)time( NULL ) );
}

void Game::Go()
{

	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::ComposeFrame()
{
    if     ( kbd.UpIsPressed() )
    {
        car.SetCarDirection( &car,UP );
    }
    else if( kbd.DownIsPressed() )
    {
        car.SetCarDirection( &car,DOWN );
    }
    else if( kbd.LeftIsPressed() )
    {
        car.SetCarDirection( &car,LEFT );
    }
    else if( kbd.RightIsPressed() )
    {
        car.SetCarDirection( &car,RIGHT );
    }

    car.SetTrackSide( &car );

    car.UpdatePosition( &car );

    car.DrawCar( car.x,car.y,car.direction,&gfx );
}