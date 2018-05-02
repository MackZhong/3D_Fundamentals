#include "FrameTimer.h"
#include <chrono>
using namespace std::chrono;

CLASS_DECLSPEC FrameTimer::FrameTimer()
{
	last = steady_clock::now();
}

CLASS_DECLSPEC float FrameTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}
