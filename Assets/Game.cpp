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
    x( 0 ),
    y( 0 )
{
	srand( (unsigned int)time( NULL ) );
}

void Game::Go()
{
	observer.Update(kbd);

	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void DrawCar( int position_x,int position_y )
{
    int width = 40;
    for (int height = 0; height < width; ++height)
       {
            gfx.DrawLine( position_x + height, position_x + height + width,
                    position_y + height,position_y + height + width
                    D3DCOLOR( 255.255,100 ) );
       }   
}

void Game::ComposeFrame()
{	
	// observer.Draw(gfx);
    DrawCar( 0,0 );
}