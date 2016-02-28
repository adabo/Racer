/****************************************************************************************** 
 *	Chili DirectX Framework Version 11.12.17											  *	
 *	Keyboard.h																			  *
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
#pragma once
#include <Windows.h>
enum Key
{
	Key_Escape = VK_ESCAPE,
	Key_Left = VK_LEFT,
	Key_Up = VK_UP,
	Key_Right = VK_RIGHT,
	Key_Down = VK_DOWN,

	Key_1 = '1',
	Key_2,
	Key_3,
	Key_4,
	Key_5,
	Key_6,
	Key_7,
	Key_8,
	Key_9,
	Key_0,

	Key_A = 'A',
	Key_B,
	Key_C,
	Key_D,
	Key_E,
	Key_F,
	Key_G,
	Key_H,
	Key_I,
	Key_J,
	Key_K,
	Key_L,
	Key_M,
	Key_N,
	Key_O,
	Key_P,
	Key_Q,
	Key_R,
	Key_S,
	Key_T,
	Key_U,
	Key_V,
	Key_W,
	Key_X,
	Key_Y,
	Key_Z,


};
class KeyboardServer;

class KeyboardClient
{
public:
	KeyboardClient( const KeyboardServer& kServer );
	bool UpIsPressed() const;
	bool DownIsPressed() const;
	bool LeftIsPressed() const;
	bool RightIsPressed() const;
	bool SpaceIsPressed() const;
	bool EnterIsPressed() const;
private:
	const KeyboardServer& server;
};

class KeyboardServer
{
	friend KeyboardClient;
public:
	KeyboardServer();

	void OnUpPressed();
	void OnDownPressed();
	void OnLeftPressed();
	void OnRightPressed();
	void OnSpacePressed();
	void OnEnterPressed();

	void OnUpReleased();
	void OnDownReleased();
	void OnLeftReleased();
	void OnRightReleased();
	void OnSpaceReleased();
	void OnEnterReleased();
private:
	bool upIsPressed;
	bool downIsPressed;
	bool leftIsPressed;
	bool rightIsPressed;
	bool spaceIsPressed;
	bool enterIsPressed;
};