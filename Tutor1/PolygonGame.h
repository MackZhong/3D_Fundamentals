#pragma once
#include "Game.h"
#include <vector>

class PolygonGame :
	public Game
{
public:
	PolygonGame(MainWindow& wnd);

	// Í¨¹ý Game ¼Ì³Ð
	virtual void ComposeFrame() override;
	virtual void UpdateModel() override;

private:
	std::vector<Vec2> m_Star;
	float m_Theta{ 0.0f };
	static constexpr float m_Rotation = PI / 180.0f;
	static constexpr float m_RadInner = 0.5f;
	static constexpr float m_RadOuter = 2.0f;
	static constexpr int m_Flares = 15;
	static constexpr float m_Size = 100.0f;
};

