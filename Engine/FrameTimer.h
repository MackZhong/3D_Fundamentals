#pragma once
#include "ChiliWin.h"
#include <chrono>

class CLASS_DECLSPEC FrameTimer
{
public:
	FrameTimer();
	float Mark();

private:
	std::chrono::steady_clock::time_point last;
};