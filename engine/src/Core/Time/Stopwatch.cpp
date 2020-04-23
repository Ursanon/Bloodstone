#include "Core/Time/Stopwatch.hpp"

bs::Stopwatch::Stopwatch()
	: startPoint_(Time::Now())
{
}

void bs::Stopwatch::Stop()
{
	endPoint_ = Time::Now();
}

void bs::Stopwatch::Restart()
{
	startPoint_ = Time::Now();
	endPoint_ = startPoint_;
}