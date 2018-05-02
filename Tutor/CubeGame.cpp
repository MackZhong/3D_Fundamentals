#include "stdafx.h"
#include "CubeGame.h"

// https://www.youtube.com/watch?v=cN97hkDrzcc

void CubeGame::ComposeFrame()
{
	auto lines = m_Cube.GetLines();
	for (auto& v : lines.getVertices()) {
		m_Transformer.TransformVec3(v);
	}
	for (auto i = lines.getIndices().cbegin(), end = lines.getIndices().cend();
		i != end; std::advance(i, 2)) {
		this->Graph().DrawLine(lines.getVertices()[*i], lines.getVertices()[*std::next(i)], Colors::White);
	}
}

void CubeGame::UpdateModel()
{
}
