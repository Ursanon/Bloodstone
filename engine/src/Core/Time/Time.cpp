#include "Core/Time/Time.hpp"

TimePoint bs::Time::Now()
{
	return std::chrono::high_resolution_clock::now();
}