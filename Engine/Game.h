/******************************************************************************************
*	Chili DirectX Framework Version 16.10.01											  *
*	Game.h																				  *
*	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
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
#include "ChiliWin.h"

#include "Graphics.h"
#include <memory>
#include <vector>
#include "Scene.h"
#include "FrameTimer.h"
#include "Graphics.h"
#include "MainWindow.h"

class CLASS_DECLSPEC Game
{
public:
	Game( MainWindow& wnd ) : wnd(wnd), gfx(wnd) {	};
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go() {
		gfx.BeginFrame();
		UpdateModel();
		ComposeFrame();
		gfx.EndFrame();
	};
	Graphics& Graph() { return gfx; }
	MainWindow& Window() { return wnd; }

private:
	virtual void ComposeFrame() = 0;
	virtual void UpdateModel() = 0;
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
};