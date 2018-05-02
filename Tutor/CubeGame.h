#pragma once
#include "Game.h"
#include "MainWindow.h"
#include "PubeScreenTransformer.h"
#include "Cube.h"

class CubeGame : public Game
{
public:
	CubeGame(MainWindow& wnd) : Game(wnd), m_Cube(1.0f) {};

	// Í¨¹ý Game ¼Ì³Ð
	virtual void ComposeFrame() override;
	virtual void UpdateModel() override;

private:
	PubeScreenTransformer m_Transformer;
	Cube m_Cube;
	static constexpr float m_delta = PI;
	float theta_x = 0.0f, theta_y = 0.0f, theta_z = 0.0f;	//14:53
};

