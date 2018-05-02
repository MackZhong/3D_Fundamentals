#include "stdafx.h"
#include "PolygonGame.h"
#include "Mat2.h"


PolygonGame::PolygonGame(MainWindow& wnd)
	: Game(wnd)
{
	const float theta = 2.0f * PI / float(m_Flares * 2);
	for (int i = 0; i < m_Flares * 2; i++) {
		const float rad = (i % 2 == 0) ? m_RadOuter : m_RadInner;
		m_Star.emplace_back(
			rad * cos(float(i) * theta),
			rad * sin(float(i) * theta));
	}
}

void PolygonGame::ComposeFrame()
{
	Graphics& gfx = this->Graph();
	const Vec2 trl = { float(gfx.ScreenWidth) / 2.0f, float(gfx.ScreenHeight) / 2.0f };
	const Mat2 trf = Mat2::Rotation(m_Theta) * Mat2::Scaling(m_Size);
	auto vtx(m_Star);
	for (auto& v : vtx) {
		v *= trf;
		v += trl;
	}
	for (auto v = vtx.begin(), end = std::prev(vtx.end()); v != end; v++) {
		gfx.DrawLine(*v, *std::next(v), Colors::Yellow);
	}
	gfx.DrawLine(vtx.front(), vtx.back(), Colors::Blue);
}

void PolygonGame::UpdateModel()
{
	MainWindow& wnd = this->Window();
	if (!wnd.kbd.KeyIsPressed(VK_SPACE)) {
		m_Theta += m_Rotation;
	}
}
